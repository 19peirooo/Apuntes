#include <stdio.h>
#include <stdlib.h>

typedef enum bool_e{V=1,F=0}bool_e;

bool_e existeFichero(char *fichero);

int main(int argc, char **argv){
	
	FILE *fIn=NULL;
	int c;
	
	fIn = fopen(argv[1],"r+");
	if(existeFichero(argv[1]) == F){
		printf("ERROR: Fichero no existe\n");
	}
	else{
		do{
			c=getc(fIn);
			if(c!=EOF){
				printf("%c",c);
			}
		}while(!feof(fIn));
		fclose(fIn);
	}
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