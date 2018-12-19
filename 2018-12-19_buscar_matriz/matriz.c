#include <stdio.h>

#define MAX 50

typedef struct {
  int nfilas; //numero de filas
  int ncols;  //numero de columnas
  int elems[MAX][MAX];
} t_matriz;

// Encuentra n en la matriz m
// Guarda la posición en *fil, y *col
// Retorna 0 si lo encuentra
// Retorna -1 si no lo encuentra
int buscar(int n, t_matriz m, int *fil, int *col);

main() {
  t_matriz m = {
    4, 5,
    { { 1, 2, 3, 4, 5 },
      { 6, 7, 8, 9,10 },
      {11,12,13,14,15 },
      {16,17,18,19,20 }}
  };
  int n;
  printf("Numero a buscar: ");
  scanf("%d", &n);
  int fila, columna;
  if (buscar(n, m, &fila, &columna) == 0) {
    printf("El elemento se encuentra en %d, %d\n",
                fila, columna);
  } else {
    printf("No se ha encontrado\n");
  }
}

int buscar(int n, t_matriz m, int *fil, int *col) {
  int f, c;
  
  for (f = 0 ; f < m.nfilas ; f++) {
    for (c = 0 ; c < m.ncols ; c++) {
      if (m.elems[f][c] == n) {
        *fil = f;
        *col = c;
        return 0;
      }
    }
  }
  return -1;
}
















