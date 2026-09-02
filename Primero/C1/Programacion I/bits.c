#include <stdio.h>

int main(){
	/*unsigned char num1,bit3;
	unsigned int uno=0;
	printf("Introduzca un numero entreo de 8 bits: \n");
	scanf("%f", &num1);
	
	bit3 = 1<<2;
	uno = bit3 & num1;
	uno = uno >> 2;
	printf("Resultado: %d", uno);*/
	char c1 = 'c';
	float f1 = 1.2;
	int e1 = 5;
	
	printf("Caracter: %c, Lugar De Memoria: %x \n", c1, &c1);
	printf("Float: %f, Lugar De Memoria: %x \n", f1, &f1);
	printf("Entero: %d, Lugar De Memoria: %x \n", e1, &e1);
	
	int i1, i2;
	char c1, c2;
	printf("Introduce los datos: \n");
	scanf("%d", &i1);
	scanf("%d", &i2);
	scanf("%c", &c1);
	scanf("%c", &c2);
	printf("valor de i1: %d\n", i1);
	printf("valor de i2: %d\n", i2);
	printf("valor de c1: %c\n", c1);
	printf("valor de c2: %c\n", c2);
	return 0;
}