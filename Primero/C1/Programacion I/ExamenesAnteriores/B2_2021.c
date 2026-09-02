#include <stdio.h>

#define MAX_TAM 200

int esVocal(char c);
int esConsonante(char c);
int niVocalniConsonante(char c);
int esValido(char c);
void calcularPalabras(char *frase, int *palabras);

void main(){
	char frase[MAX_TAM]={'\0'};
	char c;
	int strSize=0, cadenaValida=0;
	int vocales=0, consonantes=0, caracteres, palabras=1;
	
	while (!cadenaValida){
		for (int i = 0; i < MAX_TAM; i++){
			frase[i] = '\0';
		}
		strSize = 0;
		
		printf("Introduce una frase (solo minusculas): ");
		while ((c = getchar())!='\n'){
			frase[strSize] = c;
			strSize++;
		}
		if (strSize > MAX_TAM){
			cadenaValida = 0;
			printf("Cadena demasiado larga \n");
		}
		else{
			cadenaValida = 1;
			for (int i = 0; frase[i] != '\0' && cadenaValida; i++){
				cadenaValida = esValido(frase[i]);
			}
			if (!cadenaValida){
				printf("Hay algun caracter erroneo. Prueba otra vez \n");
			}
		}	
	}
	for (int i = 0; frase[i] != '\0'; i++){
		if (esVocal(frase[i])){
			vocales++;
		}
		else if (esConsonante(frase[i])){
			consonantes++;
		}
		else if (niVocalniConsonante(frase[i])){
			caracteres++;
		}
		else{
			caracteres = caracteres;
		}
	}
	calcularPalabras(frase, &palabras);
	caracteres = caracteres + vocales + consonantes;
	printf("La frase tiene: %d caracteres, %d vocales, %d consonantes y %d palabras \n", caracteres, vocales, consonantes, palabras);
}

int esValido(char c){
	return (((c >= 'a') && (c <='z')) || c == ' ');
}

int esVocal(char c){
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int esConsonante(char c){
	return (c >= 'a' && c <= 'z' && !(esVocal(c)));
}

int niVocalniConsonante(char c){
	return (c == ' ');
}

void calcularPalabras(char *frase, int *palabras){
	for (int i = 0; *frase != '\0'; i++){
		if (*frase == ' '){
			(*palabras)++;
		}
		frase++;
	}
}