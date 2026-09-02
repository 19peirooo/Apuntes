//Concatenar con punteros
#include <stdio.h>

#define TAM 50

void main(){
	char cadena1[] = "Hola";
	char cadena2[] = "Pepe";
	char cadena3[TAM];
	char *pcadena1,*pcadena2,*pcadena3;
	pcadena1 = cadena1;
	pcadena2 = cadena2;
	pcadena3 = cadena3;
	int i;
	
	while(*pcadena1 != '\0'){
		*pcadena3 = *pcadena1;
		pcadena1++;
		pcadena3++;
	}
	*pcadena3 = ' ';
	pcadena3++;
	while(*pcadena2 != '\0'){
		*pcadena3 = *pcadena2;
		pcadena2++;
		pcadena3++;
	}
	printf("%s", cadena3);
}