/* GLOBAL.H

*/

// Ancho y alto de la pantalla
const int PANTALLA_ANCHO = 500;
const int PANTALLA_ALTO  = 450;

// En este BITMAP dibujaremos todo
BITMAP *buffer;

// es el espacio en pixel que recorre el jugador al andar
const int desplazamiento=4;


// Copiar el buffer a la pantalla del juego (screen)
void pintar_pantalla()
{
    blit(buffer, screen, 0, 0, 0, 0, PANTALLA_ANCHO, PANTALLA_ALTO);
}

// controla el bucle principal
bool salir;

// Variable usada para la velocidad
volatile unsigned int contador_tiempo_juego = 0;

const int FRAME_RATE = 30;

// Función para controlar la velocidad
void inc_contador_tiempo_juego()
{
    contador_tiempo_juego++;
}
END_OF_FUNCTION(inc_contador_tiempo_juego)
