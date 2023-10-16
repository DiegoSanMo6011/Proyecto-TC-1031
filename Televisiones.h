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
 * 
 * 
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
    // declaracion de los contructores y los metodos
    public:
        //constructor default
        Televisiones ();
        //cosntructor
        Televisiones (string, string, int);
        //metodos
        string to_string () override;
        int get_num_ventas() const override;

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

//get ventas
int Televisiones::get_num_ventas() const{
    return num_ventas;
}
#endif // Televisiones.h