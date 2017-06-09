#include <allegro.h>

#ifndef PERSONAJES_H_INCLUDED
#define PERSONAJES_H_INCLUDED
struct Personaje{
    int x,y;
    int b_ancho;
    int b_alto;
    int n_disp;
    int max_disp;
    int tick;
    int ancho_p;
    int alto_p;
    int dir_bala;
    int tipo;
    int vida;


    BITMAP *img;
    BITMAP *bala;


    void inicia(char* ruta_img, char* ruta_bala,int _ancho_b, int _alto_b,
                int _ancho_p, int _alto_p, int _x, int _y, int _dir_bala, int _tipo, int _vida);
    bool temporizador();
    void pinta(BITMAP* buffer);
    void mueve();
    void disparo(struct Balas disparos[], BITMAP *buffer);

};


void acomoda_enemigos(struct Personaje E[]);
void pintar_enemigo(struct Personaje  E[], BITMAP *buffer);

#endif // DISPAROS_H_INCLUDED
