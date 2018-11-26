#include <stdio.h>

// Como esta función modifica el valor de las variables originales,
// no puedo usar paso de parámetro por valor (modificaría copias
// temporales) sino paso de parámetro por referencia (modifico las
// variables originales a través de punteros a éstas).
void intercambia(char *a, char *b) {
  char c;
  c = *a;
  *a = *b;
  *b = c;
}

main() {
  char a = 'A', b = 'Z';
  printf("Antes de intercambiar: a = %c, b = %c\n", a, b);
  
  // Le paso punteros a las variables originales para que me las
  // modifique
  intercambia(&a, &b);
  
  printf("Despues de intercambiar: a = %c, b = %c\n", a, b);

}
