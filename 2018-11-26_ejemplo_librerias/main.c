#include <stdio.h>
#include "calculo.h"

main() {
  int x;
  printf("X? ");
  scanf("%d", &x);
  printf("e^x = %lf\n", exponencial(x));
}

