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

void ingresarJugadoresMezclados(tLista* pl)
{
    Jugador jugador;
    int cont = 1;   //Lo arranco en uno para no dividir por 0 y porque de por si va a dar siempre 0.
    printf("A continuacion ingrese los nombres de los jugadores (Para finalizar la carga de nombres ingrese -1):\n");
    int posIns;
    srand(time(NULL));

    do
    {
        posIns = (rand() % cont);
        scanf("%s", jugador.nombre);
        if(strcmp(jugador.nombre, "-1") != 0)
        {
            listaInsertarEnPos(pl, &jugador, sizeof(Jugador), posIns);
            cont++;
        }

    }while(strcmp(jugador.nombre, "-1") != 0);

}

void mostrarJugador(void* jug, void* punt, void* valor)
{
    bool* p = (bool*)punt;
    Jugador* jugador = (Jugador*)jug;
    printf("%s", jugador->nombre);
    if(*p == true)
        printf(" -> %d", jugador->puntaje);
    printf("\n");
}

int jugarPartidaIndividual()
{
    char tablero[3][3];
    int cantEspaciosVacios, puntaje, indiceFicha;
    bool victoriaJugador, victoriaMaquina;
    char fichaJugador, fichaMaquina;
    char fichas[2];

    fichas[0] = 'X';
    fichas[1] = 'O';

    cantEspaciosVacios = 9;
    victoriaJugador = victoriaMaquina = false;

    srand(time(NULL));

    indiceFicha = rand() % 2;   //Da 0 o 1
    fichaJugador = fichas[indiceFicha];
    fichaMaquina = fichas[1-indiceFicha]; //Garantiza que da el opuesto a la ficha del jugador


    printf("La ficha del jugador es %c y la de la maquina es %c. \nBuena suerte!\n", fichaJugador, fichaMaquina);

    inicializarTablero(tablero);

    if(fichaMaquina == 'X') //Empieza la maquina
    {
        realizarMovimientoAleatorio(cantEspaciosVacios, fichaMaquina, tablero);
        cantEspaciosVacios--;
    }

    mostrarTablero(tablero);



    while(!victoriaJugador && cantEspaciosVacios > 0 && !victoriaMaquina)
    {
        realizarMovimientoJugador(fichaJugador, tablero);
        cantEspaciosVacios--;
        victoriaJugador = esVictoria(tablero, fichaJugador);
        //mostrarTablero(tablero);
        printf("\n");

        if(!victoriaJugador && cantEspaciosVacios > 0)
        {
            if(chequearPosibilidadVictoria(tablero, fichaMaquina, fichaMaquina) == true)
                victoriaMaquina = true;
            else if (chequearPosibilidadVictoria(tablero, fichaJugador, fichaMaquina) == false)
                realizarMovimientoAleatorio(cantEspaciosVacios, fichaMaquina, tablero);

            cantEspaciosVacios--;
            mostrarTablero(tablero);
        }

    }

    if(victoriaJugador == true)
    {
        printf("\nGano el jugador!\n");
        puntaje = 3;
    }

    else if(victoriaMaquina == true)
    {
        printf("\nGano la maquina!\n");
        puntaje = -1;
    }
    else
    {
        printf("\nEmpate!\n");
        puntaje = 2;
    }

    return puntaje;
}

int cmpJugadores(const void* i1, const void* i2)
{
    Jugador* j1, *j2;
    j1 = (Jugador*) i1;
    j2 = (Jugador*) i2;

    return strcmp(j1->nombre, j2->nombre);
}

void actJugadores(void* i1, const void* iAct)
{
    Jugador* jug, *jActualizador;
    jug = (Jugador*) i1;
    jActualizador = (Jugador*) iAct;

    jug->puntaje = jActualizador->puntaje;
}

int jugarPartidaGrupal(tLista* listaJugadores, int cantPartidasPorJugador)
{
    int maxPuntaje = -100; ///Un puntaje que nos aseguremos que nadie llegue (Es irreal que se jueguen 100 partidas por cada jugador.)
    tLista listaIterador;
    bool hayNodo;
    hayNodo = listaPrimerNodo(listaJugadores, &listaIterador);
    if(!hayNodo)
    {
        printf("Lista vacia");
        exit(1);
    }

    int i;
    Jugador aux;

    while(hayNodo)
    {
        listaObtenerInfoNodoActual(&listaIterador, &aux, sizeof(Jugador));
        aux.puntaje = 0;
        printf("\nJugador %s, es su turno.\n", aux.nombre);
        for(i = 0 ; i < cantPartidasPorJugador ; i++)
        {
            printf("\nPartida n%d:\n", i+1);
            aux.puntaje += jugarPartidaIndividual();
        }

        if(aux.puntaje > maxPuntaje)   ///Guardamos el mayor puntaje para retornarlo y usarlo en otras funciones.
            maxPuntaje = aux.puntaje;

        printf("\n%s, tu puntaje fue %d\n\n", aux.nombre, aux.puntaje);

        listaActualizarNodo(listaJugadores, &aux, cmpJugadores, actJugadores);
        hayNodo = listaProximoNodo(&listaIterador);
    }

    return maxPuntaje;
}

int leerConfigJuego(Cfg* cfg, char* nomArchivoCfg)
{
    FILE* fp = fopen(nomArchivoCfg, "rt");
    if(!fp)
        return ERR_ARCH;

    fscanf(fp, "%s | %s\n\n", cfg->urlApi, cfg->codGrupo);
    fscanf(fp, "%d", &cfg->cantPartidas);

    return TODO_OK;
}

void agregarJugadorAInforme(void* j, void* fp, void* valor)
{
    Jugador* jug;
    jug = (Jugador*)j;

    FILE* pInforme = (FILE*)fp;

    fprintf(pInforme, "%-31s %-3d\n", jug->nombre, jug->puntaje);

}

void agregarGanadorAInforme(void* j, void* fp, void* valor)
{
    Jugador* jug;
    jug = (Jugador*)j;

    int maxPuntaje = *((int*)valor);
    FILE* pInforme = (FILE*)fp;

    if(jug->puntaje == maxPuntaje)
        fprintf(pInforme, "%s\n", jug->nombre);
}

int generarInforme(tLista* listaJugadores, int maxPuntaje)
{
    char nomArch[100] = "informe-juego_";
    char fechaStr[20];

    time_t t = time(NULL);
    struct tm fecha = *localtime(&t);

    strftime(fechaStr, sizeof(fechaStr), "%Y-%m-%d-%H-%M", &fecha);

    strcat(nomArch, fechaStr);
    strcat(nomArch, ".txt");

    FILE* pInforme = fopen(nomArch, "wt");
    if(!pInforme)
        return ERR_ARCH;

    fprintf(pInforme, "\nCon %d puntos, el/los ganador/es de esta partida es/son:\n", maxPuntaje);

    listaMap(listaJugadores, agregarGanadorAInforme, pInforme, &maxPuntaje);

    fprintf(pInforme, "\nTabla General de jugadores\n\n%-31s %-8s\n", "Puntaje", "Jugador");

    listaMap(listaJugadores, agregarJugadorAInforme, pInforme, NULL);



    fclose(pInforme);


    return TODO_OK;
}

void verRankingEquipo(char* urlApi, char* codEquipo)
{
    CURL *curl;
    CURLcode res;

    // Construimos la URL con el código del equipo
    char urlCompleta[512];
    snprintf(urlCompleta, sizeof(urlCompleta), "%s/%s", urlApi, codEquipo);

    curl = curl_easy_init();
    if (curl) {
        // Configurar la solicitud GET
        curl_easy_setopt(curl, CURLOPT_URL, urlCompleta);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback); // Para manejar la respuesta
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L); // Desactivar verificación SSL (opcional)

        // Ejecutar la solicitud
        res = curl_easy_perform(curl);

        // Verificar errores
        if (res != CURLE_OK)
            fprintf(stderr, "Error en la solicitud: %s\n", curl_easy_strerror(res));

        // Liberamos recursos
        curl_easy_cleanup(curl);
    }
}

void listaJugadoresAJson(tLista* listaJug, char* jsonJug)
{
    char fragmentoJsonJugador[64];
    tLista listaIterador;
    bool hayNodo;
    hayNodo = listaPrimerNodo(listaJug, &listaIterador);
    Jugador aux;
    while(hayNodo)
    {
        listaObtenerInfoNodoActual(&listaIterador, &aux, sizeof(Jugador));


        sprintf(fragmentoJsonJugador, "{ \"nombre\": \"%s\", \"puntos\":\"%d\"}", aux.nombre, aux.puntaje);
        strcat(jsonJug, fragmentoJsonJugador);


        hayNodo = listaProximoNodo(&listaIterador);
        if(hayNodo)
            strcat(jsonJug, ", ");
    }

}

int postListaDeJugadores(tLista* listaJugadores, char* urlApi, char* codEquipo)
{
    CURL *curl;
    CURLcode res;

    char jsonJugadores[1024];
    sprintf(jsonJugadores, "{ \"CodigoGrupo\": \"%s\",\"Jugadores\": [", codEquipo);
    listaJugadoresAJson(listaJugadores, jsonJugadores);
    strcat(jsonJugadores, "]}");

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

     if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);


        // Configurar la URL
        curl_easy_setopt(curl, CURLOPT_URL, urlApi);

        // Indicar que es un POST
        curl_easy_setopt(curl, CURLOPT_POST, 1L);

        // Definir los headers
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        // Enviar el JSON en el cuerpo de la solicitud
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonJugadores);

        // Ejecutar la solicitud
        res = curl_easy_perform(curl);

        // Verificar respuesta
        if (res != CURLE_OK) {
            fprintf(stderr, "Error en POST: %s\n", curl_easy_strerror(res));
        }

        // Liberar recursos
        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return (res == CURLE_OK) ? TODO_OK : -10;
}

int menu()
{
    char input;
    tLista listaJugadores;
    bool mostrarPuntaje = false;    ///Sirve para manejar la funcion mostrarJugador (true indica que mostrara el puntaje y viceversa)
    Cfg configPartida;
    int cod, maxPunt;

    cod = leerConfigJuego(&configPartida, nomArchCfg);
    if(cod != TODO_OK)
        return cod;

    printf("[A] Jugar\n[B] Ver ranking equipo\n[C] Salir\n\n");

    do
    {
        scanf("%c", &input);

        if(input != 'A' && input != 'B' && input != 'C')
        {
            printf("\nOpcion invalida, elija una de las mencionadas.\n");
            fflush(stdin);
        }

    }while(input != 'A' && input != 'B' && input != 'C');


    switch(input)
    {
        case 'A':
            listaCrear(&listaJugadores);

            ingresarJugadoresMezclados(&listaJugadores);

            if(listaJugadores == NULL)
                return LISTA_VACIA;

            printf("\nEl orden de los jugadores sera el siguiente:\n");
            listaMap(&listaJugadores, mostrarJugador, &mostrarPuntaje, NULL);

            maxPunt = jugarPartidaGrupal(&listaJugadores, configPartida.cantPartidas);

            mostrarPuntaje = true;
            listaMap(&listaJugadores, mostrarJugador, &mostrarPuntaje, NULL);
            printf("\n");

            ///Generar informe y enviar data a la API.
            cod = generarInforme(&listaJugadores, maxPunt);
            if(cod != TODO_OK)
                return cod;

            cod = postListaDeJugadores(&listaJugadores, configPartida.urlApi, configPartida.codGrupo);
            if(cod != TODO_OK)
                return cod;

            listaVaciar(&listaJugadores);
            fflush(stdin);
            break;
        case 'B':
            printf("\nRanking del equipo (.json):\n");
            verRankingEquipo(configPartida.urlApi, configPartida.codGrupo);
            printf("\n\n");
            fflush(stdin);
            break;
        case 'C':
            return FINALIZAR_PROGRAMA;
    }

    return TODO_OK;
}
