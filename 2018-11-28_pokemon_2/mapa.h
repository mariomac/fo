#ifndef _MAPA_H_
#define _MAPA_H_

// Si 0 --> Desactiva Emojis (para terminales antiguos)
#define EMOJI 1

// Chars del mapa, tal y como se representan internamente
#define C_VACIO   ' '
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
  int jug_f, jug_c; // posición del jugador
  char c[T][T+1];
} t_mapa;

// Prototipos de las funciones. Su implementación está en mapas.c

/**
 * Función que muestra un mapa.
 * Parámetros: m -> Mapa a mostrar
 */
void mostrar_mapa(t_mapa m);

/**
 * Mueve al jugador por el mapa, en la dirección indicada.
 * Parámetros: direcc -> Dirección del jugador. Podrá ser una de las siguientes
 *                       constantes de "teclas.h": UP, DOWN, LEFT o RIGHT
 */
void mueve(int direcc, t_mapa *m);

/**
 * Imprime un char. Si la constante EMOJI vale 0, imprimirá el carácter tal
 * cual. Si EMOJI tiene otro valor, intentará imprimir el emoji correspondiente
 * Parámetros: c -> Carácter a imprimir, o carácter que representa un emoji
 */
void imprime_char(char c);

#endif






