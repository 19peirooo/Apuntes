#include <stdio.h>
#include <stdlib.h>

//Se puede ver tambien en ej2.c

char *leeLineaDinamica();

int main(int argc, char **argv){
	char *lineaLeida=NULL;
	
	printf("Escribe la linea:\n");
	lineaLeida = leeLineaDinamica();
	printf("Has Introducido: %s\n",lineaLeida);
}

char *leeLineaDinamica(){
	char *linea=NULL;
	int chars=0;
	char c;
	linea = (char*)malloc(chars);
	
	do{
		c=getchar();
		linea = (char*)realloc(linea,sizeof(char)*chars+1);
		linea[chars++] = c;
		chars++;
	}while (linea [chars-1] != '\n');
	linea[chars-1] = '\0';
	return linea;
}