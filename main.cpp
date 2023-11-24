#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <iomanip>

#include "Empresa.h"
#include "Empleados.h"
#include "Televisiones.h"
#include "Radios.h"
#include "bst.h"

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
    cout << "Accion completada con exito" << endl;
}

int main() {
    int opcion;
    char temp_nombre[100] = "";
    string temp_local;
    int temp_ventas;

    Empresa empresa;
    // Cargar empleados desde el archivo CSV
    empresa.cargarDesdeCSV("empleados.csv");


    while (true) {
        // Limpia la pantalla de la terminal
        system("cls");

        // Imprime el título y línea decorativa
        cout << "\033[32m";
        cout << setw(50) << "*********** Gestion de ventas por empleado ***********" << std::endl;
        cout << "\033[0m";
        imprimirLineaDecorativa(50);

        // Imprime las opciones
        // Imprime las opciones de manera más estilizada
        cout << "Opciones:" << std::endl;
        cout << "\033[1;36m1. Actualiza CSV\033[0m" << endl;
        cout << "\033[1;36m2. Agregar un vendedor de radios\033[0m" << endl;
        cout << "\033[1;36m3. Agregar un vendedor de televisiones\033[0m" << endl;
        cout << "\033[1;36m4. Modificar las Ventas de un Empleado\033[0m" << endl;
        cout << "\033[1;31m0. Salir\033[0m" << endl;
        imprimirLineaDecorativa(50);

        cout << "Seleccione una opcion: " << endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                if (empresa.hayEmpleadosAgregados()) {
                    empresa.guardarEnCSV("empleados.csv");
                    return 0;
                } else {
                    cout << "No se han agregado empleados. Agregue empleados antes de cargarlos." << endl;
                    // Pausa antes de continuar
                    cout << "Presione Enter para continuar...";
                    limpiarBuffer();
                    cin.get();
                }
                break;

            case 2:
                cout << "Escribe el nombre del empleado: ";
                limpiarBuffer();
                cin.getline(temp_nombre, sizeof(temp_nombre));
                temp_local = "Tienda de Radios";
                cout << "Dime el numero de ventas que hizo este empleado: ";
                cin >> temp_ventas;

                empresa.agrega_radios(temp_nombre, temp_local, temp_ventas);
                mostrarConfirmacion();
                break;
            case 3:
                cout << "Escribe el nombre del empleado: ";
                limpiarBuffer();
                cin.getline(temp_nombre, sizeof(temp_nombre));
                temp_local = "Tienda de Televisiones";
                cout << "Dime el numero de ventas que hizo este empleado: ";
                cin >> temp_ventas;

                empresa.agrega_teles(temp_nombre, temp_local, temp_ventas);
                mostrarConfirmacion();
                break;

            case 4:
                cout << "Escribe el nombre del empleado: ";
                limpiarBuffer();
                cin.getline(temp_nombre, sizeof(temp_nombre));
                cout << "Dime el numero de ventas que hizo este empleado: ";
                cin >> temp_ventas;
                empresa.modificarVentasEmpleado(temp_nombre,temp_ventas);
                empresa.mergeSortEmpleados();
                mostrarConfirmacion();
                break;

            case 0:
                // Cierra el archivo de salida
                cout << "Saliendo del programa. Hasta luego :D" << endl;
                return 0;
            default:
                cout << "Opcion no valida. Por favor, elija una opcion valida." << endl;
                break;
        }

        // Pausa antes de continuar
        cout << "Presione Enter para continuar...";
        limpiarBuffer();
        cin.get();
    }

    return 0;
}