#include <stdio.h>

int main(){
	int num;
	printf("Introduce un numero: ");
	scanf("%d", &num);
	if (num % 2 == 0){
		printf("El numero es par \n");
	}
	else{
		printf("El numero es impar \n");
	}
	
	/*Program Salario*/
	/*float salario, incremento, porcentaje, nuevo_salario;
	printf("Introduzca el salario y el porcentaje de incremento: ");
	scanf("%f %f%", &salario,&porcentaje);
	printf("Salario Inicial: %f \n", salario);
	incremento = (porcentaje+100)/100;
	salario *= incremento;
	printf("Nuevo Salario: %f \n", salario);*/
	
	/*Programa Comparación*/
	/*int num1,num2,res;
	printf("Introduce dos enteros separados por una coma: ");
	scanf("%d,%d", &num1, &num2);
	res = (num1==num2);
	printf("%d", res);*/
	
	/*Operadores Logicos*/
	float num1,num2,num3,num4;
	int res;
	printf("Introduce 4 numeros de coma flotante separados por comas: ");
	scanf("%f,%f,%f,%f",&num1,&num2,&num3,&num4);
	res = (num1>num2 && num1>num3);
	printf("Resultado 1: %d \n", res);
	res = ((num3*num3)<(num2*num4) || (num3*2)<num2);
	printf("Resultado 2: %d \n", res);
	res = (num1%num4 > num3 && num1 > num4);
	printf("Resultado 3: %d \n", res);
	res = (num2/num4 == num1);
	printf("Resultado 4: %d \n", res);
	
	return 0;
	
}