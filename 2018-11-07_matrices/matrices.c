#include <stdio.h>
#define LARGO 7 // lado largo de la matriz
#define CORTO 4 // lado corto de la matriz

// Programa que, dada una matriz 'm', calcula su transpuesta 't'
main() {
  // 4 filas por 7 columnas
  int m[CORTO][LARGO] = {
    {  1,  2,  3,  4,  5,  6,  7 },
    {  8,  9, 10, 11, 12, 13, 14 },
    { 15, 16, 17, 18, 19, 20, 21 },
    { 22, 23, 24, 25, 26, 27, 28 }
  };
  // transpuesta: 7 filas por 4 columnas
  int t[LARGO][CORTO];

  // Cálculo de la transpuesta: t[j][i] = m[i][j]
  // Para recorrer una matriz, necesitamos dos bucles, uno anidado dentro
  // del otro
  int i, j;
  for (i = 0 ; i < LARGO ; i++) {
    for (j = 0 ; j < CORTO ; j++) {
      t[i][j] = m[j][i];
    }
  }

  printf("\nLa matriz:\n\n");

  // Mostrar la matriz original por pantalla
  for (i = 0 ; i < CORTO ; i++) { // Recorrer filas
    for (j = 0 ; j < LARGO ; j++) { // Recorrer columnas
      printf("%2d ", m[i][j]);
    }
    printf("\n");
  }

  printf("\nTiene como transpuesta:\n\n");

  // Mostrar la transpuesta por pantalla
  for (i = 0 ; i < LARGO ; i++) { // Recorrer filas
    for (j = 0 ; j < CORTO ; j++) { // Recorrer columnas
      printf("%2d ", t[i][j]);
    }
    printf("\n");
  }

  printf("\n");
}
