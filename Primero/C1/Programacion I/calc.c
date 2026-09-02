#include <stdio.h>

double calculadora(int num1, int num2, char operador);

int main(){
	char op;
	int num1,num2;
	printf("Numero 1: ");
	scanf("%d", &num1);
	printf("Numero 2: ");
	scanf("%d", &num2);
	printf("Operador. + para suma, - para resta, x para multiplicar, / para dividir: ");
	scanf("%c", &op);
	printf("Resultado %lf", calculadora(num1,num2,op));
	return 0;
}

double calculadora(num1,num2,operador){
	if (operador == '+'){
		return num1+num2;
	}
	else if (operador == '-'){
		return num1-num2;
	}
	else if (operador == '*'){
		return num1*num2;
	}
	else{
		return num1/num2
	}
}