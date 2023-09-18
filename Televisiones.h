/*
 * Proyecto Gestión de Vendedores y Ventas
 * Diego Gerardo Sanchez Moreno
 * A01276011
 * 
 */

/*
 * Clase Televisiones que hereda de la clase Empleados
 */

#ifndef TELEVISIONES_H
#define TELEVISIONES_H

#include "Empleados.h"

#include <string>
#include <sstream>

using namespace std;

class Televisiones: public Empleados{
    // declaro atributos privados de instancia
    private:
        int num_ventas;
    // declaracion de los contructores y los metodos
    public:
        //constructor default
        Televisiones ();
        //cosntructor
        Televisiones (string, string, int);
        //metodos
        int get_num_ventas ();
        string to_string ();

};

//constructor default 
Televisiones::Televisiones () {
    nombre = ""; 
    local = ""; 
}

//cosntructor
Televisiones::Televisiones (string nom, string loc, int vent):Empleados(nom,loc){
    num_ventas = vent;
}

//get ventas
int Televisiones::get_num_ventas(){
    return num_ventas;
}

/**
 * Almacena los valores de las variables de instancia en una cadena de
 * texto.
 *
 * @param
 * @return string con los datos de Empleados del local televisiones
*/
string Televisiones::to_string(){

    stringstream aux;
    aux << "\nNombre: " << nombre << "\nLocal: " << local << "\nVentas: " << num_ventas << "\n" ;
    return aux.str();
}

#endif // Radios.h