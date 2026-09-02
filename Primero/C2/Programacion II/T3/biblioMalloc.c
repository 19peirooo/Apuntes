#include <stdio.h>
#include <stdlib.h>

typedef struct libro_t{
	int numPag;
	char *autor;
	char *titulo;
}libro_t;

typedef struct biblio_t{
	libro_t *libro;
	int num;
}biblio_t;

char *leeLineaDinamica();
libro_t pideLibro();

int main(int argc, char **argv){
	biblio_t biblio={NULL,0};
	
}

char* leeLineaDinamica(){
	char *linea;
	int tam;
	do{
		linea=(char*)realloc(linea,sizeof(char)*(tam+1);
		linea[tam++]=getchar();
	}while(linea[tam-1]!='\n');
	linea[tam-1] = '\0';
	return linea;
}

libro_t pideLibro(){
	libro_t l;
	printf("Introduce el autor:");
	l.autor = leeLineaDinamica();
	printf("Introduce el titulo:");
	l.titulo = leeLineaDinamica();
	printf("Introduce el numero de paginas: ");
	scanf("%d",&l.numPag);
	while(getchar()!='\n');
	return l;
}