#include <stdio.h>
#include <stdlib.h>

typedef enum gruposUtad_e{
	INSOA,INSOB,INSOC,MAIS,FIIS
}gruposUtad_e;

char *nombreGrupos[]={"INSOA","INSOB","INSOC","MAIS","FIIS"};

typedef struct listaEdades_t{
	int *nums;
	int numEdadesMax;
	int numEdadesIntroducidos;
}listaEdades_t;

typedef struct grupos_t{
	gruposUtad_e grupo;
	listaEdades_t *edads;
}grupos_t;

int calcularEdadMinima(int *edades,int n);
int calcularEdadMaxima(int *edades,int n);
int calcularEdadMedia(int *edades,int n);
void imprimirEdades(int *edades,int n);


int main(int argc, int **argv){
	int edad=1;
	int edadMinima=0;
	int edadMaxima=0;
	int edadMedia=0;
	
	listaEdades_t edades={
		.numEdadesMax = 10,
		.numEdadesIntroducidos=0
	};
	edades.edads = (int*)realloc(NULL,sizeof(int)* edades.numEdadesMax);
	
	grupos_t grupo={
		.*edads
	}
	
	while (edad > 0){
		printf("Introduce la edad del alumno %d: ", edades.numEdadesIntroducidos+1);
		scanf("%d", &edad);
		if (edades.numEdadesIntroducidos == edades.numEdadesMax){
			edades.numEdadesMax+=10;
			edades.edads = (int*)realloc(edades.edads,sizeof(int)*edades.numEdadesMax);
			if (edades.edads == NULL){
				printf("ERROR: No hay memoria suficiente");
				exit(0);
			}
		}
		edades.edads[edades.numEdadesIntroducidos] = edad;
		edades.numEdadesIntroducidos++;
	}
	edadMinima=calcularEdadMinima(edades.edads,edades.numEdadesIntroducidos);
	edadMaxima=calcularEdadMaxima(edades.edads,edades.numEdadesIntroducidos);
	edadMedia=calcularEdadMedia(edades.edads,edades.numEdadesIntroducidos);
	printf("Edad Minima: %d\n", edadMinima);
	printf("Edad Maxima: %d\n", edadMaxima);
	printf("Edad Media: %d\n", edadMedia);
	imprimirEdades(edades.edads,edades.numEdadesIntroducidos);
	free(edades.edads);
	return 0;
}

int calcularEdadMinima(int *edades,int n){
	int edad = 100;
	int i = 0;
	while (i<(n-1)){
		if (*edades < edad){
			edad = *edades;
		}
		*edades++;
		i++;
	}
	return edad;
}

int calcularEdadMaxima(int *edades,int n){
	int edad = 0;
	int i = 0;
	while (i<(n-1)){
		if (*edades > edad){
			edad = *edades;
		}
		edades++;
		i++;
	}
	return edad;
}

int calcularEdadMedia(int *edades,int n){
	int suma = 0;
	int edad;
	int i = 0;
	while (i<(n-1)){
		suma+=*edades;
		edades++;
		i++;
	}
	edad = suma/(n-1);
	return edad;
}

void imprimirEdades(int *edades,int n){
	int i = 0;
	while (i < (n-1)){
		printf("Alumno: %d, Edad: %d\n", i+1,*edades);
		i++;
		edades++;
	}
}