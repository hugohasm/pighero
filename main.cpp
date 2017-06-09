#include <allegro.h>
#include "inicia.h"
#include "disparos.h"
#define ANCHO 600
#define ALTO  600
#include <stdlib.h>
#include <time.h>
#include "personajes.h"
#include "Menu.h"




bool limites(struct Personaje E[], int& dir){

    for(int i; i<140;i++){
        if(E[i].x > 100|| E[i].x < 100)
        {
            dir =-1*dir;
            return true;
        }

    }

        return false;

}

void mover_enemigos(struct Personaje E[],int& dir){

    if(limites(E,dir)){
        for(int j = 0;j < 140; j++) E[j].y +=dir;
    }



}


int main(){
    srand(time(NULL));

    inicia_allegro(ANCHO,ALTO); // fuciones del include inicia.h
	inicia_audio(70,70);        //

    BITMAP *buffer = create_bitmap(ANCHO, ALTO);
    BITMAP *portada = load_bitmap("Recursos/portada.bmp",NULL);
    BITMAP *fondo = load_bitmap("Recursos/fondo.bmp",NULL);
    BITMAP *Over = load_bitmap("Recursos/over.bmp",NULL);
    BITMAP *Win = load_bitmap("Recursos/Win.bmp",NULL);
    MIDI *musifondo = load_midi("Recursos/Musica/fondo.mid");
    Menup(portada);

    Personaje puerco;
    Personaje E[200];
    puerco.inicia("Recursos/Puerco/puerquito.bmp","Recursos/Disparos/shoot1.bmp",16,16,32,32,
                  ANCHO/2,ALTO-150,-8,0,3);

    puerco.max_disp = 5;
    acomoda_enemigos(E);
    Balas disparos[puerco.max_disp];
    Balas dis_e[E[0].max_disp];

    int azar = rand()%140;
    int dir = -1;
    int vel_juego =10;
    int con = 0, con2=0;

    play_midi(musifondo,1);
////////////////////////////////////////////
    while(!key[KEY_ESC]){
       clear_to_color(buffer,0x000000);
       Imprimir_fondo(fondo,buffer);
        if(puerco.vida==0){
            Imprimir_fondo(Over,buffer);

        }
        for (int i = 0; i<140;i++)
            if(elimina_bala_objeto(puerco,E[i],disparos, con)){
                explosion1(E[i],buffer);
                con++;
            }

        puerco.pinta(buffer);
        puerco.mueve();

            if(con>=20){
            puerco.img = load_bitmap("Recursos/Puerco/puerquitodp.bmp",NULL);

                        }

            if(con >= 40){
            puerco.img = load_bitmap("Recursos/Puerco/puerquitotp.bmp",NULL);
            if ( puerco.x < -35 ) puerco.x= ANCHO-35;
            if ( puerco.x > ANCHO-35) puerco.x = 0;


            }

            if(con >= 80){

            puerco.img = load_bitmap("Recursos/Puerco/superpuerquito.bmp",NULL);
            puerco.max_disp = 10;
            }


            if (con>=140)
                Imprimir_fondo(Win,buffer);

            if(E[0].temporizador())
            mover_enemigos(E,dir);


        if(key[KEY_SPACE] && puerco.temporizador())
        crear_bala(puerco.n_disp,puerco.max_disp,disparos,puerco.x,puerco.y,puerco.dir_bala);
        puerco.disparo(disparos,buffer);

        pintar_enemigo(E,buffer);

    if(E[azar].n_disp == 0) azar = rand()%140;
    E[azar].disparo(dis_e, buffer);

if(elimina_bala_objeto(E[azar],puerco,dis_e,con2))
    explosion2(puerco,buffer,fondo);

    blit(buffer,screen,0,0,0,0,ANCHO,ALTO);
            rest(20);





    }


	return 0;
}
END_OF_MAIN();

