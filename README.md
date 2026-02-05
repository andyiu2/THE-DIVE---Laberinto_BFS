<img width="280" height="260" alt="image" src="https://upload.wikimedia.org/wikipedia/commons/f/f5/BFS-Algorithm_Search_Way.gif" />


🧩 Generador y Solucionador de Laberintos en C++
================================================

📌 Descripción
--------------

Este proyecto implementa un **generador de laberintos perfectos** y un **algoritmo para resolverlos**, utilizando estructuras de datos clásicas y técnicas fundamentales de programación.

-   El laberinto se genera usando **DFS (Depth-First Search) con backtracking**.

-   El camino de solución se encuentra usando **BFS (Breadth-First Search)**, garantizando el camino más corto.

-   El resultado se muestra por consola en formato ASCII.

Es un proyecto orientado a practicar:

-   Algoritmos de búsqueda

-   Manejo de memoria dinámica

-   Uso de `stack`, `queue` y `vector`

-   Trabajo con matrices dinámicas

* * * * *

🧠 Algoritmos utilizados
------------------------

### Generación del laberinto

-   **DFS con backtracking**

-   Se parte de una matriz llena de paredes.

-   Se avanza de dos en dos para mantener paredes entre caminos.

-   Se eliminan paredes para crear pasillos conectados.

-   El resultado es un **laberinto perfecto** (un único camino entre dos puntos).

### Resolución del laberinto

-   **BFS**

-   Explora el laberinto por niveles.

-   Guarda el "padre" de cada celda visitada.

-   Reconstruye el camino mínimo desde la salida hasta la entrada.

* * * * *

🧱 Representación del laberinto
-------------------------------

| Símbolo | Significado |
| --- | --- |
| `##` | Pared |
| Espacio | Camino libre |
| `EE` | Entrada |
| `SS` | Salida |
| `.` | Camino solución |

* * * * *

⚙️ Compilación y ejecución
--------------------------

`g++ laberinto.cpp -o laberinto
./laberinto`

> El tamaño del laberinto está definido directamente en el código (`filas` y `columnas`).

* * * * *

📁 Estructura del código
------------------------

-   `generarLaberinto()`\
    Crea el laberinto usando DFS y backtracking.

-   `resolverLaberinto()`\
    Encuentra el camino mínimo usando BFS.

-   `imprimirLaberinto()`\
    Muestra el laberinto y la solución por consola.

-   `liberarLaberinto()`\
    Libera la memoria dinámica utilizada.

* * * * *

📚 Conceptos aplicados
----------------------

-   Matrices dinámicas con punteros dobles (`int**`)

-   Algoritmos DFS y BFS

-   Pilas (`stack`) y colas (`queue`)

-   Vectores y pares (`vector`, `pair`)

-   Semillas aleatorias (`srand`, `rand`)

-   Reconstrucción de caminos usando padres

* * * * *

🚀 Posibles mejoras futuras
---------------------------

-   Permitir que el usuario ingrese el tamaño del laberinto.

-   Agregar interfaz gráfica.

-   Mostrar animación paso a paso del BFS.

-   Guardar el laberinto en un archivo.
