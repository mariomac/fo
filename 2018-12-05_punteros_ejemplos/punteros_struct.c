#include <stdio.h>
typedef struct {
  char nombre[100];
  int fuerza;
  int vida;
} t_pokemon;

// Simula el ataque de un Pokemon atacante a uno que recibe el golpe.
// Del que ataca solo necesitamos saber su fuerza. No modificamos nada y por
// eso usamos un valor.
// En el que recibe, necesitamos modificar su vida. Como el estado del Pokemon
// cambiará, hemos de usar un paso por referencia (puntero).
void ataca(t_pokemon ataca, t_pokemon *recibe) {
  recibe->vida -= ataca.fuerza;
}

// Muestra el nombre y la vida de un Pokemon.
// Como solo necesitamos leer los datos (no vamos modificarlo), usamos un paso
// de parámetros por valor.
void muestra(t_pokemon p) {
  printf("%s (vida: %d)", p.nombre, p.vida);  
}

main() {
  t_pokemon p1 = { "Pikachu", 10, 100 };
  t_pokemon p2 = { "Charizord", 20, 90 };
  
  muestra(p1);
  printf(" ataca a");
  muestra(p2);
  printf("\n");

  // p1 (ataca) se pasa por valor
  // p2 (recibe) se pasa por referencia (puntero)
  ataca(p1, &p2);
  
  muestra(p2);
  printf(" ataca a");
  muestra(p1);
  printf("\n");

  // p2 (ataca) se pasa por valor
  // p1 (recibe) se pasa por referencia (puntero)
  ataca(p2, &p1);
  
  printf("El estado de los Pokemon despues del rifirrafe es:\n");
  muestra(p1); printf("\n");
  muestra(p2); printf("\n");
}










