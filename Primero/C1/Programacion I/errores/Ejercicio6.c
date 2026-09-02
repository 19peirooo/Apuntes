/*
  Programa que utiliza scanf para guardar un nombre y un apellido
*/

#include <stdio.h>
#include <math.h> //Sobra



int main()
{
	char nombre[20];
	char apellido[20];
	
	
	printf("Introduce nombre: \n");
	scanf("%s", &nombre);
	printf("===> Nombre: %s\n", nombre);
	
	//while(getchar() != '\n')No hay llaves y a get char le falta () y sobra
	
	printf("Introduce apellido: \n");
	scanf("%s", &apellido);
	
	printf("===> Apellido: %s\n", apellido);
	
	
}