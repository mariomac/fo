#include <stdio.h>
#include "mapa.h"
#include "teclas.h"

/**
 * Mueve al jugador por el mapa, en la dirección indicada.
 * Parámetros: direcc -> Dirección del jugador. Podrá ser una de las siguientes
 *                       constantes de "teclas.h": UP, DOWN, LEFT o RIGHT
 */
void mueve(int direcc, t_mapa *m) {
  // Establezco filas y columna destino, según la posición actual del
  // jugador y la dirección a moverse.
  int fd = m->jug_f;
  int cd = m->jug_c;
  switch(direcc) {
    case UP:
      fd--;
      break;
    case DOWN:
      fd++;
      break;
    case LEFT:
      cd--;
      break;
    case RIGHT:
      cd++;
      break;
    default:
      // entrada no reconocida: salgo de la función
      return;                  
  }
  // Sólo me moveré si la casilla de destino está vacía
  if (m->c[fd][cd] == C_VACIO) {
    // saco al jugador de su posición actual
    m->c[m->jug_f][m->jug_c] = C_VACIO;
    
    // actualizo el jugador a la nueva posición
    m->jug_f = fd;
    m->jug_c = cd;
    
    // volver a poner al jugador en nueva posicion
    m->c[m->jug_f][m->jug_c] = C_PROTA;
  }
  
}

/**
 * Función que muestra un mapa.
 * Parámetros: m -> Mapa a mostrar
 */
void mostrar_mapa(t_mapa m) {
  int fil, col;
  for( fil = 0 ; fil < T ; fil++) {
    for( col = 0 ; col< T ; col++) {
      imprime_char(m.c[fil][col]);  
    }
    printf("\n");
  }
}

/**
 * Imprime un char. Si la constante EMOJI vale 0, imprimirá el carácter tal
 * cual. Si EMOJI tiene otro valor, intentará imprimir el emoji correspondiente
 * Parámetros: c -> Carácter a imprimir, o carácter que representa un emoji
 */
void imprime_char(char c) {
  if (!EMOJI) {
    // Si emoji está desactivado, imprimo el caracter tal cual
    printf("%c", c);
    return;  // y salgo de la función
  }
  // Según el carácter a imprimir, imprimo su correspondiente emoji
  switch(c) {
    case C_ARBOL:
      printf(EMOJI_ARBOL);
      break;
    case C_POKEMON:
      printf(EMOJI_POKEMON);
      break;
    case C_PROTA:
      // imprimo personaje
      printf(EMOJI_PROTA);
      break;
    default:
      // como los emojis ocupan el doble de espacio,
      // cualquier otro caracter lo imprimo con un espacio delante
      printf(" %c", c);
      break;
  }  
}

