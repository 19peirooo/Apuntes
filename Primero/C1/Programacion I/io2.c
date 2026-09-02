#include <stdio.h>

int main(){
	int num1;
	printf("Introduce un numero: ");
	scanf("%d", &num1);
	if (num1 % 2 == 0){
		printf("El numero es par \n");
	}
	else{
		printf("El numero es impar \n");
	}
	
	/*Program Salario*/
	float salario, incremento, porcentaje, nuevo_salario;
	printf("Introduzca el salario y el porcentaje de incremento: ");
	scanf("%f %f%", &salario,&porcentaje);
	printf("Salario Inicial: %f \n", salario);
	incremento = (porcentaje+100)/100;
	salario *= incremento;
	printf("Nuevo Salario: %f \n", salario);
	return 0;
}