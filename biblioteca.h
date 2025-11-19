#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 100

// Cola (lista de espera)

typedef struct nodo{
    int idUsuario;
    struct nodo* siguiente;
} tNodo;

typedef struct{
    tNodo* principio;
    tNodo* final;
}tCola;

// Libros

typedef struct {
    int idLibro;
    char titulo[MAX];
    char autor[MAX];
    int disponible; // 1 = disponible, 0 = prestado
    tCola* listaEspera; // Puntero a la cola de espera
} tLibro;

//Arbol Binario de Busqueda (para los libros) 

typedef struct nodoArbol{
    tLibro libro;
    struct nodoArbol* izquierda;
    struct nodoArbol* derecha;
} tNodoArbol;

//Lista enlazada (para los libros prestados a un usuarios)

typedef struct nodoLibro{
    int idLibro;
    struct nodoLibro* siguiente;
} tNodoLibro;

// Usuarios

 typedef struct {
    int idUsuario;
    char nombre[MAX];
    tNodoLibro* librosPrestados; // Lista enlazada de libros prestados
 } tUsuario;

typedef struct nodoUsuario{
    tUsuario usuario;
    struct nodoUsuario* siguiente;
}tNodoUsuario;
 
// Funciones de la cola

void inicializarCola(tCola* cola); 
bool estaVacia(tCola* cola);
void encolar(tCola* cola, int idUsuario);
int desencolar(tCola* cola);
int frente(tCola* cola);

// Funciones del arbol binario

tNodoArbol* crearNodoArbol(tLibro libro);
tNodoArbol* insertarLibro(tNodoArbol* raiz, tLibro libro);
tNodoArbol* buscarLibro(tNodoArbol* raiz, int idLibro);
void liberarArbol(tNodoArbol* raiz);

// Funciones de la lista enlazada de libros prestados

void agregarLibroPrestado(tUsuario* usuario, int idLibro);
bool quitarLibroPrestado(tUsuario* usuario, int idLibro);
bool tieneLibroPrestado(tUsuario* usuario, int idLibro);
void liberarLibrosPrestados(tUsuario* usuario);

// Funciones de gestion de usuarios

tNodoUsuario* crearNodoUsuario(tUsuario usuario);
tNodoUsuario* insertarUsuario(tNodoUsuario* cabeza, tUsuario usuario);
tNodoUsuario* buscarUsuario(tNodoUsuario* cabeza, int idUsuario);
void liberarUsuarios(tNodoUsuario* cabeza);

// Funciones de gestion de la biblioteca

bool prestarLibro(tNodoArbol* raizLibros, tNodoUsuario* cabezaUsuarios,
                     int idLibro, int idUsuario);
bool devolverLibro(tNodoArbol* raizLibros, tNodoUsuario* cabezaUsuarios,
                        int idLibro, int idUsuario);
void liberarBiblioteca(tNodoArbol* raizLibros, tNodoUsuario* cabezaUsuarios);

// Funciones auxiliares

void inicializarBiblioteca(tNodoArbol** raizLibros, tNodoUsuario** cabeza
                        );
void mostrarLibro(tLibro libro);
void mostrarUsuario(tUsuario usuario);



// IMPLEMENTACION DE FUNCIONES

void inicializarCola(tCola** pCola){
    *pCola = (tCola*)malloc(sizeof(tCola));
    (*pCola)->principio = NULL;
    (*pCola)->final = NULL;
    printf("Cola inicializada\n");
}

bool estaVacia(tCola* cola){
    return (pCola->principio == NULL);
}

void encolar(tCola* pCola, int idUsuario){
    tNodo* nuevoNodo = (tNodo*)malloc(sizeof(tNodo));
    nuevoNodo->idUsuario = idUsuario;
    nuevoNodo->siguiente = NULL;
    if (estaVacia(pCola)){
        pCola->principio = nuevoNodo;
        pCola->final = nuevoNodo;
    } else {
        pCola->final->siguiente = nuevoNodo;
        pCola->final = nuevoNodo;
    }
}

int desencolar(tCola* pCola){
    if (estaVacia(pCola)){
        printf("Error: Cola vacia\n");
        return -1; // Valor de error
    }
    tNodo* nodoDesencolado = pCola->principio;
    int idUsuario = nodoDesencolado->idUsuario;
    pCola->principio = pCola->principio->siguiente;
    if (pCola->principio == NULL){
        pCola->final = NULL;
    }
    free(nodoDesencolado);
    return idUsuario;
}

int frente(tCola* pCola){
    if (estaVacia(pCola)){
        printf("Error: Cola vacia\n");
        return -1; // Valor de error
    }
    return pCola->principio->idUsuario;
}

