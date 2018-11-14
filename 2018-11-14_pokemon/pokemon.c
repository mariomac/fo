#include <stdio.h>

// Si 0 --> Desactiva Emojis (para terminales antiguos)
#define EMOJI 1

// Chars del mapa, tal y como se representan internamente
#define C_ARBOL   'A'
#define C_POKEMON 't'
#define C_PROTA   '@'

// Emojis para cada elemento del mapa, según su código estándar
// https://apps.timwhitlock.info/emoji/tables/unicode
#define EMOJI_ARBOL   "\xF0\x9F\x8C\xB2"
#define EMOJI_POKEMON "\xF0\x9F\x90\x93"
#define EMOJI_PROTA   "\xF0\x9F\x98\x8B"

// Tamaño del mapa
#define T 12

typedef struct {
  char c[T][T+1];
} t_mapa;

// Prototipos de las funciones. Su implementación está después del main()
void mostrar_mapa(t_mapa m);
void imprime_char(char c);

main() {
  t_mapa m = {{
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
  mostrar_mapa(m);
}

// Imprime un mapa m
void mostrar_mapa(t_mapa m) {
  int fil, col;
  for( fil = 0 ; fil < T ; fil++) {
    for( col = 0 ; col< T ; col++) {
      imprime_char(m.c[fil][col]);  
    }
    printf("\n");
  }
}

// Imprime un char. Si EMOJI != 0, tratará de imprimir el emoji que corresponda
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



















