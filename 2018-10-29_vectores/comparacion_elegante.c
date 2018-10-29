#include <stdio.h>

#define N 5

main() {
  int v[N] = { 1, 2, 3, 4, 5 };
  int w[N] = { 1, 2, 3, 4, 5 };
  int i;

  // El índice 'i' avanzará hasta encontrar dos elementos distintos
  // o hasta llegar al final del vector
  for (i = 0 ; i < N && v[i] == w[i]; i++) {
    // Vacío a drede
  }

  // Si i == N -> Ha llegado al final del vector -> No ha encontrado ningún
  // elemento diferente
  if (i == N) {
    printf("Son iguales\n");
  } else {
    printf("Son diferentes\n");
  }
}


