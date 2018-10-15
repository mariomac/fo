#include <stdio.h>

// Programa que imprimirá una matriz identidad de lado N
main() {
    int n, fil, col;
    
    printf("n? ");
    scanf("%d", &n);

    // Cada iteración de este "for" imprimirá una fila distinta 
    for (fil = 1; fil <= n; fil++) {
        // Cada iteración de este "for" imprimirá la coordenada fil, col
        for (col = 1; col <= n; col++) {
            // Cada elemento será 0 o 1 según el valor de fil y col
            if (fil == col) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }

}

