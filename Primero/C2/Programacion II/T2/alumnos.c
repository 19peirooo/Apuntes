#include <stdio.h>
#include <stdlib.h>

#define TAM 100
#define TAM_CLASE 25



struct alumnos_t {
	int edad;
	float altura;
	char nombre[TAM];
	char apellido[TAM];
};

struct alumnos_t pedirAlumnos();

int main(int argc, char **argv){
	struct alumnos_t alumnos[TAM_CLASE];
	for (int i = 0; i<TAM_CLASE; i++){
		alumnos[i]=pedirAlumnos();
	}
	printf("Nombre: %s\n", alumnos[0].nombre);
	printf("Direccion: %s\n", alumnos[0].apellido);
	printf("Edad: %d\n", alumnos[0].edad);
	printf("Altura: %f\n", alumnos[0].altura);
	return 0;
}

struct alumnos_t pedirAlumnos(){
	struct alumnos_t a1;
	printf("Introduce el nombre: ");
	scanf("%s", a1.nombre);
	while (getchar() != '\n');
	printf("Introduce el apellido: ");
	scanf("%s", a1.apellido);
	while (getchar() != '\n');
	printf("Introduce el edad: ");
	scanf("%d", &a1.edad);
	while (getchar() != '\n');
	printf("Introduce el altura: ");
	scanf("%f", &a1.altura);
	while (getchar() != '\n');
	return a1;
};