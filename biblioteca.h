#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

// --- CONFIGURACIÓN DEL SISTEMA ---
#define MAX_PRESTAMOS_POR_USUARIO 5
#define MAX_TITULO 100
#define MAX_AUTOR 100
#define MAX_NOMBRE_USUARIO 100

// --- ESTRUCTURAS DE DATOS (TADs) ---

// Cola (para lista de espera)
typedef struct NodoCola {
    int idUsuario;
    struct NodoCola* siguiente;
} ;NodoCola

typedef struct {
    NodoCola *frente, *final;
} Cola;

// Libro
typedef struct {
    int idLibro;
    char titulo[MAX_TITULO];
    char autor[MAX_AUTOR];
    int disponible;
    Cola* listaEspera;
} Libro;

