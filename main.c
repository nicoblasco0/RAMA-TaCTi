#include "tacti.h"

int main()
{
    int cod = 0;
    while(cod != FINALIZAR_PROGRAMA)
    {
        cod = menu();
        if(cod == LISTA_VACIA)
        {
            printf("\nNo ha ingresado ningun jugador a la lista, por lo tanto se lo devolvera al menu.\n\n");
            fflush(stdin);
        }else if(cod == ERR_ARCH || cod == SIN_MEM)
            exit(cod);
    }

    return TODO_OK;
}
