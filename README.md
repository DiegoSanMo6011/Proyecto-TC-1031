# Proyecto de Gestión de Vendedores y Ventas

## Descripción del Proyecto

Este proyecto de "Gestión de Vendedores y Ventas" se enfoca en el desarrollo de un programa que permite gestionar vendedores y sus datos de ventas. Los usuarios pueden agregar nuevos vendedores y registrar información sobre sus ventas. Además, el programa ofrece la funcionalidad de ordenar y mostrar a los vendedores en función del número de ventas, de mayor a menor.


## Descripcion de Avance
En este avance se codificaron todas las clases planeadas (Radios, Televisiones, Empleados y Empresa) tambien se ralizo un main y se hizo el repositorio de github.
La funcionalidad meta que era ordenar los vendedores por numero de ventas fue lograda, en las siguientes entregas se piensa agragar nuevos metodos para que el tener distintos tipos de clases hijas de empleados tenga una funcionalidad, es decir agregar nuevos metodos y atributos a estas clases. Tambien se planea agregar un metodo a la clase Empresa que permita buscar los empleados de una tienda especifica.

## Cómo Usar el Programa

El programa se ejecuta a través del archivo `main.cpp`, que funciona como un menú interactivo. Los usuarios pueden realizar las siguientes acciones:

1. **Crear ejemplos y mostrar vendedores (prueba)**: Genera ejemplos de vendedores y muestra la lista de vendedores.

2. **Mostrar vendedores**: Muestra la lista de vendedores actual.

3. **Mostrar vendedores con más ventas**: Ordena y muestra a los vendedores de mayor a menor número de ventas.

4. **Agregar un vendedor de radios**: Permite agregar un vendedor de radios con su nombre, local y número de ventas.

5. **Agregar un vendedor de televisiones**: Permite agregar un vendedor de televisiones con su nombre, local y número de ventas.

0. **Salir**: Sale del programa.

## Cumplimiento de las Sub-Competencias

### SICT0301: Evalúa los componentes

El uso de Bubble Sort en este proyecto se fundamenta en una evaluación exhaustiva de sus componentes y su adecuación al contexto específico del programa. A continuación, se detallan los aspectos clave de esta evaluación:

Análisis de Complejidad: Dado que el tamaño del arreglo de empleados es limitado, se ha realizado un análisis de complejidad que demuestra que el rendimiento de Bubble Sort es satisfactorio para esta aplicación. Aunque Bubble Sort tiene una complejidad de tiempo de O(n^2) en el peor caso, su rendimiento es aceptable para conjuntos de datos pequeños, como el utilizado en este proyecto.

Memoria y Recursos: En proyectos con recursos limitados, como sistemas embebidos o aplicaciones de hardware restringidas, el uso de algoritmos más simples como Bubble Sort puede ser una elección adecuada para minimizar la carga de memoria y recursos. En este caso, dado que el arreglo es pequeño y la complejidad espacial de Bubble Sort es O(1), se evita un consumo innecesario de recursos.

Mantenimiento y Claridad del Código: La claridad del código es esencial para facilitar el mantenimiento y la comprensión del proyecto. Bubble Sort es un algoritmo simple de implementar y depurar, lo que lo hace más accesible para futuras modificaciones o colaboraciones en el código.

Compatibilidad con Objetos Polimórficos: El programa maneja objetos de diferentes tipos (Radios y Televisiones) en un arreglo de apuntadores a la clase base "Empleados". Bubble Sort se adapta naturalmente a esta situación, ya que se basa en comparaciones de elementos sin preocuparse por su tipo específico.

En resumen, la elección de Bubble Sort se apoya en una evaluación completa de sus componentes, teniendo en cuenta aspectos de rendimiento, uso eficiente de recursos, facilidad de mantenimiento y compatibilidad con la estructura de datos del proyecto. Esto garantiza que el algoritmo sea adecuado y eficiente en el contexto específico de esta aplicación de gestión de vendedores y ventas.

### SICT0302: Toma decisiones

Se optó por utilizar el algoritmo de ordenamiento "Bubble Sort" en lugar de otros algoritmos más eficientes (como Merge Sort o Quick Sort) debido a varias consideraciones específicas para este proyecto:

Tamaño del Arreglo: El arreglo de empleados en este proyecto es relativamente pequeño, lo que significa que no se requiere una gran cantidad de memoria ni una alta velocidad de ordenamiento. En situaciones con arreglos pequeños, la diferencia en la eficiencia entre Bubble Sort y otros algoritmos más avanzados es insignificante.

Sencillez de Implementación: Bubble Sort es un algoritmo de ordenamiento simple y fácil de entender. Utiliza una única función para su funcionamiento, lo que facilita la implementación y el mantenimiento del código. En proyectos pequeños o con fines educativos, la simplicidad de la implementación puede ser una ventaja importante.

Ordenamiento de Objetos Polimórficos: En este proyecto, se está ordenando un arreglo de apuntadores a objetos de la clase "Empleados". Estos objetos pueden ser de dos tipos diferentes: "Radios" y "Televisiones". Al usar Bubble Sort, es más sencillo ordenar el arreglo sin preocuparse por el tipo de objeto, lo que evita problemas potenciales al tratar de ordenar objetos heterogéneos.

Facilita la Interacción del Usuario: Dado que el programa permite al usuario agregar vendedores de diferentes tipos (Radios o Televisiones), utilizar un algoritmo más complejo podría introducir limitaciones en la funcionalidad. Bubble Sort permite mantener la simplicidad de la interacción del usuario al ordenar el arreglo de empleados sin restricciones.

En resumen, la elección de Bubble Sort se basa en la eficiencia adecuada para el tamaño del arreglo, la facilidad de implementación, la capacidad de manejar objetos polimórficos y la compatibilidad con la funcionalidad del programa que permite la inclusión de vendedores de diferentes tipos. Estas consideraciones hacen que Bubble Sort sea una elección apropiada y justificable para este proyecto.

## Instrucciones de Ejecución

1. Abre una terminal o línea de comandos.

2. Navega al directorio donde se encuentra el archivo `main.cpp`.

3. Compila el programa utilizando un compilador C++ compatible (por ejemplo, g++):

   ```bash
   g++ main.cpp -o gestion_vendedores_ventas
