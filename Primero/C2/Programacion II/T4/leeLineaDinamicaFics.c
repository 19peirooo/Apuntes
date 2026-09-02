#include <stdio.h>
#include <stdlib.h>

char *leeLineaDinamicaFichero(FILE*f)
bool_e existeFichero(char *fichero);

int main(int argc, char **argv){
	FILE *f = NULL;
	char *linea
	if (argc > 1){
		if (existeFichero(argv[1])==V){
			printf("El fichero %s existe\n",argv[1]);
			while (!feof(f)){
				linea=leeLineaDinamicaFichero(f);
				printf("%s\n",linea);
				free(linea);
			}
			fclose(f);z
		} else {
			printf("El fichero %s no existe\n", argv[1]);
		}
	}
}

char *leeLineaDinamicaFichero(FILE*f){
	char *linea=NULL;
	int chars=0;
	char c;
	
	do{
		c = getc(f);
		if (c != EOF){
			linea = (char*)realloc(linea,sizeof(char)*chars+1);
			linea[chars++] = c;
		}
	}while ((linea [chars-1] != '\n') && (!feof(f))); //Mientras que no hayamos leido el ultimo caracter o no se acabe el fichero
	if (chars > 0){
		linea[chars-1] = '\0';
	}
	return linea;
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