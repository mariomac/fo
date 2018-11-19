#include <stdio.h>

#define N 50

double potencia(double a, int b);
long factorial(int n);
double exponencial(int x);

main() {
  int x;
  printf("X? ");
  scanf("%d", &x);
  printf("e^x = %lf\n", exponencial(x));
}

double exponencial(int x) {
  int i;
  double r = 0;
  for (i = 0 ; i <= N ; i++) {
    r += potencia(x, i) / factorial(i);
  }
  return r;
}

long factorial(int n) {
  int i;
  long r = 1;
  for (i = 1 ; i <= n ; i++) {
    r = r * i;
  }
  return r;
}

// TO DO: exponentes negativos
double potencia(double a, int b) {
  int i;
  double r = 1;
  for (i = 1 ; i <= b ; i++) {
    r = r * a;  
  }
  return r;
}
