#include "tacti.h"

void inicializarTablero(char tablero[][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            tablero[i][j] = ' ';
        }
    }

}


void mostrarTablero(char tab[][3])
{
    int i, j;
    printf("-------------\n");
    for(i = 0 ; i < 3 ; i++)
    {
        printf("|");
        for(j = 0 ; j < 2 ; j++)
        {
            printf(" %c |", tab[i][j]);
        }
        printf(" %c", tab[i][j]);
        printf(" |\n-------------\n");
    }
}

void realizarMovimientoAleatorio(int cantEspaciosVacios, char caracterMaquina, char tablero[][3])
{
    srand(time(NULL));
    int nroCasilleroRand = (rand() % cantEspaciosVacios) + 1;
    int i, j, contadorVacios = 0;

    for(i = 0 ; i < 3 ; i++)
    {
        for(j = 0 ; j < 3 ; j++)
        {
            if(tablero[i][j] == ' ')
            {
                contadorVacios++;
            }

            if(contadorVacios == nroCasilleroRand)
            {
                tablero[i][j] = caracterMaquina;
                return;
            }
        }
    }
}

void realizarMovimientoJugador(char caracterJugador, char tablero[][3])
{
    int nroCasillero, fil, col;

    do{
        printf("\nSeleccione una casilla (1-9) para colocar su ficha (%c).\n", caracterJugador);
        scanf("%d", &nroCasillero);
        nroCasillero -= 1;

        fil = nroCasillero / 3;
        col = nroCasillero % 3;

        if(nroCasillero < 0 || nroCasillero > 8)
            printf("\nCasillero invalido. Recuerde que tiene que encontrarse dentro del rango 1-9.\n");
        else if(tablero[fil][col] != ' ')
            printf("\nCasillero ocupado, seleccione otro.\n");

    }while(nroCasillero < 0 || nroCasillero > 8 || tablero[fil][col] != ' ');

    tablero[fil][col] = caracterJugador;
}

bool chequearPosibilidadVictoria(char tablero[][3], char caracter, char caracterRespuesta)    //Chequea si hay un movimiento ganador y responde con un movimiento
{
    int i, j, z, contHorizontal, contVertical, contDiag, contDiagAlt;
    contDiag = contDiagAlt = 0;

    ///Chequeo rectas
    for(i = 0 ; i < 3 ; i++)
    {
        contHorizontal = contVertical = 0;
        for(j = 0 ; j < 3 ; j++)
        {
            if(tablero[i][j] == caracter)   ///Lo que pense es que se va a ejecutar tras cada movimiento, entonces siempre va a detectar antes de que pase la victoria.
                contHorizontal++;
            else if(tablero[i][j] == ' ')
                contHorizontal += 3;

            if(tablero[j][i] == caracter)
                contVertical++;
            else if(tablero[j][i] == ' ')
                contVertical += 3;
        }

        if(contHorizontal == 5) //Hay un movimiento posible para llegar a las 3 fichas iguales en horizontal en la fila en la que quedo la i.
        {
            for(z = 0 ; z < 3 ; z++) //nos tenemos que fijar cual es la ficha que falta
            {
                if(tablero[i][z] == ' ')///Si hay un vacio le ponemos la ficha deseada para poder responder
                {
                    tablero[i][z] = caracterRespuesta;
                    return true;
                }
            }
        }

        if(contVertical == 5)   //Aplican los mismos comentarios que arriba pero en vertical
        {
            for(z = 0 ; z < 3 ; z++)
            {
                if(tablero[z][i] == ' ')
                {
                    tablero[z][i] = caracterRespuesta;
                    return true;
                }
            }
        }
    }

    ///Chequeo diagonales
    for(i = 0 ; i < 3 ; i++)
    {
        if(tablero[i][i] == caracter)
            contDiag++;
        else if(tablero[i][i] == ' ')
            contDiag += 3;

        if(tablero[i][2-i] == caracter)
            contDiagAlt++;
        else if(tablero[i][2-i] == ' ')
            contDiagAlt += 3;
    }

    if(contDiag == 5)
    {
        for(z = 0 ; z < 3 ; z++)
            {
                if(tablero[z][z] == ' ')
                {
                    tablero[z][z] = caracterRespuesta;
                    return true;
                }
            }
    }

    if(contDiagAlt == 5)
    {
        for(z = 0 ; z < 3 ; z++)
            {
                if(tablero[z][2-z] == ' ')
                {
                    tablero[z][2-z] = caracterRespuesta;
                    return true;
                }
            }
    }

    return false;
}

bool esVictoria(char tablero[][3], char caracter)
{
    int i, j, contHorizontal, contVertical, contDiag, contDiagAlt;
    contDiag = contDiagAlt = 0;

    ///Chequeo rectas
    for(i = 0 ; i < 3 ; i++)
    {
        contHorizontal = contVertical = 0;
        for(j = 0 ; j < 3 ; j++)
        {
            if(tablero[i][j] == caracter)
                contHorizontal++;

            if(tablero[j][i] == caracter)
                contVertical++;

        }

        if(contHorizontal==3 || contVertical==3)
            return true;
    }

    ///Chequeo diagonales
    for(i = 0 ; i < 3 ; i++)
    {
        if(tablero[i][i] == caracter)
            contDiag++;

        if(tablero[i][2-i] == caracter)
            contDiagAlt++;
    }

    if(contDiag == 3 || contDiagAlt == 3)
        return true;



    return false;
}

/*
void imprimirReglas()
{
    printf("Bienvenido a Ta-C-ti!\n");
    printf("Reglas:\n");
    printf("1. Dos jugadores alternan turnos: uno usa 'X' y el otro 'O'.\n");
    printf("2. El objetivo es formar una linea de tres simbolos iguales (horizontal, vertical o diagonal).\n");
    printf("3. Si el tablero se llena sin que nadie forme una linea, el juego termina en empate.\n");
    printf("4. Para jugar, ingresa las coordenadas de la fila y columna donde quieras colocar tu simbolo.\n");
    printf("�Que comience el juego!\n");
}
*/
