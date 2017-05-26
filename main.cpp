#include <allegro.h>
#include "global.h"
#include "player.h"
#include "mijuego.h"

const int maxdisp=5;
const int ANCHO = 500;
const int ALTO = 450;


void inicia_allegro()
{

	allegro_init();
	install_keyboard();

	set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, ANCHO, ALTO, 0, 0);

    LOCK_VARIABLE(contador_tiempo_juego);
    LOCK_FUNCTION(inc_contador_tiempo_juego);

    // Iniciamos el limitador de FPS
    install_int_ex(inc_contador_tiempo_juego, BPS_TO_TIMER( FRAME_RATE ));
}

struct Puerco {

int x;
int y;
int dir;
int ndisparos;

} puer ={350,300,3,0};

struct Balas {
int x;
int y;
int dx;
int dy;

}disparos[maxdisp];


 void pintar_puerco (BITMAP *puerco, BITMAP *buffer, struct Puerco puer){
    masked_blit(puerco,buffer,40*puer.dir,0,puer.x,puer.y,32,32);
    }


    int main () {

    inicia_allegro();
    BITMAP *puerco = load_bitmap("puerquito.bmp",NULL);
    BITMAP *nube = load_bitmap("fondo.bmp",NULL);
    BITMAP *bala = load_bitmap("shoot.bmp",NULL);
    BITMAP *buffer = create_bitmap (500,450);

    int i = 450, dsw=0, contt=0;
    while (!key[KEY_ESC]){
        blit (nube,buffer,0,--i,0,0,500,450); if (i==0) i=450;
        pintar_puerco(puerco,buffer,puer);

    if(key[KEY_UP]) {puer.dir = 1; puer.y -= 1;}
    else if (key[KEY_DOWN]) {puer.dir = 1; puer.y += 2;}
    if(key[KEY_RIGHT]) {puer.dir = 2; puer.y += 1;}
    else if (key[KEY_LEFT]) {puer.dir = 0; puer.y -= 1;}
    else {puer.dir = 1;}

    if(key[KEY_SPACE] && dsw ==0) {
        if(puer.ndisparos < maxdisp){

            puer.ndisparos++;
            disparos[puer.ndisparos].x=puer.x +14 ; //el numero es para que salga centrado del bitmap
            disparos[puer.ndisparos].y = puer.y;
            disparos[puer.ndisparos].dx=0; //el numero es para que salga centrado del bitmap
            disparos[puer.ndisparos].dy = -3;
            dsw=1;
        }
    }

    if(contt++ > 20){

        dsw=0; contt=0;

    }
    if(puer.ndisparos >0){
        for(int cont = 1;cont<=puer.ndisparos;cont++){
            disparos[cont].x += disparos[cont].dx;
            disparos[cont].y += disparos[cont].dy;
            masked_blit(bala,buffer,0,0,disparos[cont].x,disparos[cont].y,40,70);

            if(disparos[cont].y > ALTO || disparos[cont].y <0 ||
               disparos[cont].x > ANCHO | disparos[cont].x <0){

                    disparos[cont] = disparos[puer.ndisparos];
                    puer.ndisparos--;
                    if(puer.ndisparos < 0) puer.ndisparos =0;


               }
        }


    }

    blit(buffer,screen,0,0,0,0,500,450);
    rest(5);
    }

    destroy_bitmap(buffer);
    destroy_bitmap(puerco);
    destroy_bitmap(nube);

    }


END_OF_MAIN();
