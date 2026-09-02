#include <stdio.h>

int main(){
	char c;
	int contador = 0;
	scanf("%c",c);
	
	do {
		contador++;
		c= getchar();
	} while (c != '\n' && c != ' ');
	printf("%d", contador);
}