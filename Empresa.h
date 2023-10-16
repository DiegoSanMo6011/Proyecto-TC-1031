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
 * Esta clase define objeto de tipo Empresa que contiene todas las operaciones para 
 * agregar nuevos empleados de cada local y permite mostrar los mejores
 * vendedores.
 * 
 */

#ifndef EMPRESA_H
#define EMPRESA_H

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

//bibliotecas con los objetos a usar
#include "Empleados.h"
#include "Televisiones.h"
#include "Radios.h"
#include "bst.h" 

using namespace std;

const int MAX = 100; // valor constante para el tamano de los arreglos

//definicion de la clase
class Empresa{
    //Declaro las variables de isntancia
    private:
        BST<Empleados*> empleadosTree; // Usamos un puntero a Empleados para permitir objetos de clases derivadas
        int cont;
        
    //Declaro constructor default y metodos publicos
    public:
        Empresa(): cont(0){}; //cosntructor default

        void crea_ejemplos();
        void muestra_vendedores();
        void agrega_radios(string nombre, string local, int num_ventas);
        void agrega_teles(string nombre, string local, int num_ventas);
};

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
void Empresa::crea_ejemplos(){
    empleadosTree.add(new Radios("Juan Carlos Perez", "Tienda de Radios", 9));
    empleadosTree.add(new Radios("Fulanito Gutierrez", "Tienda de Radios",8));
    empleadosTree.add(new Televisiones("Leo Messi", "Tienda de Televisiones", 7));
    empleadosTree.add(new Televisiones("Cristiano Ronaldo", "Tienda de Televisiones", 10));
    
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
  //new crea el objeto en tiempo de ejecución para usar polimorfismo
  empleadosTree.add(new Radios(nombre, local, num_ventas));

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

  //new crea el objeto en tiempo de ejecución para usar polimorfismo
  empleadosTree.add(new Televisiones(nombre, local, num_ventas));
}



// Muestra a los vendedores en orden
void Empresa::muestra_vendedores(){
  if (empleadosTree.empty()) {
        cout << "No hay empleados registrados." << endl;
        return;
    }
  // Crea un stringstream para acumular los datos de los empleados
  stringstream empleadosEnOrden;
  empleadosTree.inorder(empleadosEnOrden);
  cout << "\033[32m";
  cout << setw(50) << "*********** Empleados en orden ***********" << std::endl;
  cout << "\033[0m";
  cout << empleadosEnOrden.str() <<endl;
}




#endif //Empresa.h