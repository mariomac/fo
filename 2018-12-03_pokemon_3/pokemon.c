#include "pokemon.h"
#include <string.h>
#include <stdio.h>

void mostrar_pokemon(t_pokemon p) {
  printf("%s (estado: %c, vida: %d)\n",
    p.nombre, p.estado, p.vida);
}

int sacar_pokemon(char *nombre, t_bolsa_pokemon *bolsa, t_pokemon *p) {
  int pos = 0;
  while (pos < bolsa->num &&
        strcasecmp(nombre, bolsa->pok[pos].nombre) != 0) {
    pos++;
  }
  if (pos >= bolsa->num ) {
    return RES_NO_ENCONTRADO;
  }
  if (bolsa->pok[pos].estado != ESTADO_BIEN) {
    return RES_INDISPUESTO;
  }
  *p = bolsa->pok[pos];
  
  // FALTA: eliminar el pokemon de la bolsa

  return RES_OK;
}

// FALTA: mostrar todos los pokemons de una bolsa
