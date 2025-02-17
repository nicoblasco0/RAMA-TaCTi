#ifndef TACTI_H_INCLUDED
#define TACTI_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "lista.h"
#include "api.h"

#define nomArchCfg "tactiConfig.txt"
#define ERR_ARCH -2
#define FINALIZAR_PROGRAMA -10
#define LISTA_VACIA -3

typedef struct
{
    char nombre[31];
    int puntaje;
}Jugador;

typedef struct
{
    char urlApi[101];
    char codGrupo[11];
    int cantPartidas;
}Cfg;

void inicializarTablero(char[][3]);
void mostrarTablero(char[][3]);
void realizarMovimientoAleatorio(int cantEspaciosVacios, char caracterMaquina, char tablero[][3]);
void realizarMovimientoJugador(char caracterJugador, char tablero[][3]);
bool chequearPosibilidadVictoria(char tablero[][3], char caracter, char caracterRespuesta);
bool esVictoria(char tablero[][3], char caracter);
void ingresarJugadoresMezclados(tLista* pl);
void mostrarJugador(void* jug, void* punt, void* valor);
int jugarPartidaIndividual();
int cmpJugadores(const void* i1, const void* i2);
void actJugadores(void* i1, const void* iAct);
int jugarPartidaGrupal(tLista* listaJugadores, int cantPartidasPorJugador);
int leerConfigJuego(Cfg* cfg, char* nomArchivoCfg);
void agregarJugadorAInforme(void* j, void* fp, void* valor);
void agregarGanadorAInforme(void* j, void* fp, void* valor);
int generarInforme(tLista* listaJugadores, int maxPuntaje);
void verRankingEquipo(char* urlApi, char* codEquipo);
void listaJugadoresAJson(tLista* listaJug, char* jsonJug);
int postListaDeJugadores(tLista* listaJugadores, char* urlApi, char* codEquipo);
int menu();

#endif // TACTI_H_INCLUDED
