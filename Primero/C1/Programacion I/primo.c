#include <stdio.h>

void main(){
	int num, resto, esPrimo = 0;
	
	printf("Introduce un numero: ");
	scanf("%d", &num);
	
	for(int i = 2; i <= num; ++i){
		resto = num % i;
		if (resto == 0 && num != i){
			esPrimo = 0;
			break;
		}
		else{
			esPrimo = 1;
		}
	}
	if (esPrimo){
		printf("Numero Primo");
	}
	else{
		printf("Numero no primo");
	}
}