#include "lista.h"

void listaCrear(tLista* pl)
{
    *pl = NULL;
}

void listaVaciar(tLista* pl)
{
    tLista* aux = pl;

    while(*pl != NULL)
    {
        free((*pl)->info);
        (*pl) = (*pl)->sig;
    }

    *aux = NULL;
}

int listaInsertarEnPos(tLista* pl, void* info, size_t tamInfo, int pos)
{
    int posAct = 0;
    tNodo* nue;

    while(*pl != NULL && posAct < pos)
    {
        pl = &((*pl)->sig);
        posAct++;
    }
    nue = malloc(sizeof(tNodo));
    if(!nue)
        return SIN_MEM;

    nue->info = malloc(tamInfo);
    if(!(nue->info))
    {
        free(nue);
        return SIN_MEM;
    }

    memcpy(nue->info, info, tamInfo);

    //Agregamos el nodo a la lista
    nue->sig = (*pl);
    *pl = nue;

    return TODO_OK;
}

void listaMap(tLista* pl, Funcion func, void* valor1, void* valor2)
{

    while(*pl != NULL)
    {
        func((*pl)->info, valor1, valor2);
        pl = &((*pl)->sig);
    }
}

void listaObtenerInfoNodoActual(tLista* pl, void* info, size_t tam)
{
    memcpy(info, (*pl)->info, MIN(tam, (*pl)->tamInfo));
}

bool listaPrimerNodo(tLista* listaOriginal, tLista* destino)
{
    if(*listaOriginal != NULL)
    {
       *destino = *listaOriginal;
       return true;
    }

    return false;
}

bool listaProximoNodo(tLista* pl)
{
    *pl = (*pl)->sig;

    if(*pl != NULL)
        return true;

    return false;
}

bool listaActualizarNodo(tLista* pl, const void* info, Cmp cmp, Actualizar act)
{
    while(*pl != NULL && cmp((*pl)->info, info) != 0 )
        pl = &((*pl)->sig);

    if(cmp((*pl)->info, info) == 0)
    {
        act((*pl)->info, info);
        return true;
    }

    return false;
}
