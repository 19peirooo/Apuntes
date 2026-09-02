#include <stdio.h>

int main(){
	float peso,altura;
	printf("Introduce tu peso: ");
	scanf("%f", &peso);
	
	printf("Introduce tu altura: ");
	scanf("%f", &altura);
	float imc = peso/(altura*altura);
	if (imc < 18.5){
		printf("Peso por debajo de lo normal");
	}
	else if (18.5 <= imc < 25){
		printf("Peso Saludable");
	}
	else if(25<=imc<=30){
		printf("Sobrepeso");
	}
	else{
		printf("Obesidad");
	}
	return 0;
}