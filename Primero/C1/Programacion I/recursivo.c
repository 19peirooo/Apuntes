#include <stdio.h>

int factorial(int n);

int main(){
	int result, numero;
	printf("Introduce el numero factorial: \n");
	scanf("%d", &numero);
	result = factorial(numero);
	printf("El factorial es: %d", result);
	return 0;
}

int factorial(int n){
	int res;
	if (n == 0){
		res = 1;
	}
	else{
		res = n*factorial(n-1);
	}
	return res;
}