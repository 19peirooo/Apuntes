#include <stdio.h>
#include <math.h>

#define PI 3.1416

float GradosARadianes(int grados);
int factorial(int n);
float calcularSeno(float angulo, int precision);

void main(){
	float anguloRad, resultado;
	int precision, err=0,anguloGrad;
	while (err != 1){
		printf("Introduzca en angulo en grados: ");
		err = scanf("%d", &anguloGrad);
	}
	err = 0;
	while (err != 1){
		printf("Introduzca la precision deseada: ");
		err = scanf("%d", &precision);
	}
	anguloRad=GradosARadianes(anguloGrad);
	resultado = calcularSeno(anguloRad,precision);
	printf("El seno de %d es: %f",anguloGrad,resultado);
}

float GradosARadianes(int grados){
	return ((float)grados/360)*(2*PI);
}

int factorial(int n){
	if (n == 1 || n == 0){
		return 1;
	}
	else{
		return n*factorial(n-1);
	}
}

float calcularSeno(float angulo, int precision){
	float res;
	for (int i = 0; i <= precision; i++){
		res =+ pow(-1,i) * (pow(angulo,(2*i)+1)/factorial((2*i)+1));
	}
	return res;
}