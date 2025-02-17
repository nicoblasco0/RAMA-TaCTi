#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MIN(X, Y) X <= Y ? X : Y

#define SIN_MEM -1
#define TODO_OK 1

typedef struct sNodo
{
    void* info;
    size_t tamInfo;
    struct sNodo* sig;
}tNodo;

typedef tNodo* tLista;

typedef void (*Funcion)(void* info, void* valor1, void* valor2);
typedef int (*Cmp)(const void* i1, const void* i2);
typedef void (*Actualizar)(void* i1, const void* i2);

void listaCrear(tLista* pl);
void listaVaciar(tLista* pl);
int listaInsertarEnPos(tLista* pl, void* info, size_t tamInfo, int pos);
void listaMap(tLista* pl, Funcion func, void* valor1, void* valor2);
void listaObtenerInfoNodoActual(tLista* pl, void* info, size_t tam);
bool listaPrimerNodo(tLista* listaOriginal, tLista* destino);
bool listaProximoNodo(tLista* pl);
bool listaActualizarNodo(tLista* pl, const void* info, Cmp cmp, Actualizar act);

#endif // LISTA_H_INCLUDED
