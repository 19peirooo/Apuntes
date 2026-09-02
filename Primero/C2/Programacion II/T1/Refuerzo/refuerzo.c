#include <stdio.h>
#include <stdlib.h>

#define TAM 100

void comprobarContraseña(char *ent, char *pswd);

//Imprimir caracter por caracter los parametros pasados
int main(int argc, char **argv){
	int j = 0;
	for (int i = 1; i < argc; i++){ //Por cada parametro pasado
		j = 0;
		while(argv[i][j] != '\0'){
			printf("%c\n", argv[i][j]);
			j++;
		}
		printf("\n");
	}
}


