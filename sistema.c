#include <stdio.h>
#include <stdlib.h>
//#include <stbool.h>
#include <string.h>

/* Parte TAD */

//Cola 
typedef struct NodoCola {
    int idUsuario; //
    struct NodoCola* siguiente;
}tNodoCola;

typedef struct {
    NodoCola *frente, *final;
}tCola;

//Libros
typedef struct {
    long long code;
    char titulo[100];
    char autor[100];
    int disponible; // 1 = disponible, 0 = prestado
    Cola* listaEspera; // Cola de IDs de usuarios esperando por este libro
}tLibro;
