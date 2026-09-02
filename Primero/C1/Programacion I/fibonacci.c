#include <stdio.h>

int fibonacci(int n);

int main(){
	int num, result;
	printf("Que numero de la fibonacci quieres encontrar: ");
	scanf("%d", &num);
	result = fibonacci(num);
	printf("%d", result);
}

int fibonacci(int n){
	int res;
	if (n <= 0){
		res = 0;
	}
	else if (n == 1){
		res = 1;
	}
	else{
		res = fibonacci(n-1) + fibonacci(n-2);
	}
	return res;
}