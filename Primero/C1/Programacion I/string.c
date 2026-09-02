#include <stdio.h>

int main() {

    char nombre[40];
    int i = 0;
	int strSize;
	char newChar;
	
    printf("Ingrese su nombre y apellidos: ");
    
    while ((caracter = getchar()) != '\n') {
        nombre[strSize] = newChar;
        strSize++;
    }
    
    nombre_apellidos[i] = '\0';
    
    printf("\nNombre y apellidos: ");
    
	for (i = 0; i < strSize; i++){
		putchar(nombre[i]);
	}
	
	putchar('\n')
    return 0;