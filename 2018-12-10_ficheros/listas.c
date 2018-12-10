#include <stdio.h>
#define MAX 100
#define ARCHIVO "notas.txt"

typedef struct {
  char nombre[MAX];
  float nota;
} t_alumno;

typedef struct {
  int num;
  t_alumno al[MAX];
} t_lista_notas;

// Ver descripción de cada función más abajo, junto a la implementación
t_alumno lee_alumno();
int busca_posicion(t_alumno nuevo, t_lista_notas notas);
void inserta(t_alumno nuevo, int posicion, t_lista_notas *notas);
void mostrar_notas(t_lista_notas notas);

void guarda_notas(t_lista_notas n);
void lee_notas(t_lista_notas *n);

main() {
  t_lista_notas notas;
  t_alumno nuevo;
  int posicion;
  char otro;
  
  // Leer notas de disco, si el archivo existe
  lee_notas(&notas);
  mostrar_notas(notas);

  do {
    // Leer un alumno por teclado
    nuevo = lee_alumno();
    // Buscar en qué posición debe ir según su orden de nota
    posicion = busca_posicion(nuevo, notas);
    // Insertar al alumno en la posición calculada
    inserta(nuevo, posicion, &notas);

    printf("Lista actualizada:\n");
    mostrar_notas(notas);
    
    printf("introducir otro (s/n)? ");
    scanf("%c%*c", &otro);
  } while(otro == 's' || otro == 'S');

  printf("Guardando datos en disco...\n");
  guarda_notas(notas);
} 

// Lee por teclado los datos de un alumno, y lo retorna.
t_alumno lee_alumno() {
  t_alumno nuevo;
  printf("Nombre: ");
  scanf("%[^\n]%*c", nuevo.nombre);
  printf("Nota: ");
  scanf("%f%*c", &nuevo.nota);
  return nuevo;
}

// Busca en qué posición debería ir el alumno "nuevo" en la lista de notas para que
// ésta lista siga ordenada por orden decreciente de notas.
int busca_posicion(t_alumno nuevo, t_lista_notas notas) {
  int posicion = 0;
  while (posicion < notas.num && nuevo.nota < notas.al[posicion].nota) {
    posicion++;
  }
  return posicion;
}

// Inserta el alumno nuevo en la posición dada para la lista de notas que se pasa
// por referencia (puntero *notas)
void inserta(t_alumno nuevo, int posicion, t_lista_notas *notas) {
  int i;
  for (i = notas->num ; i > posicion ; i--) {
    notas->al[i] = notas->al[i - 1];
  }
  notas->al[posicion] = nuevo;
  notas->num++;
}

// Muestra las notas de todos los alumnos
void mostrar_notas(t_lista_notas notas) {
  int i;
  for(i = 0 ; i < notas.num ; i++) {
    printf("%s. Nota: %.2f\n",
              notas.al[i].nombre,
              notas.al[i].nota);
  }
}

// Guarda las notas en disco según el siguiente formato:
// La primera línea es el número de alumnos
// Luego, cada línea es el nombre seguido de dos puntos : y la nota
/* Ejemplo:
3
Laia:9.000000
Miquel:7.500000
Maria:6.000000
*/
void guarda_notas(t_lista_notas n) {
    FILE *fp = fopen(ARCHIVO, "w");
    if (fp == NULL) {
      printf("error escribiendo archivo!");
      return;
    }
    fprintf(fp, "%d\n", n.num);
    int i;
    for (i = 0 ; i < n.num ; i++) {
      fprintf(fp, "%s:%f\n", n.al[i].nombre,
                             n.al[i].nota);
    }
    fclose(fp);
}

// Lee las notas de disco, según e formato del archivo generado en guarda_notas
// Si el archivo no existe, devuelve una lista de notas vacía
void lee_notas(t_lista_notas *n) {
  FILE *fp = fopen(ARCHIVO, "r");
  if (fp == NULL) {
    printf("Se creará un nuevo archivo\n");
    n->num = 0;
    return;
  }
  fscanf(fp, "%d%*c", &n->num);
  int i;
  for (i = 0 ; i < n->num ; i++) {
    fscanf(fp, "%[^:]%*c%f%*c",
                       n->al[i].nombre,
                       &n->al[i].nota);
  }
  fclose(fp);
  
}
































