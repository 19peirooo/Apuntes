#include <stdio.h>
#include <stdlib.h>

void comprobarContraseña(char *ent, char *pswd, int size);

//Imprimir caracter por caracter los parametros pasados
int main(int argc, char **argv){
	char contrasenya[] = "diegomarica";
	int tam = sizeof(contrasenya);
	if (argc != 2){
		printf("Numero de parametros incorrectos");
	}
	else{
		comprobarContraseña(argv[1],contrasenya, tam);
	}
	return 0;
}

void comprobarContraseña(char *ent, char *pswd, int size){
	int esIgual = 1, i = 0;
	while (esIgual && i < size){
		if (*ent != *pswd){
			esIgual = 0;
		}
		else{
			ent++;
			pswd++;
			i++;
		}
	}
	if (esIgual){
		printf("Contrasenya Correcta");
	}
	else{
		printf("Contrasenya Erronea");
	}
}