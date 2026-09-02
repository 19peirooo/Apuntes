#include <stdio.h>
#include <stdlib.h>

typedef struct lista_t{
	char **nombres;
	int num;
}lista_t;

char *leeLineaDinamica();
void addNombre(lista_t *listaNombres, char *nombre);
int main(int argc, char ** argv){
	
	lista_t listaNombres={.nombres = NULL, .num = 0};
	int salir = 0;
	char *nombre;
	do{
		printf("Introduce el nombre del alumno %d:", listaNombres.num+1);
		nombre = leeLineaDinamica();
		if(nombre[0] == '\0'){ // Si cadena vacia
			salir = 1;
		} 
		else {
			addNombre(&listaNombres,nombre);
		}
	}while(!salir);
	for (int i = 0; i < listaNombres.num; i++){
		printf("Alumno: %s\n", listaNombres.nombres[i]);
	}
	
	for (int i = 0; i < listaNombres.num; i++){
		free(listaNombres.nombres[i]);
	}
	free(listaNombres.nombres);
	return 0;
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

void addNombre(lista_t *listaNombres, char *nombre){
	listaNombres->nombres=(char**)realloc(sizeof(char*)*(listaNombres->num+1));
	listaNombres->nombres[listaNombres->num++] = nombre;
}