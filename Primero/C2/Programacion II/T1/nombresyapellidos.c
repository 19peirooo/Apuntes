#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 100

int contieneComa(char *cadena);
void concatena(char *cadena1, char *cadena2);

int main(int argc, char **argv){
	char nombre[TAM_MAX]={'\0'};
	char apellidos[TAM_MAX]={'\0'};
	int palabraspreApellidos=0;
	int tieneComa;
	for (int i = 1; i < argc && !tieneComa; i++){
		tieneComa = contieneComa(argv[i]);
		if (!tieneComa){
			palabraspreApellidos++;
		}
	}
	for (int i = 1; i < palabraspreApellidos; i++){
		concatena(apellidos, argv[i]);
	}
	for (int i = (palabraspreApellidos+1); i < argc; i++){
		concatena(nombre, argv[i]);
	}
	printf("El nombre del Alumno es: %s %s", nombre, apellidos);
}

 int contieneComa(char *cadena){
	int coma = 0;
	do{
		if (*cadena == ','){
			coma = 1;
		}
	}while(*cadena != '\0' && coma == 0);
	return coma;
 }
 
 void concatena(char *cadena1, char *cadena2){
	int tamDestino=0;
	while(*cadena1 != '\0'){
		cadena1++;
		tamDestino++;
	}
	do{
		*cadena1 = *cadena2;
		cadena1++;
		cadena2++;
	}while (*cadena2 != '\0' && *cadena2 != ',');
	*cadena1 = ' ';
 }