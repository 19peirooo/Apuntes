#include <stdio.h>
#include <stdlib.h>

#define TAMMAX 75
#define TAM_BIB 100
#define NUM_AUTORES 200

typedef enum booleano_e{
	V=1,F=0
}booleano_e;

typedef enum tipoLista_e{ //Enumeraciones --> Como un define --> Permite crear nuevos tipos de datos
	tipoAutor,tipoLibro,tipoError //Valores de tipoLista
}tipoLista_e;

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
}libro_t;

typedef struct lista_t{ //Union entre 2 listas --> Tipo de Estructura
	tipoLista_e tipo; //Para ver si tengo un libro o un autor
	union{
		libro_t libs[TAM_BIB];
		autor_t auts[NUM_AUTORES];
	};
	int size; //Tamaño maximo
	union{
		int numDatosIntroducidos;
		int numLibrosIntroducidos;
		int numAutoresIntroducidos;
	};
}lista_t,listaLibros_t,listaAutores_t;

autor_t nuevoAutor();
booleano_e buscarAutor(char *nombre, char *apellido, lista_t *listaAutores, autor_t **autor);
libro_t nuevoLibro();
void mostrarAutor(autor_t autor);
void mostrarLibro(libro_t libro);
listaLibros_t buscaPorAutor(lista_t libros, char autor[TAMMAX]);
int comparaCadenas(char *c1, char *c2);

int main(int argc, char **argv){
	int salir = 0, opcion = -1, i = 0;
	char nombreAutor[TAMMAX]={'\0'};
	
	lista_t biblio={
		.tipo=tipoLibro,
		.size = TAM_BIB,
		.numDatosIntroducidos = 0
	};
	
	lista_t autores={
		.tipo=tipoAutor,
		.size = NUM_AUTORES,
		.numDatosIntroducidos = 0
	};
	
	while (!salir){
		opcion=-1;
		printf("\nBienvenido a la Bibioteca. Elige una opcion: \n");
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
					biblio.libs[biblio.numLibrosIntroducidos] = nuevoLibro(&autores);
					biblio.numLibrosIntroducidos++;
				}
				else{
					printf("Biblioteca Completa. No se pueden añadir mas libros");
				}
				break;
			case 2:
				if (autores.numLibrosIntroducidos < autores.size){
					autores.auts[biblio.numLibrosIntroducidos] = nuevoAutor();
					autores.numAutoresIntroducidos++;
				}
				else{
					printf("Error: Lista de Autores LLena");
				}
				break;
			case 3:
				for (int i = 0; i<biblio.numLibrosIntroducidos; i++){
					mostrarLibro(biblio.libs[i]);
				}
				break;
			case 4:
				listaLibros_t res={
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

autor_t nuevoAutor(){
	autor_t a1;
	
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

booleano_e buscarAutor(char *nombre, char *apellido, lista_t *listaAutores, autor_t **autor){
	booleano_e encontrado = F;
	for (int i = 0; i<(*listaAutores).numAutoresIntroducidos && (!encontrado); i++){
		if (comparaCadenas(nombre,(*listaAutores).auts[i].nombre) && comparaCadenas(apellido,(*listaAutores).auts[i].apellido)){
			encontrado = V;
			(*autor)=&(*listaAutores).auts[i];
		}
	}
	return encontrado;
}

libro_t nuevoLibro(lista_t *listaAutores){
	libro_t l1;
	booleano_e encontrado;
	char nombreAutor[TAMMAX]={'\0'};
	char apellidoAutor[TAMMAX]={'\0'};
	
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
	
	do{
		printf("Introduce el nombre del Autor: ");
		scanf("%s", nombreAutor);
		while (getchar() != '\n');
		printf("Introduce el apellido del Autor: ");
		scanf("%s", apellidoAutor);
		while (getchar() != '\n');
		
		encontrado = buscarAutor(nombreAutor, apellidoAutor, listaAutores, &l1.autor);
		if (!encontrado){
			printf("ERROR: Autor no existe");
		}
	}while(!encontrado);
	return l1;
}

void mostrarAutor(autor_t autor){
	printf("Nombre: %s\n", autor.nombre);
	printf("Apellido: %s\n", autor.apellido);
	printf("Nacionalidad: %s\n", autor.nacionalidad);
}

void mostrarLibro(libro_t libro){
	printf("Titulo: %s\n", libro.titulo);
	printf("ISBN: %s\n", libro.ISBN);
	printf("Numero de Paginas: %d\n", libro.numPaginas);
	printf("Editorial: %s\n", libro.editorial);
	mostrarAutor(*(libro.autor));
}

listaLibros_t buscaPorAutor(listaLibros_t libros, char a[]){
	listaLibros_t result;
	
	for (int i = 0; i<libros.numLibrosIntroducidos;i++){
		if (comparaCadenas(libros.libs[i].autor->nombre,a)==1){//Si puntero a autor/lpsea, -> en vez de .
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