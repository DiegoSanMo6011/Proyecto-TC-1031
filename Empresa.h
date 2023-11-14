/*
 *
 * Proyecto "Gestión de Vendedores y Ventas" calse Empresa
 *
 * Diego Gerardo Sanchez Moreno
 *
 * A01276011
 *
 * 19/09/2023
 *
 *
 * Esta clase define objeto de tipo Empresa que contiene todas las operaciones
 * para agregar nuevos empleados de cada local y permite mostrar los mejores
 * vendedores.
 *
 */

#ifndef EMPRESA_H
#define EMPRESA_H

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

// bibliotecas con los objetos a usar
#include "Empleados.h"
#include "Radios.h"
#include "Sort.h"
#include "Televisiones.h"
#include "bst.h"
#include <fstream>
#include <vector>

using namespace std;

const int MAX = 100; // valor constante para el tamano de los arreglos

// definicion de la clase
class Empresa {
  // Declaro las variables de isntancia
private:
  BST<Empleados *> empleadosTree; // Usamos un puntero a Empleados para permitir
                                  // objetos de clases derivadas
  int cont;
  bool empleadosAgregados;

  // Declaro constructor default y metodos publicos
public:
  Empresa(); // cosntructor default
  bool hayEmpleadosAgregados();
  void cargarDesdeCSV(const std::string &archivo);
  void guardarEnCSV(const std::string &archivo);
  void agrega_radios(string nombre, string local, int num_ventas);
  void agrega_teles(string nombre, string local, int num_ventas);
  void mergeSortEmpleados();
  Empleados *buscarEmpleadoPorNombre(const string &nombre);
  void modificarVentasEmpleado(const string &nombre, int nuevasVentas);
};

// constructor default
Empresa::Empresa() {
  empleadosAgregados = false;
  cont = 0;
}

/**
 * crea_ejemplos: Genera objetos en empleadosTree
 *
 * Genera objetos de tipo Radios y Televisiones y los
 * guarda en la variable de instancia empleadosTree (árbol de empleados)
 * para poder hacer pruebas. No usar esta función si se va a usar el programa
 * como una agenda, ya que los datos son falsos.
 *
 * @param
 * @return
 */
void Empresa::cargarDesdeCSV(const std::string &archivo) {
  std::ifstream file(archivo);

  if (!file.is_open()) {
    // Manejar el error de no poder abrir el archivo
    std::cerr << "Error al abrir el archivo " << archivo << std::endl;
    return;
  }

  std::string primeraLinea;
  std::getline(file, primeraLinea);

  std::string linea;
  while (std::getline(file, linea)) {
    // Ignorar líneas vacías
    if (linea.empty()) {
      continue;
    }

    std::istringstream ss(linea);
    std::string nombre, departamento;
    int puntuacion;

    // Verificar si la línea contiene al menos 3 campos
    if (std::getline(ss, nombre, ',') && std::getline(ss, departamento, ',') &&
        (ss >> puntuacion)) {
      // Crear el objeto adecuado según el departamento
      Empleados *nuevoEmpleado = nullptr;
      if (departamento == "Tienda de Radios") {
        nuevoEmpleado = new Radios(nombre, departamento, puntuacion);
        empleadosAgregados = true;
      } else if (departamento == "Tienda de Televisiones") {
        nuevoEmpleado = new Televisiones(nombre, departamento, puntuacion);
        empleadosAgregados = true;
      } else {
        // Manejar un departamento desconocido si es necesario
        std::cerr << "Departamento desconocido: " << departamento << std::endl;
      }

      if (nuevoEmpleado != nullptr) {
        empleadosTree.add(nuevoEmpleado);
      }
    } else {
      // Manejar el error de formato de línea incorrecto
      std::cerr << "Error de formato en la línea: " << linea << std::endl;
    }
  }

  file.close();
}

/**
 * agrega_radios: Crea un objeto Radios y lo agrega al árbol de empleados.
 *
 * @param nombre: Nombre del empleado
 * @param local: Local del empleado
 * @param num_ventas: Número de ventas realizadas por el empleado
 * @return
 */
void Empresa::agrega_radios(string nombre, string local, int num_ventas) {
  // new crea el objeto en tiempo de ejecución para usar polimorfismo
  empleadosTree.add(new Radios(nombre, local, num_ventas));
  empleadosAgregados = true;
}

/**
 * agrega_teles: Crea un objeto Televisiones y lo agrega al árbol de empleados.
 *
 * @param nombre: Nombre del empleado
 * @param local: Local del empleado
 * @param num_ventas: Número de ventas realizadas por el empleado
 * @return
 */
void Empresa::agrega_teles(string nombre, string local, int num_ventas) {

  // new crea el objeto en tiempo de ejecución para usar polimorfismo
  empleadosTree.add(new Televisiones(nombre, local, num_ventas));
  empleadosAgregados = true;
}

void Empresa::guardarEnCSV(const std::string &archivo) {

  std::ofstream file(archivo, std::ios::trunc);

  if (!file.is_open()) {
    // Manejar el error de no poder abrir el archivo
    std::cerr << "Error al abrir el archivo " << archivo << std::endl;
    return;
  }

  // Escribir la primera línea (encabezados)
  file << "Nombre,Departamento,Puntuacion\n";

  // Obtener la lista ordenada de empleados
  std::vector<Empleados *> empleadosList;
  empleadosTree.inorderToList(empleadosList);

  // Recorrer la lista y escribir cada empleado en el archivo CSV
  for (const auto &empleado : empleadosList) {
    file << empleado->to_string();
  }

  file.close();
}

void Empresa::mergeSortEmpleados() {
  // Verifica si hay empleados antes de intentar ordenar
  if (empleadosTree.empty()) {
    cout << "No hay empleados para ordenar." << endl;
    return;
  }

  // Obtén los empleados en un vector
  vector<Empleados *> empleadosList;
  empleadosTree.inorderToList(empleadosList);

  // Aplica el Merge Sort al vector de empleados
  Sort<Empleados *> sort;
  sort.MergeSort(empleadosList);

  // Vuelve a construir el árbol con el vector ordenado
  empleadosTree.removeAll();
  for (Empleados *empleado : empleadosList) {
    empleadosTree.add(empleado);
  }
}

inline Empleados *Empresa::buscarEmpleadoPorNombre(const string &nombre) {
  // Crea un vector temporal para almacenar los empleados en orden
  vector<Empleados *> empleadosList;
  empleadosTree.inorderToList(empleadosList);

  // Busca el empleado por nombre
  for (Empleados *empleado : empleadosList) {
    if (empleado->getNombre() == nombre) {
      return empleado;
    }
  }

  // Si no se encuentra, retorna nullptr
  return nullptr;
}

void Empresa::modificarVentasEmpleado(const string &nombre, int nuevasVentas) {
  Empleados *empleado = buscarEmpleadoPorNombre(nombre);

  if (empleado != nullptr) {
    empleado->setNumVentas(nuevasVentas);
    cout << "Numero de ventas modificado exitosamente." << endl;
    mergeSortEmpleados();
  } else {
    cout << "Empleado no encontrado." << endl;
  }
}
inline bool Empresa::hayEmpleadosAgregados() { return empleadosAgregados; }

#endif // Empresa.h