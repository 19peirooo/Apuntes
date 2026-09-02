#include <stdio.h>

void obtenerDosVariables(int *valor1, int *valor2) {
    // Asignar valores a través de los punteros
    *valor1 = 10;
    *valor2 = 20;
}

int main() {
    int resultado1, resultado2;

    // Llamar a la función y pasar las direcciones de las variables
    obtenerDosVariables(&resultado1, &resultado2);

    // Imprimir los resultados
    printf("Valor 1: %d\n", resultado1);
    printf("Valor 2: %d\n", resultado2);

    return 0;
}
