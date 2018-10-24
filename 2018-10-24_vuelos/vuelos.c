#include <stdio.h>

// t_tiempo representa una fecha y hora
typedef struct {
    int dia;
    int mes;
    int anyo;
    int hh;
    int mm;
} t_tiempo;

// t_aeropuerto representa un código de aeropuerto de 3 caracteres
// NOTA: es más conveniente usar un vector
typedef struct {
    char c1, c2, c3;
} t_aeropuerto;

// t_extremo representa el extremo de un vuelo: aeropuerto y fecha
typedef struct {
    t_aeropuerto lugar;
    t_tiempo     fecha;
} t_extremo;

// t_vuelo representa un vuelo: extremos de origen y destino, precio por plaza,
// y plazas libres
typedef struct {
    t_extremo origen;
    t_extremo destino;
    int plazas;
    float precio;
} t_vuelo;

main() {
    // En esta variable, daremos valor a sus elementos para que represente
    // el siguiente vuelo:
    // BCN 29/10/2018 22:35 --> TYO 31/10/2018 07:30.
    // Plazas libres: 24. Precio: 625.30 euros
    t_vuelo v = {
        {{'B', 'C', 'N'}, {29, 10, 2018, 22, 35}}, // Origen
        {{'T', 'Y', 'O'}, {31, 10, 2018, 7, 30}}, // Destino
        24,     // plazas libres
        625.30, // precio
    };

    // Para imprimir los datos del vuelo, hemos de "navegar" desde la variable
    // 'v' hasta cada uno de los datos que queremos imprimir
    
    // Aeropuerto de salida
    printf("%c%c%c ", v.origen.lugar.c1, v.origen.lugar.c2, v.origen.lugar.c3);
    // Hora de salida
    printf("%02d/%02d/%04d %02d:%02d",
                    v.origen.fecha.dia, v.origen.fecha.mes, v.origen.fecha.anyo,
                    v.origen.fecha.hh, v.origen.fecha.mm);
    
    printf(" -> ");

    // Datos del destino. Cuando veamos el tema "funciones" veremos
    // cómo no tener que repetir casi el mismo código dos veces.
    printf("%c%c%c ",
                v.destino.lugar.c1, v.destino.lugar.c2, v.destino.lugar.c3);
    printf("%02d/%02d/%04d %02d:%02d",
                v.destino.fecha.dia, v.destino.fecha.mes, v.destino.fecha.anyo,
                v.destino.fecha.hh, v.destino.fecha.mm);

    // Otros datos: plazas y precio
    printf("\nPlazas libres: %d. Precio: %.2f euros\n", v.plazas, v.precio);
}