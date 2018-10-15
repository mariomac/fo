#include <stdio.h>

main() {
    char c;
    char may;

    printf("Letra? ");
    do {
        // Sacamos un caracter del buffer
        scanf("%c", &c);

        if (c >= 'a' && c <= 'z') {
            // Si es una minúscula, la convertimos a mayúscula
            may = c - 'a' + 'A';
        } else {
            // Si no, la dejamos tal cual
            may = c;
        }
        printf("%c", may);
        
    // Repetimos la operación hasta que nos encontremos el caracter "intro"    
    } while (c != '\n');
}

