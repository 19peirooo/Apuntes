#include <stdio.h>

int main(){
	const float pi = 3.141592;
	const int num = 40;
	
	printf("Entero: %16d",num);
	printf("\nPunto Flotante: %10.2f", pi);
	
	float num1;
	printf("Introduce un numero: ");
	scanf("%f", &num1);
	if ((num1 % 2) == 0){
		printf("El numero es par");
	}
	else{
		printf("El numero es impar");
	}
	return 0;
}