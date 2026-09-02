#include <stdio.h>

int areaCuadrado(int altura, int base);

int main(){
	int altura, base,area;
	printf("Introduce la altura: ");
	scanf("%d", &altura);
	printf("Introduce la base: ");
	scanf("%d", &base);
	area = areaCuadrado(altura,base);
	printf("Area: %d",area);
	return 0;
}

int areaCuadrado(altura,base){
	return altura*base;
}