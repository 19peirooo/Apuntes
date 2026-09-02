#include <stdio.h>
#include <stdlib.h>

#define TAM 100

//Mostrar por pantalla una estructura de tipo persona_t
void imprimePersona(struct persona_t persona);

struct persona_t{ //Palabra clave para crear estructuras, se definen fuera del main
		char direccion[TAM]; // Referencias, no son variables
		char nombre[TAM];
		int numCliente;
		int edad;
}; //Acaban en punto y coma

int main(int argc, char **argv){
	struct persona_t p1 ={ // Estructura de tipo persona_t. Separados por comas. p1 es el nombre de la variable.
		.direccion="c/Ficus",
		.nombre="Victor",
		.numCliente=1456,
		.edad=18
	};
	imprimePersona(p1);
	return 0;
}

void imprimePersona(struct persona_t persona){
	printf("Direccion: %s\n", persona.direccion);
	printf("Nombre: %s\n", persona.nombre);
	printf("Edad: %d\n", persona.edad);
	printf("Numero Cliente: %d\n", persona.numCliente);
}
