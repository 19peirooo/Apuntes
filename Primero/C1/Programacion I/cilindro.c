#include <stdio.h>

const double pi = 3.1415926535;

int main(){
	float radio;
	float area;
	printf("Introduce el radio de el circulo del cilindro: ");
	scanf("%f", &radio);
	area = pi * (radio * radio);
	printf("El area de el circulo es: %f \n", area);
	
	double altura;
	float volumen;
	printf("Introduce la altura del cilindro: ");
	scanf("%lf",&altura);
	volumen = area * altura;
	printf("El volumen del cilindro es: %f", volumen);
	return 0;
}