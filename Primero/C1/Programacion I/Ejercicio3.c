/*Ejercicio 3: Suma y resta*/

#include <stdio.h>

int num1,num2,resultado;

void main(){
	printf("Escribe 2 numeros: ");
	scanf("%d %d",&num1,&num2);
	
	if (num1 >= num2){
		resultado = num1 - num2;
	}
	else{
		resultado = num1 + num2;
	}
	printf("El resultado es: ");
	printf("%d",resultado);
}