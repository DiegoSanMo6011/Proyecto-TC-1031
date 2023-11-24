# Proyecto: Gestión de Vendedores y Ventas

## Overview del Proyecto

El proyecto **Gestión de Vendedores y Ventas** tiene como objetivo desarrollar un programa que permita gestionar vendedores, registrar datos de ventas y ofrecer funcionalidades como ordenar la lista de vendedores y realizar operaciones de lectura y escritura de archivos.

## Descripción del avance 1

En este primer avance, se han codificado las clases planificadas (Radios, Televisiones, Empleados y Empresa). También se ha desarrollado un programa principal (`main.cpp`) que funciona como un menú interactivo para que los usuarios interactúen con el sistema. Se ha establecido un repositorio de GitHub para facilitar el control de versiones y la colaboración.

## Descripción del avance 2

En este segundo avance, se ha implementado un árbol de búsqueda binaria para gestionar y ordenar a los vendedores según el número de ventas. Este cambio se realizó para mejorar la eficiencia del programa en la gestión de grandes conjuntos de datos. Se han realizado cambios estéticos en el menú interactivo para mejorar su presentación.

### Cambios sobre el primer avance
1. **Implementación de Árbol de Búsqueda Binaria:**
   - Se ha sustituido el Bubble Sort por un árbol de búsqueda binaria para ordenar y almacenar a los vendedores. La razón es mejorar la eficiencia del programa para grandes conjuntos de datos.

2. **Cambios Estéticos en el Menú:**
   - Ajustes visuales en el menú interactivo para mejorar la presentación y usabilidad.

## Descripción del avance 3

En este tercer avance, se han implementado nuevas funcionalidades y mejoras en el programa. Se ha agregado la capacidad de modificar el número de ventas de un vendedor y reordenar la lista usando Merge Sort. Además, se ha permitido cargar datos iniciales desde un archivo CSV y guardar datos en un archivo CSV.

### Cambios sobre el segundo avance
1. **Modificación de Ventas y Reordenamiento:**
   - Se ha implementado la modificación del número de ventas y reordenamiento de la lista utilizando Merge Sort para ampliar la funcionalidad del programa.

2. **Lectura Inicial desde Archivo CSV:**
   - Se ha añadido la funcionalidad de cargar datos iniciales de vendedores desde un archivo CSV para facilitar la inicialización del programa con datos preexistentes.

3. **Escritura de Datos en Archivo CSV:**
   - Se ha implementado la capacidad de guardar los datos de los vendedores en un archivo CSV para conservar la información entre sesiones.

4. **Análisis de Complejidad Adicional:**
   - Se ha agregado el análisis de complejidad para los algoritmos de ordenamiento, todas las estructuras de datos y cada uno de sus usos en el programa. También se ha incluido el análisis de complejidad para todos los demás componentes del programa, determinando la complejidad final del mismo.

## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:


g++ main.cpp Empleados.h Empresa.h Radios.h Televisiones.h bst.h Sort.h

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:


./a.out

## Descripción de las entradas del avance de proyecto
Para la carga inicial desde un archivo CSV, el formato del archivo debe ser:


Nombre,Local,Ventas
Arturo,Tienda de Televisiones,32
Cristiano Ronaldo,Tienda de Televisiones,10
Juan Carlos Perez,Tienda de Radios,9
Fulanito Gutierrez,Tienda de Radios,8
Leo Messi,Tienda de Televisiones,7

El resto de entradas se piden dentro de la ejecución del programa en la terminal por medio de un menú que te va indicando que datos escribir.

## Descripción de las salidas del avance de proyecto

Las salidas del programa incluyen mensajes de confirmación para operaciones como la modificación de ventas, carga desde CSV y guardado en CSV. El menú interactivo presenta opciones organizadas, facilitando la gestión de vendedores y ventas. Es importante seleccionar la opción 1 (Actualizar CSV) para guardar y visualizar los cambios en los empleados.


## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
En el Proyecto, he incorporado el algoritmo de ordenamiento Merge Sort en la clase `Sort`. Esta elección se basa en un análisis exhaustivo de su complejidad, tanto temporal como espacial:

- **Análisis de Complejidad Temporal:**
  - **Mejor Caso:** O(n log n) - Se alcanza cuando el arreglo ya está ordenado, facilitando fusiones eficientes.
  - **Caso Promedio:** O(n log n) - Merge Sort demuestra un rendimiento constante y eficiente al dividir y fusionar el arreglo de manera logarítmica en cada nivel.
  - **Peor Caso:** O(n log n) - Incluso en situaciones desfavorables, Merge Sort mantiene un rendimiento predeciblemente eficiente mediante su estrategia de división y fusión.

- **Análisis de Complejidad Espacial:**
  - O(n) - Merge Sort requiere espacio adicional para almacenar el arreglo auxiliar durante la fusión, en proporción al tamaño del arreglo.

Considerando el contexto de mi programa, la elección de Merge Sort para ordenar un conjunto de datos de empleados según el número de ventas se fundamenta en la optimización de la operación de ordenamiento. Este análisis respalda la decisión de implementar Merge Sort y refleja mi comprensión de los aspectos clave de rendimiento y eficiencia en el desarrollo de software. Estoy convencido de que esta elección contribuirá positivamente al rendimiento general de mi proyecto.Si lograste este criterio anteriormente, copia aquí tu argumentación. Si no, ésta es una nueva oportunidad para lograrlo. Escribe aquí tu aprendizaje y tus argumentos sobre por qué consideras que ahora ya has desarrrollado este criterio y dónde se puede observar el desarrollo que mencionas.

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.

En mi proyecto individual, he implementado una estructura de datos clave: un árbol binario de búsqueda (BST) en la clase `BST`. A continuación, se presenta un análisis detallado de la complejidad temporal y espacial de esta estructura y sus usos en el programa:

**Árbol Binario de Búsqueda (BST):**
- **Complejidad Temporal:**
  - **Inserción (add):** 
    - Mejor Caso: O(1) - En un árbol balanceado, la inserción puede ser constante en el mejor caso cuando se agrega en una posición que mantiene el equilibrio.
    - Peor Caso: O(h) - En el peor caso, donde el árbol está desbalanceado, la inserción tiene una complejidad de O(h), donde h es la altura del árbol. Si el árbol está completamente desbalanceado, h puede ser igual al número de nodos, llevando a una complejidad de O(n), donde n es el número de nodos en el árbol.
  - **Búsqueda (find):** 
    - Mejor Caso: O(1) - En un árbol balanceado, la búsqueda puede ser constante en el mejor caso.
    - Peor Caso: O(h) - En el peor caso, donde el árbol está desbalanceado, la búsqueda tiene una complejidad de O(h). En el caso más desfavorable desbalanceado, h puede ser igual al número de nodos, llevando a una complejidad de O(n).
  - **Eliminación (remove):** 
    - Mejor Caso: O(1) - En un árbol balanceado, la eliminación puede ser constante en el mejor caso cuando se elimina un nodo hoja.
    - Peor Caso: O(h) - La complejidad de eliminar un nodo depende de la ubicación del nodo y la estructura del árbol. En el peor caso desbalanceado, la altura h puede ser igual al número de nodos, llevando a una complejidad de O(n).
  - **Recorrido Inorden (inorder):** O(n) - Realizar un recorrido inorden implica visitar todos los nodos del árbol una vez, lo cual es lineal.

- **Complejidad Espacial:**
  - O(n) - La complejidad espacial de un BST es lineal, ya que se almacena un nodo por cada elemento en el árbol.


En el programa, el BST se utiliza para organizar y gestionar eficientemente la información de los empleados, específicamente para mantenerlos ordenados según el número de ventas. La elección de un BST se justifica por su capacidad para realizar operaciones de inserción, búsqueda y eliminación de manera eficiente, aspectos cruciales para las operaciones del programa.

Este análisis respalda mi decisión de utilizar un árbol binario de búsqueda y demuestra mi comprensión de la complejidad asociada con esta estructura de datos en el contexto del proyecto.


#### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.

##### Clase Empleados
- **Constructor Empleados()**: Complejidad de tiempo: O(1) - constante, ya que solo inicializa atributos.
- **Constructor Empleados(string, string)**: Complejidad de tiempo: O(1) - constante, ya que inicializa atributos.
- **Método to_string()**: Complejidad de tiempo: O(1) - constante, ya que solo concatena atributos.
- **Método getNombre() const y getLocal() const**: Complejidad de tiempo: O(1) - constante, ya que simplemente devuelve un atributo.
- **Método setNumVentas(int ventas)**: Complejidad de tiempo: O(1) - constante, ya que solo asigna un valor al atributo.
- **Operadores de comparación (operator<, operator>, operator==)**: Complejidad de tiempo: O(1) - constante, ya que compara solo el atributo num_ventas.

##### Clase Empresa
### 1. Constructor `Empresa()`
   - Complejidad: O(1)
   - No realiza operaciones dependientes del tamaño de los datos.

### 2. Método `cargarDesdeCSV(const std::string &archivo)`
   - Complejidad: O(n log n), donde n es el número de líneas en el archivo CSV.
   - Lee cada línea, crea objetos `Empleados` y los agrega al árbol. La inserción en el árbol (`empleadosTree.add()`) tiene complejidad O(log n).

### 3. Métodos `agrega_radios` y `agrega_teles`
   - Complejidad: O(log n)
   - Realizan la inserción en el árbol (`empleadosTree.add()`), con complejidad O(log n).

### 4. Método `guardarEnCSV(const std::string &archivo)`
   - Complejidad: O(n log n), donde n es el número de empleados en el árbol.
   - Obtiene una lista ordenada de empleados y escribe cada empleado en el archivo. In-order traversal tiene complejidad O(n), y escribir cada empleado es constante.

### 5. Método `mergeSortEmpleados()`
   - Complejidad: O(n log n), donde n es el número de empleados en el árbol.
   - Realiza in-order traversal, aplica Merge Sort al vector de empleados y reconstruye el árbol. In-order traversal tiene complejidad O(n), y Merge Sort tiene complejidad O(n log n).

### 6. Método `buscarEmpleadoPorNombre(const string &nombre)`
   - Complejidad: O(n), donde n es el número de empleados en el árbol.
   - Realiza in-order traversal para buscar el empleado por nombre.

### 7. Método `modificarVentasEmpleado(const string &nombre, int nuevasVentas)`
   - Complejidad: O(n log n), donde n es el número de empleados en el árbol.
   - Busca el empleado por nombre (O(n)), modifica las ventas y realiza un ordenamiento (Merge Sort) en el árbol, O(n log n).

### 8. Método `hayEmpleadosAgregados()`
   - Complejidad: O(1)
   - Devuelve el valor de una variable miembro, operación constante.

##### Clase Radios
- **Constructor Radios()**: Complejidad de tiempo: O(1) - constante, ya que solo inicializa atributos.
- **Constructor Radios(string, string, int)**: Complejidad de tiempo: O(1) - constante, ya que inicializa atributos.
- **Método to_string()**: Complejidad de tiempo: O(1) - constante, ya que solo llama al método to_string de la clase base y concatena atributos.
- **Método get_num_ventas() const**: Complejidad de tiempo: O(1) - constante, ya que devuelve un atributo.

##### Clase Televisiones
- **Constructor Televisiones()**: Complejidad de tiempo: O(1) - constante, ya que solo inicializa atributos.
- **Constructor Televisiones(string, string, int)**: Complejidad de tiempo: O(1) - constante, ya que inicializa atributos.
- **Método to_string()**: Complejidad de tiempo: O(1) - constante, ya que solo llama al método to_string de la clase base y concatena atributos.
- **Método get_num_ventas() const**: Complejidad de tiempo: O(1) - constante, ya que devuelve un atributo.

##### Complejidad Final del Programa
La complejidad final del programa está dominada por las operaciones en el árbol de búsqueda binaria utilizado para almacenar y gestionar los empleados. Las operaciones clave, como agregar, buscar y modificar las ventas de un empleado, tienen una complejidad de O(log N), donde N es el número de empleados en el árbol. Además, la operación de ordenamiento en modificarVentasEmpleado contribuye con una complejidad adicional de O(N log N). Por lo tanto, la complejidad general del programa se puede expresar como O(N log N), siendo N el número total de empleados.


### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.

En el desarrollo del programa, he seleccionado el algoritmo de ordenamiento Merge Sort para la gestión de empleados. Esta elección se basa en la eficiencia de Merge Sort para ordenar grandes conjuntos de datos y su estabilidad, lo que significa que no cambia el orden de elementos con claves iguales. Además, al no requerir comparaciones directas entre elementos para realizar el ordenamiento, Merge Sort es una elección eficiente para estructuras de datos complejas como árboles.

Esta decisión se refleja en la implementación del método mergeSortEmpleados() en la clase Empresa, donde aplico el algoritmo Merge Sort para ordenar los empleados almacenados en un árbol binario de búsqueda. La correcta aplicación de este algoritmo se puede observar en la eficiencia del programa para manejar grandes cantidades de empleados y garantizar un orden correcto en las operaciones de escritura y lectura de archivos.

La eficiencia de Merge Sort se fundamenta en su complejidad temporal de O(N log N), que es especialmente valiosa para estructuras de datos complejas como árboles. Este algoritmo asegura un rendimiento consistente incluso en situaciones desfavorables, contribuyendo así a la eficiencia global del programa.

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.
La elección de un árbol binario de búsqueda como estructura de datos para almacenar y gestionar empleados es fundamental para garantizar un acceso eficiente y ordenado a la información. La estructura jerárquica del árbol binario de búsqueda facilita la implementación de operaciones como la búsqueda, inserción y modificación de empleados en un tiempo logarítmico, lo que mejora significativamente la eficiencia del programa.

Comparado con estructuras de datos como listas enlazadas o arreglos, las cuales tendrían complejidades temporales distintas:

Listas Enlazadas: La búsqueda en una lista enlazada tiene una complejidad temporal de O(N), donde N es el número de elementos. La inserción y eliminación pueden ser más eficientes que en un arreglo, pero aún así, tienen una complejidad O(N) en el peor de los casos.

Arreglos: La búsqueda en un arreglo tiene una complejidad temporal de O(N), similar a la lista enlazada. Sin embargo, la inserción y eliminación en un arreglo pueden ser más costosas, especialmente si se requiere desplazar elementos, lo que lleva a una complejidad de O(N) en el peor de los casos.

La complejidad logarítmica O(log N) del árbol binario de búsqueda destaca su eficiencia en comparación con estas estructuras, especialmente cuando se trata de operaciones que involucran grandes conjuntos de datos.

### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructras correctos.
En este avance, el programa permite a los usuarios buscar vendedores en función del número de ventas utilizando el árbol de búsqueda binaria. Estos mecanismos de consulta se han implementado correctamente y proporcionan resultados precisos y eficientes.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.

La implementación de la lectura de archivos se realiza correctamente a través del método cargarDesdeCSV en la clase Empresa. Este método lee datos desde un archivo CSV, crea objetos Empleados o derivados, y los agrega al árbol binario de búsqueda correspondiente. La elección de un formato CSV para la entrada de datos facilita la carga eficiente de información, y la utilización de estructuras de datos específicas asegura una correcta organización de los empleados en el programa

### Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta
La implementación de mecanismos de escritura de archivos se realiza de manera correcta mediante el método guardarEnCSV en la clase Empresa. Este método realiza un recorrido inorder en el árbol binario de búsqueda, escribiendo los datos de los empleados en un formato CSV. La elección de este enfoque garantiza la consistencia en la representación de datos en el archivo de salida y facilita la posterior lectura y procesamiento de la información almacenada. 