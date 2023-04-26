# So_long
Este proyecto consiste en crear un juego en 2D utilizando la librería gráfica MinilibX y programado en C.

## Descripción del juego
El juego se desarrolla en un laberinto en el que el jugador tiene que recoger todos los coleccionables antes de llegar a la salida. Si el jugador entra en contacto con los enemigos o si se queda sin vidas, pierde la partida. El jugador puede moverse hacia arriba, abajo, izquierda o derecha, pero no puede atravesar paredes ni obstáculos.

## Compilación
Para compilar el proyecto, simplemente ejecuta el comando make en la raíz del proyecto. Este comando compila el proyecto y genera el ejecutable so_long.

## Ejecución
Para ejecutar el juego, utiliza el siguiente comando en la raíz del proyecto:

> ./so_long maps/map.ber

El argumento map.ber puede ser sustituido por el nombre del archivo del mapa que quieras utilizar.

## Mapas
Los mapas deben tener la extensión .ber y deben estar formados por los siguientes caracteres:

- *1*: pared
- *0*: suelo
- *C*: coleccionable
- *E*: salida
- *P*: jugador

## Controles del juego
Los controles del juego son los siguientes:

- *W* o *flecha hacia arriba*: mover el jugador hacia arriba.
- *A* o *flecha hacia la izquierda*: mover el jugador hacia la izquierda.
- *S* o *flecha hacia abajo*: mover el jugador hacia abajo.
- *D* o *flecha hacia la derecha*: mover el jugador hacia la derecha.
- *ESC*: cerrar el juego.
¡Que lo disfrutes!




