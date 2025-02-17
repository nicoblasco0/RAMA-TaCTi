# <ins>***TaCTi***</ins>
Este programa es un clásico juego de la infancia, el Ta-Te-Ti, implementado en C, hecho para jugar contra la maquina, pero en grupo. La finalidad es competir contra tus compañeros, buscando ser el que mejor performance de a traves de las partidas.

Lo primero que verá el usuario es un menú que permite 3 funciones:

### **\[A\] Jugar**
La funcionalidad mas importante del programa, nos solicitara los nombres de los jugadores para asociarlos a su puntaje y asi poder determinar quien ganó la partida. Tras ingresar uno debemos presionar enter para ingresar el proximo, cuando no querramos ingresar mas, ingresamos un '-1'.

Cada jugador disputará N partidas contra la maquina, siendo N modificable por el propio usuario. (referirse a seccion de "Configuración").

Tras finalizar el ingreso de jugadores de forma exitosa, se procederán a jugar las partidas, siendo el orden de juego completamente aleaorio (no necesariamente arranca el primer jugador que enlistamos).

Recordando el clásico juego, el jugador puede ser la 'X' o la 'O', en esta implementación esto es aleatoria la ficha a utilizar, siendo si certero que quien tenga la ficha 'X' (sea la máquina o el jugador) comenzará la partida.

Tabla de puntajes:

| Resultado de partida | Puntos |
|         :---:        | :---: |
| Victoria             |+3     |
| Empate             |+2     |
| Derrota             |-1     |

Cada jugador, tras finalizar sus N partidas, podrá ver su puntaje, y tras la finalización de todas las partidas de todos los jugadores, se podrá ver como quedaron los puntos de cada jugador.

También se generará un informe con los datos de la partida con la finalidad de entrenar posteriormente a la IA. Estos se pueden encontrar en la carpeta del proyecto bajo el nombre de informe-juego_YYYY-MM-DD-HH-mm.txt, esto nos permite identificar univocamente la partida a través de la fecha y horario. Además se enviara la información del puntaje de cada jugador a una API, pudiendo ser acumulados si posteriormente juega devuelta.

------

### **\[B\] Ver ranking equipo**
Todos los jugadores que jueguen con este programa pertenecen al equipo RAMAL por defecto. Esta función solicita la información de todos los jugadores del equipo a la API ya mencionada, devolviendo su nombre, puntuación y fecha de ultima partida en formato JSON.

------

### **\[C\] Salir**
Nos permite finalizar el programa.

------

### <ins>*Configuración*</ins>
Es posible cambiar ciertos parametros del juego, a través del archivo *tactiConfig.txt*.
Este tiene el siguiente formato:



UrlApi | Codigo del equipo

nro "N" (partidas por jugador)


Para asegurar la funcionalidad del programa procure solo modificar el nro N, a menos que planee cambiar de API. La API actual solo acepta equipos registrados.

------
### DOCUMENTACIÓN DE CASOS DE PRUEBA
| Nro. | Descripción | Salida esperada | Salida obtenida |
| :---:| :---: | :---: | :---: |
| 1 | Hay un movimiento ganador para la maquina |La maquina lo detecta y pone su ficha, concluyendo la partida a su favor|Correcta, https://ibb.co/chycWWB0|
| 2 | Hay un movimiento ganador para el jugador|La maquina lo detecta y pone su ficha, anulando la victoria del jugador|Correcta, https://ibb.co/7xpbHPC4|
| 3 | El jugador gana |Se muestra mensaje correspondiente|Correcta, https://ibb.co/x8HD62Gy|
| 4 | El jugador pierde|Se muestra mensaje correspondiente|Correcta, https://ibb.co/PZMvZNzv|
| 5 | El jugador empata|Se muestra mensaje correspondiente|Correcta, https://ibb.co/ZRM737M8|
| 6 | Se presiona B en el menú |El programa muestra el JSON de jugadores|Correcta, https://ibb.co/v6D0p1c2|
| 7 | Se presiona C|Finaliza el programa|Correcta, https://ibb.co/mCw2xrdz|
| 8 | Se coloca '-1' sin colocar ningun nombre| El programa se da cuenta y nos muestra un mensaje |Correcta, https://ibb.co/RkppLBwr|
| 9 | Se coloca una ficha en un casillero ocupado| El programa se da cuenta y nos muestra un mensaje |Correcta, https://ibb.co/H3Kb5tT|
| 10 | Se finaliza la carga de nombres| El programa nos muestra la lista ya mezclada |Correcta, https://ibb.co/v4kg334Q|
| 11 | Terminan las N partidas del jugador| El programa nos muestra su puntaje final |Correcta, https://ibb.co/N6N39dkN|
| 12 | Terminan las N partidas de TODOS los jugadores |El programa nos muestra el puntaje de cada uno |Correcta, https://ibb.co/3yJRMPf6|
| 13 | Se ingresa una opción no contemplada en el menú |El programa nos lo notificá solicitando una opción válida |Correcta, https://ibb.co/mCw2xrdz|

------
### Capturas como imagen
<ins>CAPTURA 1</ins>

![1](https://github.com/user-attachments/assets/5c7314ab-c20b-4b9c-8073-6cc9aa241b13)

<ins>CAPTURA 2</ins>

![2](https://github.com/user-attachments/assets/ef0b8dea-ab7f-4362-bf7f-af78d2b42256)

<ins>CAPTURA 3</ins>

![3](https://github.com/user-attachments/assets/376edbc8-a755-4149-8e88-cee75a86792f)

<ins>CAPTURA 4</ins>

![4](https://github.com/user-attachments/assets/72fc4664-2ceb-4f5f-9b4f-51cec3811317)

<ins>CAPTURA 5</ins>

![5](https://github.com/user-attachments/assets/9af06273-a438-49d6-a1db-cd7f9c57bbee)

<ins>CAPTURA 6</ins>

![6](https://github.com/user-attachments/assets/95a0c4f0-5445-4060-8983-2d48479fbde5)

<ins>CAPTURA 7</ins>

![7](https://github.com/user-attachments/assets/6cb453d7-50a7-4350-9b4d-c1d9b2a6d8d2)

<ins>CAPTURA 8</ins>

![8](https://github.com/user-attachments/assets/4935c719-baf5-4997-b9a4-887ef7a4539c)

<ins>CAPTURA 9</ins>

![9](https://github.com/user-attachments/assets/3d6d5cc4-2564-4963-8763-45e4f69a42b5)

<ins>CAPTURA 10</ins>

![10](https://github.com/user-attachments/assets/5091dba1-2820-4d5e-9d57-510772c2350c)

<ins>CAPTURA 11</ins>

![11](https://github.com/user-attachments/assets/36ce5ee7-1a2d-47ac-9055-b8c5975cefc0)

<ins>CAPTURA 12</ins>

![12](https://github.com/user-attachments/assets/77aca315-c8ba-4501-a36d-e261c9a737e1)

<ins>CAPTURA 13</ins>

![13](https://github.com/user-attachments/assets/74c2317a-77ec-4b61-88e9-d6cf376a2947)



