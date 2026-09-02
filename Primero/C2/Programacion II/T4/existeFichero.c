#include <stdio.h>
#include <stdlib.h>

typedef enum bool_e{V=1,F=0}bool_e;

bool_e existeFichero(char *fichero);

int main(int argc, char **argv){
	if (argc > 1){
		if (existeFichero(argv[1])==V){
			printf("El fichero %s existe\n",argv[1]);
		} else {
			printf("El fichero %s no existe\n", argv[1]);
		}
	}
	return 0;
}

bool_e existeFichero(char *fichero){
	bool_e existe=V;
	
	FILE *f = NULL;
	f = fopen(fichero,"r+");
	if (f == NULL){
		existe = F;
	}
	return existe;
}