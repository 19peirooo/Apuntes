#include <stdio.h>
#define TAM 50

int main(){
	char nombre[TAM];
	char newchar;
	char mayuschar;
	int strSize = 0;
	int ascii;
	while ((newchar = getchar()) != '\n'){
		nombre[strSize] = newchar;
		strSize++;
	}
	nombre[strSize] = '\0';
	printf("Nombre: %s \n", nombre);
	
	//Imprime los caracteres en vertical
	for(int i = 0; i < strSize; i++){
		putchar(nombre[i]);
		printf("\n");
	}
	
	//Imprime en mayuscula
	for(int i = 0; i < strSize; i++){
		ascii = (int)nombre[i];
		if (ascii <= 122 && ascii >= 90){
			ascii -= 32;
			mayuschar = (char)ascii;
			nombre[i] = mayuschar;
		}
		putchar(nombre[i]);
	}
	return 0;
	
}