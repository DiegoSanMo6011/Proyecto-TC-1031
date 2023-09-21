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
 * vendedores, tato generales como de cada local
 * 
 */

#ifndef EMPRESA_H
#define EMPRESA_H

#include <string>
#include <iostream>
#include <sstream>

//bibliotecas con los objetos a usar
#include "Empleados.h"
#include "Televisiones.h"
#include "Radios.h"

using namespace std;

const int MAX = 100; // valor constante para el tamano de los arreglos

//definicion de la clase
class Empresa{
    //Declaro las variables de isntancia
    private:
        Empleados * empl[MAX]; // se define como apuntador para utilizar polimorfismo
        int cont = 0;
        


    //Declaro constructor default y metodos publicos
    public:
        Empresa(): cont(0){}; //cosntructor default

        void crea_ejemplos();
        void muestra_vendedores();
        void bubble_sort();
        void agrega_radios(string nombre, string local, int num_ventas);
        void agrega_teles(string nombre, string local, int num_ventas);
};

/**
 * crea_ejemplos genera objetos en empl[]
 *
 * genera objetos de tipo Radios y Televisiones los
 * guarda en la varibale de instancia en empl[] (arreglo de empleados)
 * para poder hacer pruebas. No usar esta función si se va a usar el programa
 * como agenda, ya que los datos son falsos.
 *
 * @param
 * @return
 */
void Empresa::crea_ejemplos(){
    //la funcion new crea el objeto en tiempo de ejecucion para usar polimorfismo
    empl[cont] = new Radios("Juan Carlos Perez", "Tienda de Radios", 76);
    cont++;
    empl[cont] = new Radios("Fulanito Gutierrez", "Tienda de Radios", 12);
    cont++;
    empl[cont] = new Televisiones("Leo Messi", "Tienda de Televisiones", 56);
    cont++;
    empl[cont] = new Televisiones("Cristiano Ronaldo", "Tienda de Televisiones", 89);
    cont++;
    
}


/**
 * agrega_radios crea un objeto Radios y lo agrega a
 * arreglo de empleados usando como
 * index un contador que incrementa en 1.
 *
 * @param string nom, string loc, int num_ventas
 * @return
 */
void Empresa::agrega_radios(string nombre, string local, int num_ventas) {

  //new crea el objeto en tiempo de ejecución para usar polimorfismo
  empl[cont] = new Radios(nombre, local, num_ventas);
  cont++;
}

/**
 * agrega_teles crea un objeto Televisiones y lo agrega a
 * arreglo de empleados usando como
 * index un contador que incrementa en 1.
 *
 * @param string nom, string loc, int num_ventas
 * @return
 */
 
void Empresa::agrega_teles(string nombre, string local, int num_ventas) {

  //new crea el objeto en tiempo de ejecución para usar polimorfismo
  empl[cont] = new Televisiones(nombre, local, num_ventas);
  cont++;
}


/* ================== Bubble Sort ================================*/
/**
 * Ordena el arreglo de apuntadores
 *
 * @param
 * @return
 */
void Empresa::bubble_sort(){
  bool swapped;
    // ciclo que accede a cada elemento del arreglo
    for (int i = 0; i < cont - 1; i++) {
        swapped = false;
        //ciclo para comparar cada elemento del arreglo
        for (int j=0; j < cont - i -1; j++){
            //comparar
            if (empl[j] -> get_num_ventas() < empl[j + 1] -> get_num_ventas()){
                swap(empl[j], empl[j+1]);
                swapped = true;
            }
        }  
        if (swapped == false)
            break;  
    }
}


//muestra
void Empresa::muestra_vendedores(){
  
  for (int i = 0; i < cont; i++){
    cout << empl[i] -> to_string();
  }
}




#endif //Empresa.h