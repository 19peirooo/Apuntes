#include <stdio.h>
#include <stdlib.h>

#define TAMMAX 100

typedef enum colores_e{
	rojo=0,verde=1,azul=2,amarillo=3
}colores_e;

char *coloresNombres[]={"rojo","verde","azul","amarillo"}; //Array de traduccion

typedef struct autor_t{
	char nombre[TAMMAX];
	char apellido[TAMMAX];
	char nacionalidad[TAMMAX];
}autor_t;

typedef struct libro_t{
	char titulo[TAMMAX];
	char ISBN[TAMMAX];
	int numPaginas;
	char editorial[TAMMAX];
	autor_t *autor;
	colores_e color;
}libro_t;

libro_t nuevoLibro();
void mostrarLibro(libro_t libro);

int main(int argc, char **argv){
	
	libro_t libro = nuevoLibro();
	mostrarLibro(libro);
	
	return 0;
}
libro_t nuevoLibro(){
	libro_t l1;
	
	printf("Introduce el titulo del libro: ");
	scanf("%s", l1.titulo);
	while (getchar() != '\n');
	
	printf("Introduce el ISBN del libro: ");
	scanf("%s", l1.ISBN);
	while (getchar() != '\n');
	
	printf("Introduce el numero de paginas del libro: ");
	scanf("%d", &l1.numPaginas);
		
	printf("Introduce la editorial del libro: ");
	scanf("%s", l1.editorial);
	while (getchar() != '\n');
	
	printf("Introduce una opcion de color: \n"
	"0-Rojo\n"
	"1-Verde\n"
	"2-Azul\n"
	"3-Amarillo\n");
	scanf("%d", l1.color);
	while (getchar() != '\n');
	return l1;
}

void mostrarLibro(libro_t libro){
	printf("Titulo: %s\n", libro.titulo);
	printf("ISBN: %s\n", libro.ISBN);
	printf("Numero de Paginas: %d\n", libro.numPaginas);
	printf("Editorial: %s\n", libro.editorial);
	printf("Color: %s",coloresNombres[libro.color]);
}
