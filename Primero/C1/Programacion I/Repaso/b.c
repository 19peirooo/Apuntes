#include <stdio.h>

int main(){
	unsigned int num, factorial = 1;
	
	do{
		printf("Introduce un entero positivo: ");
		scanf("%d", &num);
	} while ( num <= 0);
	for (int i = 1; i < num+1; i++){
		factorial *= i;
	}
	printf("%d", factorial);
}