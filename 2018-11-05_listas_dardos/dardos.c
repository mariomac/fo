#include <stdio.h>
#define MAX_N 100
#define MAX_J 30
#define N_TIRADAS 5

typedef struct {
  char nombre[MAX_N];
  int tiradas[N_TIRADAS];
  int total;
} t_jugador;

typedef struct {
  int num_j;
  t_jugador jugadores[MAX_J];
} t_clasificacion;

main() {
  t_clasificacion clas = {
    4, // num_j
    {  // jugadores
      { "Pere Garcia", { 10, 2, 3, 4, 5}, 24 },
      { "Laia Lopez", { 8, 4, 3, 2, 1 }, 18 },
      { "Josep Perez", { 3, 3, 3, 2, 1 }, 12 },
      { "Marta Pujol", { 1, 1, 1, 1, 1 }, 5 }
    }
  };

  t_jugador j;
  int i, nj, pos;
  // Leer jugador por teclado
  printf("Nombre? ");
  scanf("%[^\n]%*c", j.nombre);
  j.total = 0;
  for (i = 0 ; i < N_TIRADAS ; i++) {
    printf("Tirada %d: ", i+1);
    scanf("%d", &j.tiradas[i]);
    j.total += j.tiradas[i];
  }
  
  pos = 0;
  while (j.total < clas.jugadores[pos].total
          && pos < clas.num_j) {
    pos++;
  }

  // Insertar nuevo jugador
  // Hacer espacio
  for (i = clas.num_j ; i > pos ; i--) {
    clas.jugadores[i] = clas.jugadores[i-1];
  }
  // copiar jugador en posicion
  clas.jugadores[pos] = j;
  clas.num_j++; // aumentar tamaño lista
  
  // Mostrar jugadores
  for (nj = 0 ; nj < clas.num_j ; nj++) {
    j = clas.jugadores[nj];
    printf("%s (", j.nombre);
    printf("%d", j.tiradas[0]);
    for (i = 1 ; i < N_TIRADAS ; i++) {
      printf(" - %d", j.tiradas[i]);
    }
    printf(") Total: %d\n", j.total);
  }
}







