#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILAS 5
#define COLUMNAS 5

int main() {
    // Inicializar la semilla para la generación de números aleatorios
    srand(time(NULL));

    // Declarar la matriz
    float matriz[FILAS][COLUMNAS];

    // Llenar la matriz con números aleatorios entre 0 y 1
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            matriz[i][j] = (float)rand() / RAND_MAX;
        }
    }

    // Imprimir la matriz
    printf("Matriz de números aleatorios entre 0 y 1:\n");
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("%.2f\t", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}