#include "pokemon.h"
#include <stdio.h>

main() {
  t_bolsa_pokemon bolsa = {
      3,
      {
        {"Pikachu", 100, ESTADO_BIEN},
        {"Snorlax", 150, ESTADO_SUENYO},
        {"Son Goku", 100000, ESTADO_BIEN}
      }
  };
  t_pokemon elegido;
  
  char nombre[100];
  printf("A quien quieres? ");
  scanf("%[^\n]%*c", nombre);
  
  int res = sacar_pokemon(nombre, &bolsa, &elegido);
  
  switch(res) {
    case RES_OK:
      printf("Has elegido a:\n");
      mostrar_pokemon(elegido);
      break;
    case RES_NO_ENCONTRADO:
      printf("No he encontrado a ningun pokemon con ese nombre\n");
      break;
    case RES_INDISPUESTO:
      printf("Tu pokemon esta indispuesto\n");
      break;
  }
}













