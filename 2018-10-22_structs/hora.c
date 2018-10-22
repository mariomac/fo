#include <stdio.h>

typedef struct {
  int hora;
  int minuto;
} t_tiempo; 

main() {
  t_tiempo momento;
  
  do {
    printf("Escribe una hora (HH:MM): ");
    scanf("%d:%d", &momento.hora, &momento.minuto); 
  } while( momento.hora < 0
           || momento.minuto < 0
           || momento.hora > 23
           || momento.minuto > 59);
  
  printf("Has escrito: %02d:%02d\n",
              momento.hora, momento.minuto);
              
              
              
  
}

