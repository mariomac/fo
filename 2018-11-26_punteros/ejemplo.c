#include <stdio.h>

// Ejemplo de uso de paso de structs por valor y por referencia

typedef struct {
  char titulo[100];
  int  referencia;
} t_libro;


// Paso por valor: no necesito modificar nada, sólo leerlo.
// Para acceder a los elementos de un struct, se usa un punto.
void muestra_libro(t_libro l) {
  printf("%s - Ref: %d\n", l.titulo, l.referencia);
}

// Paso por referencia: necesito modificar los valores de la variable
// original.
// Para acceder a los elementos del struct, se usa una "flecha" ->
void lee_libro(t_libro *pl) {
  printf("Titulo: ");
  scanf("%[^\n]%*c", pl->titulo);
  printf("Ref: ");
  scanf("%d", &(pl->referencia));
}

main() {
  t_libro l;
  lee_libro(&l);    // me modifica la variable 'l' original porque le paso un puntero
  muestra_libro(l);
}















