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
 * version : 1
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
        int cont;
    //Declaro constructor default y metodos publicos
    public:
        Empresa(): cont(0){}; //cosntructor default

        void crea_ejemplos();
        void muestra_mas_ventas();
        void muestra_mas_ventas(string local);
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
    empl[cont] = new Radios("Juan Carlos Perez", "Radios", 76);
    cont++;
    empl[cont] = new Radios("Fulanito Gutierrez", "Radios", 12);
    cont++;
    empl[cont] = new Televisiones("Leo Messi", "Televisiones", 12345);
    cont++;
    empl[cont] = new Televisiones("Cristiano Ronaldo", "Televisiones", 12344);
    cont++;
    
}


//merge sort
void Empresa::muestra_mas_ventas(){

}

void Empresa::muestra_mas_ventas(string local){
    
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

#endif //Empresa.h