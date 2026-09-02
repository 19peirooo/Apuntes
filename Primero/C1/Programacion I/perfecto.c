#include <stdio.h>

void main(){
	int num, suma = 1, resto;
	printf("Introduce un entero positivo: ");
	scanf("%d",&num);
	
	for (int i = 2; i < num; i++){
		resto = num % i;
		if (resto == 0){
			suma += i;
		} 
	}
	if (suma == num){
		printf("El numero es perfecto");
	}
	else{
		printf("El numero no es perfecto");
	}
}