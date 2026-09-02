#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int generarNumeroAleatorio();
char generarOperadorAleatorio();
int generarResultado(int a, int b, char op);
int comprobarResultado(int a, int b, char op, int res);

int main(){
	int num1,num2,resultado,valido=0, correcto=0, sol;
	char operador;
	while (!correcto){
		while(!valido){
			num1 = generarNumeroAleatorio();
			num2 = generarNumeroAleatorio();
			operador = generarOperadorAleatorio();
			resultado = generarResultado(num1,num2,operador);
			valido = comprobarResultado(num1,num2,operador,resultado);
		}
		printf("%d %c %d = ",num1,operador,num2);
		scanf("%d", &sol);
		if (sol == resultado){
			correcto = 1;
		}
		else {
			correcto = 0;
		}
	}
	return 0;
}

int generarNumeroAleatorio(){
	srand(time(NULL));
	int randnum = rand() % 10;
	return randnum;
}

char generarOperadorAleatorio(){
	srand(time(NULL));
	int randnum = rand() % 3;
	char op;
	if (randnum == 0){
		op = '+';
	}
	else if (randnum == 1){
		op = '-';
	}
	else if (randnum == 2){
		op = '*';
	}
	else {
		op = '/';
	}
	return op;
}


int generarResultado(int a , int b, char op){
	if (op == '+'){
		return a+b;
	}
	else if (op == '-'){
		return a-b;
	}
	else if (op == '*'){
		return a*b;
	}
	else{
		if (b==0){
			return -1;
		}
		else{
			return a/b;
		}
	}
}

int comprobarResultado(int a, int b, char op, int res){
	int valido;
	if (res >= 200 || res <= 0){
		valido = 0;
	}
	else if ((a%b) != 0 && op == '/'){
		valido = 0;
	}
	else{
		valido = 1;
	}
	return valido;
}