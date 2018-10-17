#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Cambiar esta constante para permitir más intentos
#define MAX_INTENT 5

// Juego consistente en adivinar un número aleatorio entre 0 y 100
main() {
    // estas dos líneas generan aleatoriedad, como si "meneáramos un dado"
    srand(time(NULL));
    rand(); rand(); rand();

    // rand() retorna un entero aleatorio cualquiera. Lo limitamos al rango
    // [0 - 100]
    int secreto = rand() % 100 + 1;

    int jugador; // número introducido por el jugador
    int intentos = 0;

    do {
        printf("Adivina? [1-100]: ");
        scanf("%d", &jugador);
        intentos++;

        if (secreto > jugador) {
            printf("Te has quedado corto\n");
        } else if (secreto < jugador) {
            printf("Te has pasado\n");
        } else {
            printf("Acertaste!!!\n");
        }
    // El proceso de preguntar/comparar se repetirá mientras no se acierte
    // el número, y mientras no se supere el máximo de oportunidades
    } while (jugador != secreto && intentos < MAX_INTENT );

    if (intentos >= MAX_INTENT) {
        printf("Maximo de intentos agotado!\n");
    }
}

