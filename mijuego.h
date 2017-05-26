/*
   mijuego.h

*/

BITMAP *fondo;

player jugador;


// carga todo lo necesario antes de empezar el juego
void carga_juego()
{
    jugador.inicia();
    // cargamos imagenes del primer escenario
    fondo  = load_bmp("fondo.bmp",NULL);
}


// actualiza el estado del juego
void actualiza_juego()
{
    int ax,ay;
    ax = jugador.getx();
    ay = jugador.gety();
    jugador.teclado();

    // comprobar si colisiona con el mapa
    bool choca = false;
    int px = jugador.getx()-160;
    int py = jugador.gety()-160+16;
    if ( choca ){
         // vuelve al estado anterior
         jugador.posiciona( ax,ay );
    }

}


// Se encarga de pintar todo sobre el buffer
void pinta_juego()
{
    blit( fondo, buffer, 0,0, 160, 160, 480,325);
    jugador.pinta();
}
