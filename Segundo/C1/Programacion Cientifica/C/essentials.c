#include <stdio.h>
#include <stdlib.h>

void imprimeArray(int* arr, int numElementos){
    for (int i = 0; i < numElementos; i++){
        printf("%d;", arr[i]);
    }
    printf("\n");
}