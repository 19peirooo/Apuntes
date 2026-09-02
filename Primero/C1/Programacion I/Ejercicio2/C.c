#include <stdio.h>

int contarPalabras(char texto);

int main(){
	char texto;
	int contador;
	printf("Introduce un texto que acabe con \" :q\": ");
	scanf("%c", &texto);
	contador = contarPalabras(texto);
	printf("El numero de palabras es %d", contador);
	return 0;
}

int contarPalabras(char texto){
	int palabras, fin = 1;
	char c;
	while(fin){
		c = getchar();
		printf("%c",c);
		if (c == ':'){
			c = getchar();
			if (c == 'q'){
				fin = 0;
			}
			else{
				fin = 1;
			}
		}
		else if (c == ' ' || c == '\t' || c == '\n'){
			palabras++;
		}
		else{
			palabras = palabras;
		}
	}
	return palabras;
}