#include <stdio.h>

#include "mapa.h"
#include "teclas.h"

main() {
  t_mapa m = {
    7, 4, {
    "AAAAAAAAAAAA",
    "AA    A t AA",
    "A t   A    A",
    "A     AAA AA",
    "A          A",
    "AAAA       A",
    "A          A",
    "A   @      A",
    "A      A  AA",
    "A        t A",
    "AA     A  AA",
    "AAAAAAAAAAAA",    
  }};

  // bucle principal del juego, que se repetirá mientras no se pulse 'Q'
  int tecla;
  do {
    borrar_pantalla();
    mostrar_mapa(m);
    
    tecla = lee_tecla();
    mueve(tecla, &m);
    
  } while(tecla != CANCEL);
}




















