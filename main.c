#include "tacti.h"

int main()
{
    char tablero[3][3];
    int cantEspaciosVacios;
    bool victoriaJugador, victoriaMaquina;

    cantEspaciosVacios = 9;
    victoriaJugador = victoriaMaquina = false;


    ///*Leer* Todavia no hice para poner random la ficha, por ahora la persona empieza y es la X y la maquina es O.

    inicializarTablero(tablero);
    mostrarTablero(tablero);

    while(!victoriaJugador && cantEspaciosVacios > 0 && !victoriaMaquina)
    {
        realizarMovimientoJugador('X', tablero);
        cantEspaciosVacios--;
        victoriaJugador = esVictoria(tablero, 'X');
        mostrarTablero(tablero);

        if(!victoriaJugador && cantEspaciosVacios > 0)
        {
            if(chequearPosibilidadVictoria(tablero, 'O', 'O') == true)
                victoriaMaquina = true;
            else if (chequearPosibilidadVictoria(tablero, 'X', 'O') == false)
                realizarMovimientoAleatorio(cantEspaciosVacios, 'O', tablero);

            cantEspaciosVacios--;
            mostrarTablero(tablero);
        }

    }

    if(victoriaJugador == true)
        printf("\nGano el jugador!\n");
    else if(victoriaMaquina == true)
        printf("\nGano la maquina!\n");
    else
        printf("\nEmpate!\n");

    return 0;
}
