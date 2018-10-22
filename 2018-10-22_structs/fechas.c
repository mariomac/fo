#include <stdio.h>

typedef struct {
  int dia, mes, anyo;
} t_fecha; 

main() {
  t_fecha f1, f2;
  t_fecha anterior;
  
  printf("Fecha 1? (DD/MM/AAAA): ");
  scanf("%d/%d/%d", &f1.dia, &f1.mes, &f1.anyo);

  printf("Fecha 2? (DD/MM/AAAA): ");
  scanf("%d/%d/%d", &f2.dia, &f2.mes, &f2.anyo);
  
  // En vez de comparar campo a campo, como en el ejemplo fechas_spaguetti.c,
  // pasamos las fechas a un número en formato AAAAMMDD, de tal manera que es
  // sencillo comparar ambas fechas (simplemente comparamos un número).
  // Por ejemplo si 'f1' representara la fecha '25/7/2003',
  // nf1 tendría el valor numérico 20030725
  long nf1 = f1.anyo * 10000 + f1.mes * 100 + f1.dia;
  long nf2 = f2.anyo * 10000 + f2.mes * 100 + f2.dia;
  
  if (nf1 == nf2) {
    printf("son iguales\n");
  } else {
    if (nf1 < nf2) {
      // OJO! Comparamos nf1 y nf2 pero asignamos f1 o f2
      anterior = f1; 
    } else {
      anterior = f2;
    }
    printf("La fecha anterior es: %02d/%02d/%d\n",
        anterior.dia,
        anterior.mes,
        anterior.anyo);
  }

}

