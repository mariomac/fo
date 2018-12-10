# FO
Ejemplos de clase de Fonaments d'Ordinadors

## 10 Diciembre 2018

* [Ejemplo de ficheros](./2018-12-10_ficheros) (lectura y escritura de datos en disco).

## 5 Diciembre 2018

* [Ejemplos de uso de punteros](./2018-12-05_punteros_ejemplos)

## 3 Diciembre 2018

* [Tercera parte de Pokemon](./2018-12-03_pokemon_3) (incompleta). Queda como ejercicio:
    - Eliminar el pokemon de la bolsa en `sacar_pokemon`.
    - Hacer una función que muestre por pantalla todos los pokemons de una bolsa.

## 28 Noviembre 2018

* [Segunda parte de Pokemon](./2018-11-28_pokemon_2), en el que se incluye:
    - División el proyecto en varios archivos: `mapa.c`, `mapa.h`, `teclas.c`, `teclas.h` y `pokemon.c`.
    - Uso de punteros en la función `mueve`, usada para mover el personaje por el mapa.
    - Uso de `teclas.c` y `teclas.h` para leer entrada del teclado.
    - Para compilarlo todo: `gcc mapa.c pokemon.c teclas.c -o pokemon`

## 26 Noviembre 2018

* [Ejemplo de creación de librerías propias](./2018-11-26_ejemplo_librerias), dividiendo el código en diferentes archivos.

* Ejemplo de paso de argumentos por referencia, ya sea de [tipos básicos](./2018-11-26_punteros/intercambia.c) o de [structs](./2018-11-26_punteros/ejemplo.c)

## 21 Noviembre 2018

* [listas.c](./2018-11-21_lista_notas/listas.c) ejemplo de listas (sin funciones): inserción ordenada y eliminación en cualquier posición.

## 19 Noviembre 2018

* [exp.c](./2018-11-19_exponencial/exp.c) cálculo de función exponencial mediante funciones

## 14 Noviembre 2018

* [pokemon.c](./2018-11-14_pokemon/pokemon.c) (con ejemplo de uso de matrices, funciones, y hasta Emojis 🤯🤯🤯)

## 12 Noviembre 2018
* Ejemplo de funciones: [max.c](./2018-11-12_funciones/max.c)

## 7 Noviembre 2018

* Añadido ejemplo de matrices: [matrices.c](./2018-11-07_matrices/matrices.c)

## 5 Noviembre 2018
* Añadido ejemplo de listas: [dardos.c](./2018-11-05_listas_dardos/dardos.c)
* **Actualización**: [dardos_final.c](./2018-11-05_listas_dardos/dardos_final.c)
  contiene lo que sería un programa completo, que permite también eliminar jugadores.

## 29 Octubre 2018
* Añadidos ejemplos de [vectores](./2018-10-29_vectores):
    - `suma.c`: suma de todos los elementos de un vector
    - `comparacion.c`: compara si dos vectores son iguales (versión poco elegante, pero quizás
    más fácil de entender).
    - `comparacion_elegante.c`: compara si dos vectores son iguales (versión elegante y eficiente).

## 24 Octubre 2018
* Añadido ejemplo [vuelos.c](2018-10-24_vuelos/vuelos.c)

## 22 Octubre 2018

* Añadidos ejemplos de clase sobre structs:
    - `hora.c`
    - `fechas_spaguetti.c` con la solución "spaguetti", un poco menos liosa que la he hemos hecho en clase.
    - `fechas.c` con la solución "elegante", pasando las fechas a un formato numérico, más fácilmente comparable.
