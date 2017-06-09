#include "disparos.h"
#include "personajes.h"
#define ANCHO 600
#define ALTO  600
#include <allegro.h>

void Personaje::disparo(struct Balas disparos[], BITMAP *buffer){
        if(tipo)
        crear_bala(n_disp, max_disp, disparos, x, y, dir_bala);
        pintar_bala(n_disp,max_disp, disparos, buffer,bala,b_ancho,b_alto);
        elimina_bala(n_disp,max_disp,disparos,ANCHO,ALTO);


}



bool Personaje::temporizador(){
tick++;
if(tick == 5){
    tick = 0;
    return true;
}
return false;

}

void Personaje::inicia(char* ruta_img, char* ruta_bala,int _ancho_b, int _alto_b,
                       int _ancho_p, int _alto_p,
                    int _x, int _y, int _dir_bala,
                    int _tipo, int _vida){


x=_x;
y=_y;
n_disp = 0; max_disp = 2;
img = load_bitmap(ruta_img,NULL);
bala=load_bitmap(ruta_bala,NULL);
tick=0;
b_ancho=_ancho_b;
b_alto = _alto_b;
ancho_p = _ancho_p;
alto_p = _alto_p;
dir_bala = _dir_bala;
tipo = _tipo;
vida = _vida;
}

void Personaje::pinta(BITMAP* buffer){
        masked_blit(img,buffer,0,0,x,y,ancho_p,alto_p);
}

void Personaje::mueve(){

        if(key[KEY_LEFT]) x-=5;
        if(key[KEY_RIGHT]) x+=5;
        if(key[KEY_UP]) y-= 5;
        if(key[KEY_DOWN]) y+=5;


         if ( x < 0 ) x= 0;
      if ( x > ANCHO-32) {x = ANCHO-32;}
      if ( y < 250 ) y = 250;
      if ( y > ALTO-32) y = ALTO-32;

}
void acomoda_enemigos(struct Personaje E[]){
    int indice = -1;
    int cont = 0;
    for(int i = 0; i < 5 ; i++){
        for(int j = 0; j < 24 ;j++){
            indice++;
            cont++;
         if(cont <=24)
            E[indice].inicia("Recursos/Enemigos/bomba.bmp","Recursos/Enemigos/cuchillo.bmp",
                             24, 24, 24, 24, 10+j*24, i*24, 15,1,1);
         if(cont > 24){

            E[indice].inicia("Recursos/Enemigos/cuchillo.bmp","Recursos/Enemigos/cuchillo.bmp",
                             24, 24, 24, 24, 10+j*24, i*24, 15,0,2);

         }


        }
        if(cont==48)
        cont=0;
    }
}


void pintar_enemigo(struct Personaje  E[], BITMAP *buffer){
int indice = -1;
    for(int i = 0; i < 5 ; i++){
        for(int j = 0; j < 24 ;j++){
            indice++;
            if(E[indice].vida >0)
        E[indice].pinta(buffer);
        }
    }

}


