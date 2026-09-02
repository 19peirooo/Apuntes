#include <stdio.h>

#define TAM 15

int compararCadenas(char n1[], char n2[], int tamaño);

int main(){
	char nombre1[TAM], nombre2[TAM]; //Cadenas para los nombres
	char caracter1,caracter2;
	int tamaño1,tamaño2;
	int i = 0; //Variable intermed
	int valido = 0; // Para comprobar si los nombres son de tamaño adecuado
	int sonIguales = 0; // Variable para comparar si son iguales
	
	while (!valido){
		tamaño1 = 0;
		printf("Ingrese el nombre del primer alumno(14 caracteres maximo): ");
		while ((caracter1 = getchar()) != '\n'){
			nombre1[tamaño1] = caracter1;
			tamaño1++;
		}
		if (tamaño1 >= TAM){
			printf("Nombre muy largo\n");
			for (i = 0; i < TAM;i++){ //Vacio la cadena para que se pueda volver a escribir en ella
				nombre1[i] = ' ';
			}
			valido = 0;
		}
		else{
			valido = 1;
		}
	}
	valido = 0;
	while (!valido){
		tamaño2 = 0;
		printf("Ingrese el nombre del segundo alumno(14 caracteres maximo): ");
		while ((caracter2 = getchar()) != '\n'){
			nombre2[tamaño2] = caracter2;
				tamaño2++;
		}
		if (tamaño2 >= TAM){
			printf("Nombre muy largo\n");
			for (i = 0; i < TAM;i++){ //Vacio la lista para que se pueda volver a escribir en ella
				nombre2[i] = ' ';
			}
			valido = 0;
		}
		else{
			valido = 1;
		}
	}
	nombre1[tamaño1] = '\0';
	nombre2[tamaño2] = '\0';
	if (tamaño1 != tamaño2){
		sonIguales = 0;
	}
	else{
		sonIguales = compararCadenas(nombre1,nombre2, tamaño1);
	}
	if (sonIguales){
		printf("Los nombres son iguales\n");
	}
	else{
		printf("Los nombre no son iguales\n");
	}
	printf("La longitud del primer nombre es: %d\n", tamaño1);
	printf("La longitud del segundo nombre es: %d\n", tamaño2);
}

int compararCadenas(char n1[],char n2[], int tamaño){
		 int i = 0;
		 int igual = 1;
		 while (igual && i < tamaño){ // Mira si los elemento de cada array son iguales
			 if (n1[i] == n2[i]){
				 i++;
			 }
			 else{
				 igual = 0;
			 }
		 }
		 return igual;
}