// players.h


// Esta clase se encarga del manejo del jugador

class player
{
    BITMAP *prota;
 int x,y;
 int direccion;


    public:
       void inicia();
       void pinta();
       void teclado();
       int getx(){ return x; };
       int gety(){ return y; };
       void posiciona( int _x, int _y);
};


void player::inicia()
{
    prota  = load_bmp("puerquito2.bmp",NULL);
 // inicializar vbles
 direccion = 0;

 x = 250;
 y = 400;
}


void player::pinta()
{

    masked_blit(prota, buffer, 32, direccion*32, x, y, 32,32);
}

void player::teclado()
{
    int desplazamiento =3;
      int ax = x;
      int ay = y;
      // teclas control usuario
      if ( key[KEY_UP] )
      {
           y-=desplazamiento;
           direccion = 3;
      }
      if ( key[KEY_DOWN] )
      {
           y+=desplazamiento;
           direccion = 0;
      }
      if ( key[KEY_LEFT] )
      {
           x-=desplazamiento;
           direccion = 1;
      }
      if ( key[KEY_RIGHT] )
      {
           x+=desplazamiento;
           direccion = 2;
      }


      // limites globales
      if ( x < 0 ) x = 0;
      if ( x > PANTALLA_ANCHO ) x = PANTALLA_ANCHO;
      if ( y < 0 ) y = 0;
      if ( y > PANTALLA_ALTO )  y = PANTALLA_ALTO;
}

void player::posiciona( int _x, int _y)
{
     x=_x;
     y=_y;
}
