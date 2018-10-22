#include <stdio.h>

typedef struct {
  int dia, mes, anyo;
} t_fecha; 

main() {
  t_fecha f1, f2;
  t_fecha anterior;
  int iguales = 0;
  printf("Fecha 1? (DD/MM/AAAA): ");
  scanf("%d/%d/%d", &f1.dia, &f1.mes, &f1.anyo);

  printf("Fecha 2? (DD/MM/AAAA): ");
  scanf("%d/%d/%d", &f2.dia, &f2.mes, &f2.anyo);
  
  // Usamos el anyo como criterio prioritario
  if (f1.anyo < f2.anyo) {
    anterior = f1;
  } else if (f2.anyo < f1.anyo) {
    anterior = f2;
  } else if (f1.mes < f2.mes) { // Si el año es igual, comparamos por mes
    anterior = f1;
  } else if (f2.mes < f1.mes) {
    anterior = f2;
  } else if (f1.dia < f2.dia) { // Si también el mes es igual, comparamos por día
    anterior = f1;
  } else if (f2.dia < f1.dia) {
    anterior = f2;
  } else { // LLegado aquí, es que los años, meses y días son iguales
    iguales = 1;
  }
  
  if (iguales) {
    printf("son iguales\n");
  } else {
    printf("La fecha anterior es: %02d/%02d/%d\n",
        anterior.dia,
        anterior.mes,
        anterior.anyo);
  }

}

