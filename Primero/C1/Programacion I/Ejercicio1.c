/*Programa de Calificacion*/
#include <stdio.h>

int nota = 0;

void main(){
	printf("Introduce tu nota:\n");
	scanf("%d", &nota);
	if (nota < 5){
		printf("Suspenso");
	}
	else if (nota >= 9){
		printf("Has aprobado con un sobresaliente");
	}
	else{
		printf("Aprobao");
	}
}