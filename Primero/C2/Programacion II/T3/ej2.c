#include <stdio.h>
#include <stdlib.h>

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
		linea = (char*)realloc(linea,chars+1);
		linea[chars] = getchar();
		chars++;
	}while (linea [chars-1] != '\n');
	linea[chars-1] = '\0';
	return linea;
}