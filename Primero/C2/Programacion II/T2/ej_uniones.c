#include <stdio.h>
#include <stdlib.h>

typedef union datos_u {
	int edad;
	float peso;
	char nombre[10];
}datos_u;

typedef struct datos_t {
	int edad;
	float peso;
	char nombre[10];
}datos_t;

int main(int argc, char **argv){
	
	datos_u dat_union;
	datos_t dat_struct;
	
	printf("Para el struct: \n");
	printf("Introduce tu edad:");
	scanf("%d", &dat_struct.edad);
	while(getchar() != '\n');
	printf("Introduce tu peso:");
	scanf("%f", &dat_struct.peso);
	while(getchar() != '\n');
	printf("Introduce tu nombre:");
	scanf("%s", dat_struct.nombre);
	while(getchar() != '\n');
	
	printf("Edad: %d\n", dat_struct.edad);
	printf("Peso: %.2f\n", dat_struct.peso);
	printf("Nombre: %s\n", dat_struct.nombre);
	
	printf("Para la union: \n");
	printf("Introduce tu edad:");
	scanf("%d", &dat_union.edad);
	while(getchar() != '\n');
	printf("Introduce tu peso:");
	scanf("%f", &dat_union.peso);
	while(getchar() != '\n');
	printf("Introduce tu nombre:");
	scanf("%s", dat_union.nombre);
	while(getchar() != '\n');
	
	printf("Edad: %d\n", dat_union.edad);
	printf("Peso: %.2f\n", dat_union.peso);
	printf("Nombre: %s\n", dat_union.nombre);
}