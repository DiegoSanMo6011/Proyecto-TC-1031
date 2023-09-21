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
 * Main que funciona como menu para escoger que funcion del codigo se desea utilizar
 * y demostrar el correcto funcionamiento del mismo.
 */

 //librerias 
 #include <iostream>
#include <string>
#include <limits> // Para limpiar el búfer de entrada

#include "Empresa.h"
#include "Empleados.h"
#include "Televisiones.h"
#include "Radios.h"

using namespace std;

// Función para imprimir una línea decorativa
void imprimirLineaDecorativa(int longitud) {
    for (int i = 0; i < longitud; i++) {
        cout << "-";
    }
    cout << endl;
}

// Función para limpiar el búfer de entrada
void limpiarBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Función para mostrar un mensaje de confirmación
void mostrarConfirmacion() {
    cout << "Acción completada con exito" << endl;
}

int main() {
    int opcion;
    char temp_nombre[100] = "";
    string temp_local;
    int temp_ventas;

    Empresa empresa;

    while (true) {
        // Limpia la pantalla de la terminal
        system("cls");

        // Imprime el título y línea decorativa
        cout << "\033[32m*********** Gestion de ventas por empleado ***********\033[0m" << endl;
        imprimirLineaDecorativa(50);

        // Imprime las opciones
        cout << "1. Crear ejemplos y mostrar vendedores (prueba)" << endl;
        cout << "2. Mostrar vendedores" << endl;
        cout << "3. Mostrar vendedores con mas ventas" << endl;
        cout << "4. Agregar un vendedor de radios" << endl;
        cout << "5. Agregar un vendedor de televisiones" << endl;
        cout << "0. Salir" << endl;
        imprimirLineaDecorativa(50);

        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                empresa.crea_ejemplos();
                empresa.muestra_vendedores();
                break;
            case 2:
                empresa.muestra_vendedores();
                break;
            case 3:
                empresa.bubble_sort();
                empresa.muestra_vendedores();
                break;
            case 4:
                cout << "Escribe el nombre del empleado: ";
                limpiarBuffer();
                cin.getline(temp_nombre, sizeof(temp_nombre));
                temp_local = "Tienda de Radios";
                cout << "Dime el numero de ventas que hizo este empleado: ";
                cin >> temp_ventas;

                empresa.agrega_radios(temp_nombre, temp_local, temp_ventas);
                mostrarConfirmacion();
                break;
            case 5:
                cout << "Escribe el nombre del empleado: ";
                limpiarBuffer();
                cin.getline(temp_nombre, sizeof(temp_nombre));
                temp_local = "Tienda de Televisiones";
                cout << "Dime el numero de ventas que hizo este empleado: ";
                cin >> temp_ventas;

                empresa.agrega_teles(temp_nombre, temp_local, temp_ventas);
                mostrarConfirmacion();
                break;
            case 0:
                cout << "Saliendo del programa. Hasta luego :D" << endl;
                return 0;
            default:
                cout << "Opción no valida. Por favor, elija una opción valida." << endl;
                break;
        }

        // Pausa antes de continuar
        cout << "Presione Enter para continuar...";
        limpiarBuffer();
        cin.get();
    }

    return 0;
}