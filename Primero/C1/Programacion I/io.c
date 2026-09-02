#include <stdio.h>

int main(){
	/*int w = 123;
	float v = 1024.251;
	
	printf(":%5d: \n",w);
	printf(":%-5d: \n",w);
	printf(":%05d: \n",w);
	printf(":%2d: \n",w);
	
	printf(":%12f: \n",v);
	printf(":%12.4f: \n",v);
	printf(":%-12.4f: \n",v);
	printf(":%12.1f: \n",v);
	printf(":%3f: \n",v);
	printf(":%.3f: \n",v);
	
	printf(":%12e: \n",v);
	printf(":%12.4e: \n",v);
	printf(":%12.1e: \n",v);
	printf(":%3e: \n",v);
	printf(":%.3e: \n",v);
	
	int numero, resultado;
	printf("Introduce un numero entero: ");
	resultado = scanf("%d", &numero);
	if (resultado!=1){
		printf("Incorrecto, %d no es un numero entero. Resultado %d", numero, resultado);
	}
	else{
		printf("Correcto, %d es un numero entero. Resultado %d", numero, resultado);
	}*/
	float area, ancho, largo;
	printf("Introduzca el ancho y el largo del triangulo, separandolos con una coma: ");
	scanf("%f,%f", &ancho,&largo);
	area = ancho * largo;
	printf("Area: %.4f", area);
	return 0;
}