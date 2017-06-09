#include <allegro.h>
#include "inicia.h"
#include "disparos.h"
#define ANCHO 600
#define ALTO  600
#include <stdlib.h>
#include <time.h>
#include "personajes.h"
#include "Menu.h"


int main(){
    srand(time(NULL));

    inicia_allegro(ANCHO,ALTO); // fuciones del include inicia.h
//	inicia_audio(70,70);        //

    BITMAP *buffer = create_bitmap(ANCHO, ALTO);
    BITMAP *portada = load_bitmap("Recursos/portada.bmp",NULL);
    BITMAP *fondo = load_bitmap("Recursos/fondo.bmp",NULL);

    Menup(portada);

    Personaje puerco;
    Personaje E[200];
    puerco.inicia("Recursos/Puerco/puerquito.bmp","Recursos/Disparos/shoot1.bmp",16,16,32,32,
                  ANCHO/2,ALTO-50,-8,0,3);

    puerco.max_disp = 10;
    acomoda_enemigos(E);
    Balas disparos[puerco.max_disp];
    //Balas dis_e[E[0].max_disp];


    int azar = rand()%40;

////////////////////////////////////////////
    while(!key[KEY_ESC]){
       clear_to_color(buffer,0x000000);

        for (int i = 0; i<120;i++)
           elimina_bala_objeto(puerco,E[i],disparos);

        puerco.pinta(buffer);
        puerco.mueve();
        if(key[KEY_SPACE] && puerco.temporizador())
        crear_bala(puerco.n_disp,puerco.max_disp,disparos,puerco.x,puerco.y,puerco.dir_bala);
        puerco.disparo(disparos,buffer);

        pintar_enemigo(E,buffer);

    //    if(E[azar].n_disp == 0) azar = rand()%40;
  //      E[azar].disparo(dis_e, buffer);
    // Imprimir_fondo(fondo,buffer);
     blit(buffer,screen,0,0,0,0,ANCHO,ALTO);
            rest(20);

    }


	return 0;
}
END_OF_MAIN();

