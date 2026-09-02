/*
Program C
*/

#include <stdio.h>

char caracter;

void main (){
	printf("Introduce un caracter:\n");
	scanf("%c" , &caracter);
	if (caracter == 's')||(caracter == 'S'){
		printf("Hola");
	}
	else{
		printf("Adios");
	}
}