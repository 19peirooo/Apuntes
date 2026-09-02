#include <stdio.h>
#include <stdlib.h>

#define TAM 3

void imprimeMatriz(float matriz[TAM][TAM]);

int main(int argc , char **argv){
	float mat[TAM][TAM]={0};
	float valor=0;
	char *error;
	int k = 1;
	
	if ((argc - 1) < 9){
		printf("Numero de parametros insuficiente. Solo se pueden recibir 9\n");
	}
	else if ((argc -1) > 9){
		printf("Demasiados parametros recibido. Solo se pueden recibir 9");
	}
	else {
		for (int i = 0; i < TAM; i++){
			for (int j = 0; j < TAM; j++){
				valor = strtof(argv[k],&error);
				if (*error != '\0'){
					printf("Error, parametro no es numerico\n");
				}
				else{
					mat[i][j] = valor;
					k++;
				}
			}
		}
		imprimeMatriz(mat);
	}
	
	return 0;
}

void imprimeMatriz(float matriz[TAM][TAM]){
	for (int i = 0; i < TAM; i++){
		for(int j = 0; j < TAM; j++){
			printf("%f ", matriz[i][j]);
		}
		printf("\n");
	}
}