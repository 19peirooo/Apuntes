#include <stdio.h>
#include <stdlib.h>

#define LEEDATO(formato,dato) scanf(formato,dato); while(getchar()!='\n');

typedef enum gruposUtad_e{
	INSOA=0,INSOB=1,INSOC=2,MAIS=3,FIIS=4
}gruposUtad_e;

char *nombreGrupos[]={"INSOA","INSOB","INSOC","MAIS","FIIS"};

typedef struct listaEnteros_t{
	int *nums;
	int numMax;
	int numUsados;
}listaEnteros_t;

typedef struct listaEdades_t{
	gruposUtad_e grupo;
	listaEnteros_t *edads;
}listaEdades_t;

typedef struct listaGrupos_t{
	listaEdades_t **edadesPorGrupo;
	int tamMax;
	int numUsados;
}listaGrupos_t;

listaEdades_t* pedirNuevoGrupo();
void introduceEnListaDeNumeros(listaEnteros_t *lista, int pos, int num);
int calcularEdadMinima(listaEdades_t* grupo);
int calcularEdadMaxima(listaEdades_t* grupo);
int calcularEdadMedia(listaEdades_t* grupo);
void imprimirEdades(listaEdades_t* grupo);

int main(int argc, char **argv){
	int edad=1;
	int edadMinima=0;
	int edadMaxima=0;
	int edadMedia=0;
	int salir=0;
	
	listaGrupos_t grupos = {.edadesPorGrupo=NULL,.tamMax=0,.numUsados=0};
	grupos.edadesPorGrupo=(listaEdades_t**)malloc(sizeof(listaEdades_t*));
	grupos.tamMax = 1;
	
	do{
		printf("1 - Pedir Grupo\n");
		printf("2 - Salir\n");
		if (salir == 1){
			if (grupos.numUsados== grupos.tamMax){
				grupos.tamMax++;
				grupos.edadesPorGrupo=(listaEdades_t**)realloc(grupos.edadesPorGrupo,sizeof(listaEdades_t*)* grupos.tamMax);
			}
			grupos.edadesPorGrupo[grupos.numUsados]=pedirNuevoGrupo();
			grupos.numUsados++;
		}
	}while(salir != 2);
	for (int i = 0; i < grupos.numUsados;i++){
		printf("Datos del Grupo %s\n", grupos.edadesPorGrupo[i]->grupo);
		printf("Maximo: %d\n", calcularEdadMaxima(grupos.edadesPorGrupo[i]));
		printf("Minimo: %d\n", calcularEdadMinima(grupos.edadesPorGrupo[i]));
		printf("Media: %d\n", calcularEdadMedia(grupos.edadesPorGrupo[i]));
	}
	
	for (int i = 0; i < grupos.numUsados; i++){
		free(grupos.edadesPorGrupo[i]->edads->nums);
		free(grupos.edadesPorGrupo[i]->edads);
		free(grupos.edadesPorGrupo[i]);
	}
	free(grupos.edadesPorGrupo);
	
	return 0;
}

void introduceEnListaDeNumeros(listaEnteros_t *lista, int pos, int num){
	if (lista->numMax <= pos){
		lista->nums=realloc(lista->nums, sizeof(int)*(pos+1));
		lista->numMax=pos+1;
	}
	lista->nums[pos]=num;
	if (lista->numUsados<=pos){
		lista->numUsados=pos+1;
	}
}

void pedirListaEdadesDeGrupo(listaEdades_t* edadesGrupo){
	int edad=0;
	int pos=0;
	
	edadesGrupo->edads=(listaEdades_t*)malloc(sizeof(listaEdades_t));
	edadesGrupo->edads->nums = NULL;
	edadesGrupo->edads->numMax = 0;
	edadesGrupo->edads->numUsados = 0;
	printf("Introduce edades del grupo %s hasta introducir -1", nombreGrupos[edadesGrupo->grupo]);
	do{
		LEEDATO("%d", &edad);
		if (edad <= 0){
			introduceEnListaDeNumeros(edadesGrupo->edads,pos,edad);
			pos++;
		} else {
			printf("ERROR: Edad no valida");
		}
	}while (edad != -1);
}

listaEdades_t* pedirNuevoGrupo(){
	listaEdades_t* nuevaLista=(listaEdades_t*)malloc(sizeof(listaEdades_t));
	printf("Introduzca nombre del grupo: \n");
	printf("Grupos posibles:\n");
	for (gruposUtad_e grupo=INSOA; grupo<=FIIS; grupo++){
		printf("%d %s\n",grupo,nombreGrupos[grupo]);
	}
	LEEDATO("%d", &nuevaLista->grupo);
	pedirListaEdadesDeGrupo(nuevaLista);
}

int calcularEdadMinima(listaEdades_t* grupo){
	int edad = 0xFFFFFF;
	for (int i = 0; i < grupo->edads->numUsados; i++){
		if (grupo->edads->nums[i] < edad){
			edad = grupo->edads->nums[i];
		}
	}
	return edad;
}

int calcularEdadMaxima(listaEdades_t* grupo){
	int edad = 0;
	for (int i = 0; i < grupo->edads->numUsados; i++){
		if (grupo->edads->nums[i] > edad){
			edad = grupo->edads->nums[i];
		}
	}
	return edad;
}

int calcularEdadMedia(listaEdades_t* grupo){
	int suma = 0;
	int edad;
	for (int i = 0; i < grupo->edads->numUsados; i++){
		suma+=grupo->edads->nums[i];
	}
	edad = suma/grupo->edads->numUsados;
	return edad;
}

void imprimirEdades(listaEdades_t* grupo){
	int i = 0;
	for (int i = 0; i < grupo->edads->numUsados; i++){
		printf("Alumno: %d, Edad: %d\n", i+1,grupo->edads->nums[i]);
	}
}