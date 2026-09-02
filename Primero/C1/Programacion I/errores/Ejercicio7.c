/*
  Programa que rellena una matriz, la imprime y calcula la suma de la diagonal
*/

#include <stdio.h>

#define NUM_FILAS  3
#define NUM_COLUMNAS  3

int main()
{
	int matriz[NUM_FILAS][NUM_COLUMNAS];
	int valor,suma=0;
	
	for (int i=0; i<NUM_FILAS; i++)
	{
		for (int j=0; j<NUM_COLUMNAS; j++)
		{
			printf("Introduce valor de componente [%d][%d]: \n", i,j);
			scanf("%d", &matriz[i][j]);
		}
	}
	printf("\n===> La matriz original es: \n");
	
	for (int i=0; i<NUM_FILAS; i++)
	{
		printf("%d:\t", i);
		for (int j=0; j<NUM_COLUMNAS; j++)//Pone Colunas no Columns
		{
			printf("%d\t", matriz[i][j]); // Cambio 1 por i
		}
		printf("\n");
	}
	

 	for (int i=0; i<NUM_FILAS; i++)
	{
		suma+=matriz[i][i];
	}
	printf("\n===> La suma de los valores de la diagonal es: %d \n", suma);
	
	
