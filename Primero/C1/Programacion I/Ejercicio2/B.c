#include <stdio.h>

int CalcSuma(int M);

int main(){
	int num, resultado;
	printf("Introduce un entero: ");
	scanf("%d", &num);
	resultado = CalcSuma(num);
	printf("La suma de los digitos es: %d", resultado);
	return 0;
}

int CalcSuma(int M){
	int res;
	if (M < 10){
		res = M;
	}
	else{
		res = CalcSuma(M/10)+(M%10);
	}
	return res;
}