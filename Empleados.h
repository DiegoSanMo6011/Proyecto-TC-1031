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
 * Clase Empleados que tiene como atributo el nombre de los
 * empleados, tiene dos clases hijas:
 * "Televisiones" y "Radios"
 *
 */

#ifndef EMPLEADOS_H
#define EMPLEADOS_H

#include <string>
#include <sstream>

using namespace std;

//definicion de la clase empleados que es abstracta
class Empleados{
    //declaro atributos
    protected:
        string nombre;
        string local;
        int num_ventas;
    //declaracion de los contructores y los metodos 
    public:
        //constructor default
        Empleados();
        //constructor
        Empleados(string nom, string loc);
        //metodos
        virtual string to_string() = 0;
        string get_local();
        virtual int get_num_ventas()  = 0;
};

//cosntructor default
Empleados::Empleados () {
    nombre = ""; 
    local = "";
}

//contructor
Empleados::Empleados (string nom, string loc){
    nombre = nom;
    local = loc;
}


// getter de local
string Empleados::get_local(){
    return local;
}


#endif //Empleados.h