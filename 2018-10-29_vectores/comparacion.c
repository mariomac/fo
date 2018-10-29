#include <stdio.h>

#define N 5

main() {
  int v[N] = { 1, 2, 3, 4, 5 };
  int w[N] = { 1, 0, 3, 4, 5 };
  int i;
  int diferentes = 0;

  for (i = 0 ; i < N && diferentes == 0; i++) {
    if (w[i] != v[i]) {
      diferentes++;
    }
  }

  if (diferentes == 0) {
    printf("Son iguales\n");
  } else {
    printf("Son diferentes\n");
  }
}


