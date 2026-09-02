#include <stdio.h>

int secuencia(int num1,int num2);

int main(){
	int num1,num2, res;
	printf("2 numeros guarra separados por coma: ");
	scanf("%d,%d",&num1,&num2);
	res = secuencia(num1,num2);
	printf("Suma: %d", res);
	return 0;
}

int secuencia(num1,num2){
	int suma;
	for (i = num1; i <= num2; i++){
		suma+=i
	}
	return 0;
}