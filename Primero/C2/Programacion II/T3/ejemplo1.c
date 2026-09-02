#include <stdio.h>
#include <stdlib.h>

#define TAM 10

int main(int argc, char **argv){
	int *arr = NULL;
	int contador=0;
	arr = (int *)malloc(sizeof(int)*TAM);
	
	while (contador < TAM){
		printf("Introduce el numero %d:", contador+1);
		scanf("%d", &arr[contador]);
		contador++;
	}
	
	contador = 0;
	while (contador < TAM){
		printf("Numero %d: %d\n", contador+1, arr[contador]);
		contador++;
	}
	
	free(arr);
	return 0;
}