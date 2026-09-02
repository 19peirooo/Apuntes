#include <stdio.h>
#include <stdlib.h>

#define TAMMAX 75
#define TAM_BIB 100

struct autor_t{
	char nombre[TAMMAX];
	char apellido[TAMMAX];
	char nacionalidad[TAMMAX];
};

struct libro_t{
	char titulo[TAMMAX];
	char ISBN[TAMMAX];
	int numPaginas;
	char editorial[TAMMAX];
	struct autor_t autor;
};

//Lista
struct listaLibros_t{
	struct libro_t libs[TAM_BIB];
	int size; //Tamaño maximo
	int numLibrosIntroducidos; 
};

struct autor_t nuevoAutor();
struct libro_t nuevoLibro();
void mostrarAutor(struct autor_t autor);
void mostrarLibro(struct libro_t libro);
struct listaLibros_t buscaPorAutor(struct listaLibros_t libros, char autor[TAMMAX]);
int comparaCadenas(char *c1, char *c2);



int main(int argc, char **argv){
	int salir = 0, opcion = -1, i = 0;
	char nombreAutor[TAMMAX]={'\0'};
	struct listaLibros_t biblio={
		.size = TAM_BIB,
		.numLibrosIntroducidos = 0
	};
	
	while (!salir){
		opcion=-1;
		printf("Bienvenido a la Bibioteca. Elige una opcion: \n");
		printf("1. Nuevo libro a la galeria\n");
		printf("2. Nuevo Autor\n");
		printf("3. Listado Completo de los Libros\n");
		printf("4. Buscar Libro por Autor\n");
		printf("5. Salir\n");
		printf("Opcion: ");
		scanf("%d", &opcion);
		
		switch (opcion){
			case 1:
				if (biblio.numLibrosIntroducidos < biblio.size){
					biblio.libs[biblio.numLibrosIntroducidos] = nuevoLibro();
					biblio.numLibrosIntroducidos++;
				}
				else{
					printf("Biblioteca Completa. No se pueden añadir mas libros");
				}
				break;
			case 2:
				break;
			case 3:
				for (int i = 0; i<biblio.numLibrosIntroducidos; i++){
					mostrarLibro(biblio.libs[i]);
				}
				break;
			case 4:
				struct listaLibros_t res={
					.size=TAM_BIB,
					.numLibrosIntroducidos=0
					
				};
				printf("Introduce el nombre del autor: ");
				scanf("%s", nombreAutor);
				while (getchar() != '\n');
				res=buscaPorAutor(biblio,nombreAutor);
				for (int i = 0; i<res.numLibrosIntroducidos; i++){
					mostrarLibro(res.libs[i]);
				}
				break;
			case 5:
				salir = 1;
				break;
			default:
				printf("Entrada incorrecta. Prueba de nuevo");
				break;
		}
	}
	return 0;
}

struct autor_t nuevoAutor(){
	struct autor_t a1;
	
	printf("Introduce el nombre del autor del libro: ");
	scanf("%s", a1.nombre); 
	while (getchar() != '\n');
	
	printf("Introduce el apellido del autor del libro: ");
	scanf("%s", a1.apellido); 
	while (getchar() != '\n');
	
	printf("Introduce la nacionalidad del autor del libro: ");
	scanf("%s", a1.nacionalidad); 
	while (getchar() != '\n');
	
	return a1;
}

struct libro_t nuevoLibro(){
	struct libro_t l1;
	
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
	
	l1.autor = nuevoAutor();
	
	return l1;
}

void mostrarAutor(struct autor_t autor){
	printf("Nombre: %s\n", autor.nombre);
	printf("Apellido: %s\n", autor.apellido);
	printf("Nacionalidad: %s\n", autor.nacionalidad);
}

void mostrarLibro(struct libro_t libro){
	printf("Titulo: %s\n", libro.titulo);
	printf("ISBN: %s\n", libro.ISBN);
	printf("Numero de Paginas: %d\n", libro.numPaginas);
	printf("Editorial: %s\n", libro.editorial);
	mostrarAutor(libro.autor);
}

struct listaLibros_t buscaPorAutor(struct listaLibros_t libros, char a[]){
	struct listaLibros_t result;
	
	for (int i = 0; i<libros.numLibrosIntroducidos;i++){
		if (comparaCadenas(libros.libs[i].autor.nombre,a)==1){
			result.libs[result.numLibrosIntroducidos]=libros.libs[i];
			result.numLibrosIntroducidos++;
		}
	}
}	

int comparaCadenas(char *c1, char *c2){
	int esIgual=1;
	while (esIgual && *c1 == '\0' && *c2 == '\0'){
		if (*c1 != *c2){
			esIgual = 0;
		}
		else{
			c1++;
			c2++;
		}
	}
	return esIgual;
}