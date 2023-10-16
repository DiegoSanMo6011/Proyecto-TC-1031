# Proyecto: Gestión de Vendedores y Ventas
Este proyecto tiene como objetivo desarrollar un programa para gestionar vendedores y sus datos de ventas. Los usuarios pueden agregar nuevos vendedores, registrar información sobre sus ventas y realizar búsquedas en una estructura de árbol de búsqueda binaria.

## Descripción del avance 1
En este primer avance del proyecto, se han codificado todas las clases planificadas (Radios, Televisiones, Empleados y Empresa). Además, se ha desarrollado un programa principal (main.cpp) que funciona como un menú interactivo para que los usuarios interactúen con el sistema. El programa se ha subido a un repositorio de GitHub para facilitar el control de versiones y a su vez en Replit para su evaluación

## Descripción del avance 2
En este segundo avance, se ha incorporado un árbol de búsqueda binaria para gestionar y ordenar a los vendedores según el número de ventas. La razón detrás de esta mejora es aumentar la eficiencia del programa en la gestión de grandes conjuntos de datos. El árbol se recorre en orden (inorder), y se imprime el método to_string de los objetos contenidos en el árbol. Esto permite una representación ordenada y eficiente de los vendedores en función de sus ventas. 

### Cambios sobre el primer avance
1. Implementación de Árbol de Búsqueda Binaria: En lugar de utilizar Bubble Sort, se ha implementado una estructura de árbol de búsqueda binaria para ordenar y almacenar a los vendedores en función del número de ventas. La razón de esta elección es mejorar la eficiencia del programa para grandes conjuntos de datos, ya que el ordenamiento y búsqueda en un árbol de búsqueda binaria es más eficiente que Bubble Sort para este propósito.
2. Cambios Estéticos en el Menú
Se han realizado ajustes estéticos en el menú interactivo, mejorando la presentación de las opciones disponibles y la información mostrada al usuario. Estos cambios buscan hacer que el programa sea más agradable y fácil de usar.


## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`g++ main.cpp Empleados.h Empresa.h Radios.h Televisiones.h bst.h` 

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`./a.out` 

## Descripción de las entradas del avance de proyecto
El proyecto en su estado actual no requiere archivos de entrada externos. Las entradas se realizan a través del menú interactivo proporcionado por el programa main.cpp. Los usuarios pueden agregar vendedores, registrar ventas y buscar vendedores sin necesidad de archivos de entrada externos.

## Descripción de las salidas del avance de proyecto
Visualización del Menú: El programa muestra un menú interactivo que presenta las diferentes opciones disponibles para el usuario. Cada opción está numerada y se presenta de manera clara, facilitando la selección de acciones.

Visualización de Ejemplos y Vendedores: Cuando se selecciona la opción "Crear ejemplos y mostrar vendedores (prueba)", el programa muestra ejemplos de vendedores en un formato organizado. Cada vendedor se presenta con su nombre, local y número de ventas.

Visualización de la Lista de Vendedores: Al seleccionar la opción "Mostrar vendedores", el programa muestra una lista de vendedores en orden. Cada vendedor se presenta con su nombre, local y número de ventas.

Agregar Vendedor de Radios o Televisores: Cuando el usuario elige agregar un vendedor de radios o televisores, el programa solicita el nombre del empleado y el número de ventas que ha realizado. Después de completar la acción, el programa muestra un mensaje indicando que la acción se ha completado con éxito.

Mensaje de Salida: Al seleccionar la opción "Salir", el programa muestra un mensaje de despedida y se cierra.

Estas salidas proporcionan al usuario información clara y organizada sobre los vendedores y las acciones realizadas en el programa. Además, se destacan las acciones exitosas, como agregar un nuevo vendedor.

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
En este segundo avance, se ha implementado un árbol de búsqueda binaria para ordenar y almacenar a los vendedores. La elección de esta estructura se basó en un análisis de complejidad que demuestra su eficiencia en el ordenamiento y búsqueda de datos. El árbol de búsqueda binaria mejora significativamente el rendimiento del programa para grandes conjuntos de datos en comparación con Bubble Sort.

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.
El análisis de complejidad se ha centrado en la implementación del árbol de búsqueda binaria, que es fundamental para el ordenamiento y búsqueda de vendedores. Dado que las demás estructuras de datos utilizadas son relativamente simples, no se han identificado problemas de rendimiento significativos.

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
En lugar de utilizar Bubble Sort, se ha optado por la implementación de un árbol de búsqueda binaria para ordenar a los vendedores en función del número de ventas. Esta elección se basa en la eficiencia del árbol de búsqueda binaria en comparación con Bubble Sort, especialmente en conjuntos de datos más grandes. El uso de un árbol de búsqueda binaria demuestra la capacidad de seleccionar una estructura de datos adecuada para el problema.

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.
En este proyecto, se ha seleccionado y utilizado correctamente una estructura de árbol de búsqueda binaria para ordenar y almacenar a los vendedores en función del número de ventas. Esta elección mejora significativamente la eficiencia del programa y demuestra la capacidad de seleccionar una estructura de datos adecuada para el problema.

### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructras correctos.
En este avance, el programa permite a los usuarios buscar vendedores en función del número de ventas utilizando el árbol de búsqueda binaria. Estos mecanismos de consulta se han implementado correctamente y proporcionan resultados precisos y eficientes.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
La forma de cargar los datos a la estructura es por medio del menú interactivo del codigo.