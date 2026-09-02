#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define FILS 3
#define COLS 4

void ej2();

void main(){
	ej2();
}

void ej2(){
	int mat[3][4];
	int randnum,i,j;
	srand((unsigned int)getpid);
	
	//Pone numeros aleatorios a cada elemento de la matriz
	for (i = 0; i < FILS;i++){
		for(j = 0; j < COLS; j++){
			randnum = rand()%11;
			mat[i][j] = randnum;
		}
	}
	
	//Imprime la matriz por filas
	printf("Matriz por filas: \n");
	for (i = 0; i < FILS;i++){
		for(j = 0; j < COLS; j++){
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
	printf("\n")
	//Imprime la matriz por columnas
	printf("Matriz por columnas: \n");
	for (j = 0; j < COLS;j++){
		for(i = 0; i < FILS; i++){
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
}