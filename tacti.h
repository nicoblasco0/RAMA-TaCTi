#ifndef TACTI_H_INCLUDED
#define TACTI_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void inicializarTablero(char[][3]);
void mostrarTablero(char[][3]);
void realizarMovimientoAleatorio(int cantEspaciosVacios, char caracterMaquina, char tablero[][3]);
void realizarMovimientoJugador(char caracterJugador, char tablero[][3]);
bool chequearPosibilidadVictoria(char tablero[][3], char caracter, char caracterRespuesta);
bool esVictoria(char tablero[][3], char caracter);

#endif // TACTI_H_INCLUDED
