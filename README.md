<div align="center">
  <img src="https://www.unne.edu.ar/wp-content/uploads/Logo-UNNE-Angosto.png" width="150" />
  
  # Trabajo integrados | Sistema de gestion para Biblioteca
  
  ### Asignatura: Algoritos y Estructuras de datos II
  
  <br>
</div>

---

### Información del Equipo

| Rol | Nombre y Apellido | DNI/LU | DNI/LU |
| :--- | :--- | :--- | :--- |
| **Integrante 1** | Romani, Valentinoo| 46.881.963 | - |
| **Integrante 2** | Stoppello, M. Agustin | 46.316.920 | 60.122 |

### Docentes Responsables
| Rol | Nombre y Apellido |
| :--- | :--- |
| **Profesora** | Armana,Silvana 
| **Profesor** | Princich, Fernando

---

## 📑 Índice de Contenidos

1. [Introducción](#1-introducción)
2. [Características](#-características)
3. [Descripción del Proyecto](#descripción-del-proyecto)
4. [Planificación del Proyecto](#planificación-del-proyecto)
    * [Etapa 1: TAD biblioteca.h](#etapa-1-tad-biblioteca.h)
    * [Etapa 2: Programa Principal](#etapa-2-programa-principal)
5. [Conclusiones](#conclusiones)
---
---


### 1. Introducción
El sistema permite administrar un catálogo de libros, registrar usuarios y gestionar el préstamo y la devolución de libros, utilizando múltiples estructuras de datos combinadas.

## 📚 Características

* **Gestión de Libros:** Agregar nuevos libros al catálogo.
* **Gestión de Usuarios:** Registrar nuevos usuarios en el sistema.
* **Préstamos:** Permitir a un usuario tomar prestado un libro. Si el libro no está disponible, el usuario se añade a una **lista de espera**.
* **Devoluciones:** Registrar la devolución de un libro. Si hay usuarios en lista de espera, el libro se asigna automáticamente al siguiente en la cola.
* **Consultas:** Mostrar el catálogo completo de libros y la lista de usuarios con sus préstamos actuales.
* **Persistencia:** Guardar y cargar automáticamente el estado de la biblioteca (libros y usuarios) en archivos binarios.

### **Descripción Del Proyecto:** 

El Sistema de gestión de Biblioteca permite al bibliotecario gestionar a los usuarios y a los libros. La administración del catálogo de los libros utiliza árbol binario de búsqueda para un consulta rápida, por otro lado para el registro de los usuarios se utiliza lista enlazada. El sistema le permite al bibliotecario realizar préstamos, devoluciones y a su vez guardar toda la información (libros y usuarios) en un archivo binario para asegurar la persistencia de los datos entre ejecuciones.

### **Planificación del Proyecto:**

El proyecto cuenta con dos códigos en el repositorio “sistema.c” y “biblioteca.h” . El archivo “biblioteca.h” contiene las estructuras de datos (Árboles y Listas) y la lógica de negocio, como insertar libros, registrar usuarios, realizar préstamos y manejar archivos. El archivo “sistema.c”  contendrá el menú interactivo que será impreso en el CMD.

**Etapa 1: TAD “biblioteca.h”**

**Parte 1: Bibliotecas, Constantes, Variables y Tipos utilizados:**

**Bibliotecas Utilizadas**:
```
#include <stdio.h>
#include<stdlib.h>
#include <string.h>

#define MAX 100
```
### **Tipos de Datos Compuestos Utilizados:**

1) #### **Tipo Nodo Libro (Libro prestados):** 

```
typedef struct nodoLibro {
    int idLibro;
    struct nodoLibro* siguiente;
} tNodoLibro;
```
Es una estructura de lista enlazada simple que almacena los IDs de los libros que un usuario tiene actualmente prestados.

2) #### **Tipo Usuario y Nodo Usuario:**

```   
typedef struct {
    int idUsuario;
    char nombre[MAX];
    tNodoLibro* librosPrestados; // Lista enlazada de libros que tiene el suario
} tUsuario;

typedef struct nodoUsuario {
    tUsuario usuario; //datos
    struct nodoUsuario* siguiente;
} tNodoUsuario;
```
La estructura **tUsuario** contiene los datos del usuario y un puntero a la cabecera de su lista personal de libros prestados. **tNodoUsuario** forma la lista general de todos los usuarios registrados en el sistema.

#### **3\) Tipo Libro y Nodo Árbol (Catálogo):**
```
typedef struct {
    int idLibro;
    char titulo[MAX];
    char autor[MAX];
    int disponible; // 1 = Disponible, 0 = Prestado
} tLibro;

// Arbol Binario para mostrar libros (catalogo)

typedef struct nodoArbol {
    tLibro libro;
    struct nodoArbol* izquierda;
    struct nodoArbol* derecha;
} tNodoArbol;
```

**tLibro** es un registro con los metadatos del libro y marca la disponibilidad. **tNodoArbol** es la estructura recursiva para crear el Árbol Binario de Búsqueda, ordenado por **idLibro**.

### **Parte 2: Funciones.**

Una aclaración antes, en el presente informe no se mostrará el código completo de las funciones, debido a lo extenso que resultaría colocarlo, perjudicando la lectura del informe. Por lo tanto, se nombrará el prototipo de la función con sus parámetros, para luego explicar en lenguaje coloquial, su funcionamiento.

1)  **Funciones de Préstamo de libros**
   ```
//Libros prestados

void agregarLibroPrestado(tUsuario*, int);
int quitarLibroPrestado(tUsuario*, int);
```

La función de **agregarLibroPrestado** agrega un libro a la lista personal de un usuario reserva memoria para un nuevo nodo de libro, asigna el ID recibido y realiza una inserción al principio de la lista enlazada **librosPrestados** del usuario.

Por otro lado, la función **quitarLibroPrestado** elimina un libro de la lista del usuario cuando este lo devuelve recorre la lista enlazada buscando el nodo con el **idLibro** correspondiente. Si lo encuentra, actualiza los punteros para "saltar" ese nodo y libera la memoria con free. Retorna 1 si tuvo éxito, 0 si no lo encontró.

2)  **Funciones de Catálogo de Libros**
```
   //Catalogo

tNodoArbol* insertarLibro(tNodoArbol*, tLibro);
tNodoArbol* buscarLibro(tNodoArbol*, int);
void mostrarCatalogo(tNodoArbol*);
  ``` 

La función **insertarLibro** se trata de una función recursiva para agregar un libro al catálogo; si la raíz es NULL, crea un nuevo nodo. Si no, compara el ID del libro con el de la raíz actual: si es menor, llama recursivamente hacia la izquierda; si es mayor, hacia la derecha. Esto mantiene el árbol ordenado.  
La función **buscarLibro** realiza un recorrido "In-Order" del árbol para mostrar los libros ordenados por ID si el nodo no es nulo, se llama a sí misma para el subárbol izquierdo, luego imprime los datos del libro actual (indicando si está "DISPONIBLE" o "PRESTADO"), y finalmente llama al subárbol derecho.  
 

3)  **Persistencia (Archivos):**
   ```
//Persistencia

void guardarTodo(tNodoArbol*, tNodoUsuario*);
void cargarTodo(tNodoArbol**, tNodoUsuario**);

```

La función **guardarTodo** guarda el estado actual del sistema en archivos binarios.

1. Abre "**libros.dat**" en modo escritura binaria y utiliza una función auxiliar recursiva (**guardarLibrosRec**) para recorrer el árbol y escribir cada estructura **tLibro** en el archivo.

   

2. Abre "**usuarios.dat**". Recorre la lista de usuarios. Por cada uno, guarda su estructura base, luego cuenta cuántos libros tiene prestados, guarda ese número (cantidad), y posteriormente guarda los IDs de esos libros uno por uno.

Mientras que la función **cargarTodo** restaura el estado del sistema al iniciar lee "**libros.dat**" y reconstruye el árbol insertando nodo por nodo. Luego lee "**usuarios.dat**"; por cada usuario lee sus datos básicos, lee la cantidad de libros prestados y mediante un bucle for recupera los IDs de los libros y reconstruye su lista enlazada interna.

4) **Funciones de Usuario**
```
//Funciones de usuarios

tNodoUsuario* insertarUsuario(tNodoUsuario*, tUsuario);
tNodoUsuario* buscarUsuario(tNodoUsuario*, int);
void mostrarUsuarios(tNodoUsuario*);
```
Conjunto de funciones que permiten al bibliotecario ingresar un nuevo usuario a la lista, buscar un usuario por su id y mostrar los usuarios cargados en el sistema hasta el momento. Para ingresar un usuario, se agrega el usuario al comienzo de la lista, inicializando su lista de **librosPrestados** en NULL. En el caso de la busqueda de usuarios,  el sistema recorre linealmente la lista de usuarios 

comparando IDs y retorna el nodo del usuario, o NULL si no lo encuentra. Por último, para mostrar la lista de usuarios  el sistema recorre la lista de usuarios e imprime sus datos, a su vez recorriendo la sub.lista de **librosPrestados** por cada usuario. 

### **Etapa 2: Programa Principal**

**Parte 1: Variables y Tipos utilizados:**
```
int main() {
    tNodoArbol* arbolLibros = NULL;
    tNodoUsuario* listaUsuarios = NULL;
    int opcion, idLibro, idUsuario;
```

En el **main**, se declaran las estructuras principales que mantendrán los datos en memoria durante la ejecución:

Se llama inmediatamente a **cargarTodo** para recuperar datos previos.

**Parte 2: Bucle de Ejecución:**

El programa utiliza un bucle do-while que muestra un menú de opciones hasta que el usuario elija salir (opción 7).

Menú:

1. Agregar Usuario: Solicita ID y nombre (usando fgets para permitir espacios) e invoca **insertarUsuario**. Valida que el ID no exista previamente.

2. Agregar Libro: Solicita metadatos e invoca **insertarLibro**.  
3. Prestar Libro: Solicita IDs de libro y usuario, invoca **prestarLibro**.  
4. Devolver Libro: Solicita IDs, invoca **devolverLibro**.  
5. Mostrar Catálogo: Muestra todos los libros ordenados.  
6. Mostrar Usuarios: Muestra lista de usuarios y qué libros tienen en su poder.  
7. Guardar y Salir: Invoca **guardarTodo** y termina el programa.

**Ejecución**:

Al iniciar, se cargan los datos. El usuario interactúa ingresando números enteros para seleccionar opciones. Es importante destacar el uso de **fflush(stdin)** y la limpieza del salto de línea **\\n** después de usar **fgets** para evitar errores en la lectura de cadenas de texto (nombres y títulos).

**Conclusiones:**

Este proyecto resultó muy enriquecedor para nosotros y sirvió como una aproximación práctica a la resolución de problemas reales implementando diferentes estructuras de datos, ya que el proyecto integra árbol binario para los libros y lista enlazada para los usuarios para flexibilizar un sistema por DNI.

No obstante, uno de los principales desafíos que enfrentamos como equipo fue la gestión del tiempo y comprensión de los algoritmos implementados. Para poder sobrellevar dichos obstáculos, consultamos reiteradas veces el material teórico y prácticas de clase, así como también nos apoyamos en  la herramienta de la inteligencia artificial para la depuración de errores en el código. 
