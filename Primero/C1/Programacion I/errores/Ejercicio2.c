/*
  Programa que calcula el mayor, el menor y la media de una serie de números
   */
#include <stdio.h>

void main () {
	
	int cantidad;
	float menor = 0;
	float mayor = 0;
	float media = 0;
	float aux = 0;
	
	printf ("Introduce cuantos numeros son: ");
	scanf("%d", &cantidad);
	
	printf ("Introduce un numero: ");
	scanf ("%f", &menor); // Corrijo indentacion
	media = menor;
    mayor = menor;
	
	for (int i =1; i < cantidad; i++) //Sobra punto y coma
  {
		
		printf ("Introduce un numero: ");
		scanf ("%f", &aux);
		
		if (aux < menor){ //Faltan {} 
			menor = aux;
		}
		if (aux > mayor) {
			mayor = aux;
		}
		
		media = media + aux;
	}
	
	media = media / cantidad;
	printf("El menor es: %5.2f \n", menor);//Cambio g por f
	printf("El mayor es: %5.2f \n", mayor);
	printf ("La media es: %5.2f \n", media);
	
}