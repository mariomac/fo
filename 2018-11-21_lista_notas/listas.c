#include <stdio.h>
#define MAX 100

typedef struct {
  char nombre[MAX];
  float nota;
} t_alumno;

typedef struct {
  int num;
  t_alumno al[MAX];
} t_lista_notas;

main() {
  t_lista_notas notas = { 0, {}}; // lista vacía
  t_alumno nuevo;
  int posicion, i;
  char otro;
  
  do {
    printf("Nombre: ");
    scanf("%[^\n]%*c", nuevo.nombre);
    printf("Nota: ");
    scanf("%f%*c", &nuevo.nota);
    
    // Calcular en qué posición se debe insertar para que la lista quede
    // ordenada
    posicion = 0;
    while (posicion < notas.num && nuevo.nota < notas.al[posicion].nota) {
      posicion++;
    }
    
    // Inserción en una posición que puede ser cualquiera
    for (i = notas.num ; i > posicion ; i--) {
      notas.al[i] = notas.al[i - 1];
    }
    notas.al[posicion] = nuevo;
    notas.num++;
    
    // Mostrar todos los alumnos
    for(i = 0 ; i < notas.num ; i++) {
      printf("%d: %s. Nota: %.2f\n",
                i,
                notas.al[i].nombre,
                notas.al[i].nota);
    }
    printf("introducir otro (s/n)? ");
    scanf("%c%*c", &otro);
  } while(otro == 's' || otro == 'S');

  // eliminacion en cualquier posición
  printf("posicion a eliminar? ");
  scanf("%d%*c", &posicion);
  for(i = posicion ; i < notas.num - 1 ; i++) {
    notas.al[i] = notas.al[i+1];
  }
  notas.num--;
  
  // Mostrar otra vez todos los alumnos
  for(i = 0 ; i < notas.num ; i++) {
    printf("%d: %s. Nota: %.2f\n",
              i,
              notas.al[i].nombre,
              notas.al[i].nota);
  }
} 









