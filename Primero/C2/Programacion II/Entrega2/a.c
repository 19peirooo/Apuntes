#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum bool_e{V=1,F=0}bool_e;

typedef struct matrizDinamica_t{
	char **matriz;
	int dim;
}matrizDinamica_t;

typedef struct coordenada_t{
	int fila,columna;
}coordenada_t;

typedef struct intento_t{
	coordenada_t coords;
	bool_e acierto;
}intento_t;

typedef struct listaIntentos_t{
	intento_t *intentos;
	int numIntentos;
}listaIntentos_t;

char **crearMatriz(int dim, bool_e *error); //Crear la matriz dinamica
void rellenarMatriz(char **m, int dim,char valor); //Rellena la matriz de incognitas
intento_t pedirIntento();
void testeaIntento(char** matriz, intento_t *nuevoIntento, coordenada_t coordsMina);
void insertaIntentoEnLista(listaIntentos_t *in, intento_t nuevoIntento, bool_e *error);
void imprimirIntentos(listaIntentos_t lista,coordenada_t coordsMina);
void imprimirMatriz(char **m, int dim); //Imprime una matriz

int main(int argc, char **argv){
	matrizDinamica_t mat;
	coordenada_t coordsMina;
	listaIntentos_t in={.numIntentos = 0};
	intento_t intento={.acierto = F};
	bool_e error = F;
	bool_e menuAbierto = V;
	bool_e intentoValido = F;
	
	char *errNum = NULL;
	int dato = 0;
	int opcion=0;
	
	srand(time(NULL));
	
	//Comprobar si le paso un numero por parametro
	if (argc != 2){
		printf("ERROR: Numero de parametros incorrectos\n");
		error = V;
	}
	else {
		dato = (int)strtol(argv[1],&errNum,10);
		if (*errNum != '\0'){
			printf("ERROR: Parametro no es un numero\n");
			error = V;
		}
		else {
			mat.dim = dato;
			mat.matriz = crearMatriz(mat.dim, &error);
		}
	}
	if (error == F){
		rellenarMatriz(mat.matriz,mat.dim,'?');
		in.intentos = (intento_t *)malloc(sizeof(intento_t)*in.numIntentos);
		if(in.intentos == NULL){
			printf("ERROR: No hay memoria disponible\n");
			error = V;
		}
		coordsMina.fila = rand()%mat.dim;
		coordsMina.columna = rand()%mat.dim;
	}
	while (menuAbierto == V && error == F){
		printf("\t--------------------------------------\n"
		"\t 1. Buscar\n"
		"\t 2. Visualizar intentos\n"
		"\t 3. Ver Matriz\n"
		"\t 4. Salir\n"
		"\t--------------------------------------\n"
		"Opcion: "
		);
		scanf("%d", &opcion);
		while(getchar()!='\n');
		switch (opcion){
			case 1:{
				do{
					intento = pedirIntento();
					if (intento.coords.fila < 0 || intento.coords.fila >= mat.dim){
						printf("ERROR: Fila introducida no pertenece a la tabla\n");
						intentoValido = F;
					}
					else if(intento.coords.columna < 0 || intento.coords.columna >= mat.dim){
						printf("ERROR: Columna introducida no pertenece a la tabla\n");
						intentoValido = F;
					}
					else{
						intentoValido = V;
					}
				}while (intentoValido == F);
				testeaIntento(mat.matriz,&intento,coordsMina);
				in.numIntentos++;
				if (intento.acierto == V){
					menuAbierto = F;
				} 
				else {
					insertaIntentoEnLista(&in,intento,&menuAbierto);
				}
			}break;
			case 2:{
				imprimirIntentos(in,coordsMina);
			}break;
			case 3:{
				imprimirMatriz(mat.matriz,mat.dim);
			}break;
			case 4:{
				menuAbierto = F;
				printf("Finalizando Programa...");
			}break;
			default:{
				printf("ERROR: Entrada no valida\n");
			}break;
		}
	}
	for (int i = 0; i < mat.dim; i++){
		free(mat.matriz[i]);
	}
	free(mat.matriz);
	free(in.intentos);
	return 0;
}
char **crearMatriz(int dim,bool_e *error){
	char **matriz;
	matriz = (char**)malloc(sizeof(char*) * dim);
	if (matriz == NULL){
		printf("ERROR: No hay memoria disponible\n");
		*error = V;
	}
	for (int i = 0; i < dim && *error == F; i++) {
        matriz[i] = (char *)malloc(sizeof(char) * dim);
		if (matriz[i] == NULL){
			printf("ERROR: No hay memoria disponible\n");
			*error = V;
		}
    }
	return matriz;
}

void rellenarMatriz(char **m,int dim,char valor){
	for (int i = 0; i < dim; i++){
		for (int j = 0; j < dim; j++){
			m[i][j] = valor;
		}
	}
}

intento_t pedirIntento(){
	intento_t i;
	printf("Introduce fila: ");
	scanf("%d", &i.coords.fila);
	while (getchar() != '\n');
	printf("Introduce columna: ");
	scanf("%d", &i.coords.columna);
	while (getchar() != '\n');
	return i;
}

void testeaIntento(char** matriz, intento_t *nuevoIntento, coordenada_t coordsMina){
	if (nuevoIntento->coords.fila == coordsMina.fila && nuevoIntento->coords.columna == coordsMina.columna){
		printf("*****************************BOOOOOOOOOOOOOM**********************\n");
		nuevoIntento->acierto = V; 
	} else {
		matriz[nuevoIntento->coords.fila][nuevoIntento->coords.columna] = 'O';
	}
}

void insertaIntentoEnLista(listaIntentos_t *in, intento_t nuevoIntento, bool_e *error){
	in->intentos = (intento_t *)realloc(in->intentos,sizeof(intento_t)*(in->numIntentos));
	if (in->intentos == NULL){
		printf("ERROR: No hay memoria disponible");
		*error = V;
	}
	in->intentos[in->numIntentos-1] = nuevoIntento;
	
}

void imprimirMatriz(char **m,int dim){
	for (int i = 0; i < dim; i++){
		for (int j = 0; j < dim; j++){
			printf("%c ", m[i][j]);
		}
		printf("\n");
	} 
}

void imprimirIntentos(listaIntentos_t lista, coordenada_t coordsMina){
	for (int i = 0; i < lista.numIntentos; i++){
		printf("Intento %d:\n", i);
		printf("[%d][%d]",lista.intentos[i].coords.fila,lista.intentos[i].coords.columna);
		if (lista.intentos[i].coords.fila == coordsMina.fila){
			printf("...en esa fila\n");
		}
		else if (lista.intentos[i].coords.columna == coordsMina.columna){
			printf("...en esa columna\n");
		}
	}
	printf("\n");
}