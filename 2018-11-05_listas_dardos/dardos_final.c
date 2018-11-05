#include <stdio.h>

/**
 * DARDOS
 * 
 * Ejercicio en el que el dueño de un bar va anotando las puntuaciones de los
 * diferentes participantes en un torneo de dardos. El sistema irá manteniendo
 * una lista ordenada con todos los jugadores, de mayor a menor puntuación.
 */ 

/*
 * Constantes
 */
#define MAX_N 100   // Máxima longitud del nombre de un jugador
#define MAX_J 30    // Máximo número de jugadores
#define N_TIRADAS 5 // Número de tiradas por jugador

/*
 * Tipos de datos
 */

// Tipo de datos que representa a un jugador
typedef struct {
    char nombre[MAX_N];      // nombre del jugador
    int tiradas[N_TIRADAS];  // puntuación de las diversas tiradas
    int total;               // puntuación total
} t_jugador;

// Tipo de datos que representa una clasificación de jugadores
typedef struct {
    int num_j;                  // número de jugadores que realmente hay
    t_jugador jugadores[MAX_J]; // vector de jugadores, de tamaño máximo MAX_J
} t_clasificacion;

// Función principal, donde se implementará la lógica del programa
main() {
    t_jugador j;
    int i, nj, pos;

    // Definición de una lista vacía (num_j == 0)
    t_clasificacion clas = { 0, {} };
    int opcion;

    do {
        // Menu de opciones: añadir, eliminar, salir
        printf("Opciones:\n");
        printf("\t1 - Anyadir jugador.\n\t2 - Eliminar jugador.\n\t3 - Salir.\n");
        printf("Elige opcion: ");
        scanf("%d%*c", &opcion);

        switch(opcion) {
            case 1: // Opción: Añadir jugador.
                if (clas.num_j >= MAX_J) {
                    printf("Ya no caben mas jugadores\n");
                    break; // Salimos del switch porque no caben más en la lista
                }
                // Leer jugador por teclado
                printf("Nombre? ");
                scanf("%[^\n]%*c", j.nombre);
                j.total = 0;
                for (i = 0 ; i < N_TIRADAS ; i++) {
                    printf("Tirada %d: ", i+1);
                    scanf("%d", &j.tiradas[i]);
                    j.total += j.tiradas[i];
                }

                // Buscar en qué posición debe insertarse el nuevo jugador
                // para que la lista siga ordenada según puntuación total
                pos = 0;
                while (j.total < clas.jugadores[pos].total && pos < clas.num_j) {
                    pos++;
                }

                // Insertar nuevo jugador
                // Hacer espacio
                for (i = clas.num_j ; i > pos ; i--) {
                    clas.jugadores[i] = clas.jugadores[i-1];
                }
                // copiar jugador en posición calculada
                clas.jugadores[pos] = j;
                clas.num_j++; // aumentar tamaño lista
                break;
            case 2: // Opción: eliminar jugador
                if (clas.num_j <= 0) {
                    printf("La lista esta vacia\n");
                    break; // Salimos del switch porque no se puede eliminar nada
                }
                printf("Posicion a eliminar? ");
                scanf("%d%*c", &pos);
                pos--; // Como el usuario pondrá un número del 1 a num_j y nosotros
                       // querremos uno entre 0 y num_j-1, decrementamos para tener
                       // una posición del vector

                if (pos < 0 || pos >= clas.num_j) {
                    printf("Error! Posicion fuera de rango\n");
                    break; // salimos del switch porque el jugador ha puesto una
                           // posición que no existe
                }

                // Eliminación de elemento en posición "pos"
                // Operación inversa de la inserción. Copiamos desde "pos" hasta el
                // final, y decrementamos num_j
                for (i = pos ; i < clas.num_j ; i++) {
                    clas.jugadores[i] = clas.jugadores[i + 1];
                }
                clas.num_j--;
                break;
            case 3:
                // Opción: salir. No hacemos nada
                break;
            default:
                printf("Error! Opción incorrecta\n");
                break;
        }
        // Después de insertar o eliminar, mostramos la clasificación actualizada
        // Mostrar jugadores
        printf("La clasificación actualizada queda:\n");
        for (nj = 0 ; nj < clas.num_j ; nj++) {
            printf("\t%d : ", nj + 1); // Clasificado
            printf("%s (", clas.jugadores[nj].nombre);
            printf("%d", clas.jugadores[nj].tiradas[0]);
            for (i = 1 ; i < N_TIRADAS ; i++) {
                printf(" - %d", clas.jugadores[nj].tiradas[i]);
            }
            printf(") Total: %d\n", clas.jugadores[nj].total);
        }
    } while (opcion != 3);

}
