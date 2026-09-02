/*Programa Comparar 3 numeros*/
#include <stdio.h>

int max,num1,num2,num3;

void main(){
	printf("Ingresa 3 numeros: ");
	scanf("%d %d &d",&num1,&num2,&num3);
	
	if (num1 > num2){
		max = num1;
	}
	else if (num1 < num2){
		max = num2;
	}
	else{
		max = num1;
	}
	
	if (max < num3){
		max = num3;
	}
	
	printf("El numero mas grande es: ");
	printf("%d",max);
}