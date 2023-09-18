/*
 * Proyecto Gestión de Vendedores y Ventas
 * Diego Gerardo Sanchez Moreno
 * A01276011
 * 
 */

/*
 * Clase Radios que hereda de la clase Empleados
 */

#ifndef RADIOS_H
#define RADIOS_H

#include "Empleados.h"

#include <string>
#include <sstream>

using namespace std;

class Radios: public Empleados{
    // declaro atributos privados de instancia
    private:
        int num_ventas;
    // declaracion de los contructores y los metodos
    public:
        //constructor default
        Radios ();
        //cosntructor
        Radios (string, string, int);
        //metodos
        int get_num_ventas ();
        string to_string ();

};

//constructor default 
Radios::Radios () {
    nombre = ""; 
    local = ""; 
}

//cosntructor
Radios::Radios (string nom, string loc, int vent):Empleados(nom,loc){
    num_ventas = vent;
}

//get ventas
int Radios::get_num_ventas(){
    return num_ventas;
}

/**
 * Almacena los valores de las variables de instancia en una cadena de
 * texto.
 *
 * @param
 * @return string con los datos de Empleados del local televisiones
*/
string Radios::to_string(){

    stringstream aux;
    aux << "\nNombre: " << nombre << "\nLocal: " << local << "\nVentas: " << num_ventas << "\n" ;
    return aux.str();
}

#endif // Sucursal_sur.h