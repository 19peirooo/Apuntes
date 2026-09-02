#include <stdio.h>

int main(){
	double peso,altura, imc;
	
	printf("Introduce tu peso en kg: ");
	scanf("%lf", &peso);
	printf("Introduce tu altura en m: ");
	scanf("%lf", &altura);
	imc = peso / (altura*altura);
	printf("%lf",imc);
	return 0;
}