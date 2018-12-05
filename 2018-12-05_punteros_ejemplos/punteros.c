#include <stdio.h>
#include <math.h>
#define LAMBDA 0.000001

/*
 * Función que resuelve una ecuación de 2o grado, dados los valores a, b y c.
 * Guarda las posibless soluciones en los valores apuntados por los punteros
 * *x1 y *x2.
 * Retorna: el número de soluciones: 0, 1 o 2.
 *     Si tiene 1 solución, se encontrará en la variable apuntada por *x1.
 *     Si tiene 2 soluciones, estarán en las variables apuntadas por *x1 y *x2.
 */
int resuelve(double a, double b, double c, double *x1, double *x2);
             
main() {
  double a,b,c;
  printf("a, b, c? ");
  scanf("%lf%lf%lf", &a, &b, &c);
  int sol;
  
  double x1, x2;
  // Invocamos "resuelve" pasando a, b, c por valor (no se modificarán)
  // y x1 y x2 por referencia (su valor quedará modificado si hay soluciones).
  sol = resuelve(a, b, c, &x1, &x2);
  
  if (sol == 0) {
    printf("No tiene soluciones\n");
  } else if(sol == 1) {
    printf("Solución: %lf\n", x1);
  } else {
    printf("Soluciones: %lf y %lf\n", x1, x2);
  }
  
}

int resuelve(double a, double b, double c, double *x1, double *x2) {
  double t = b*b-4*a*c;
  int soluciones;
  // Recordad que para comparar doubles y floats con ==, es más efectivo
  // compararlos a partir de un lambda muy pequeño.
  if (t < LAMBDA && t > -LAMBDA) { // if t == 0
    soluciones = 1;
    *x1 = -b / (2*a);
  } else if (t < 0) {
    soluciones = 0;
  } else {
    soluciones = 2;
    *x1 = (-b + sqrt(t)) / (2 * a);
    *x2 = (-b - sqrt(t)) / (2 * a);
  }
  
  return soluciones;
}
