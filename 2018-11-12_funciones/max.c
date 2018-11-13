#include <stdio.h>

// Cabeceras o "prototipos" de las funciones que usaremos
// Se definen aquí para informar a C que existen. Se definen
// después del main

// Función max:
//     - Retorna el mayor de dos números
//   Parámetros:
//     - a y b (double): los dos números cuyo mayor queremos saber
//   Retorna:
//     - El mayor de los parámetros a y b
double max(double a, double b);

// Función max3:
//     - Retorna el mayor de tres números
//   Parámetros:
//     - a, b y c (double): los tres números cuyo mayor queremos saber
//   Retorna:
//     - El mayor de los parámetros a, b y c
double max3(double a, double b, double c);

main() {
  double n1, n2, n3;
  double r;
  printf("Introduce 3 numeros: ");
  scanf("%lf%lf%lf", &n1, &n2, &n3);
  
  r = max3(n1, n2, n3);
  
  printf("El mayor es %lf\n", r);
}

// Implementación de las funciones cuyos prototipos hemos escrito en la cabecera
double max(double a, double b) {  
  if (a > b) {
    return a;
  } else {
    return b;
  }
}

// Esta función queda más clara si invocamos a "max" para reutilizar código
double max3(double a, double b, double c) {
  double m = max(a, b);
  return max(m, c);
  // También valdría: return max(max(a,b), c);
}
