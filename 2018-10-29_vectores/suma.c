#include <stdio.h>

#define N 15

main() {
  float suma;
  float v[N] = {0.4, 0.6, 0.5, 0.2,
                1.7, 2.1, 0.1, 4.3,
                9.9, 5, 1000, 100.1,
                2.3, 4.4, -3.1};
  int i;
  suma = 0;
  for (i = 0 ; i < N ; i++) {
    suma += v[i];
  }
  printf("suma de todos los elementos del vector = %f\n", suma);

}


