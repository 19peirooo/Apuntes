#include <stdio.h>
#include <stdlib.h>

#define MAX_ARBOLES 50

typedef long long int INT64 ; //Te permite sustituir palabras
typedef int INT32;
typedef short INT16;
typedef char BYTE;

typedef enum booleano_e{V=1,F=0}booleano_e;

typedef enum tipoArbol_e{
	Pino=1,Haya=2,Roble=3,Eucalipto=4
}tipoArbol_e;

char *nombresArboles[]={"Pino","Haya","Roble","Eucalipto"};

typedef struct arbol_t{
	INT64 numHojas;
	INT32 numRamas;
	INT16 numRaices;
	tipoArbol_e nombreArbol;
}arbol_t;

typedef struct listaArboles_t{
	arbol_t arboles[MAX_ARBOLES];
	int tam;
	int numArbolesIntroducidos;
}listaArboles_t;

arbol_t crearArbol();
void mostrarArbol(arbol_t arbol);


int main(int argc, char **argv){
	listaArboles_t bosque={
		.tam = MAX_ARBOLES,
		.numArbolesIntroducidos=0
	};
	booleano_e menuAbierto = V;
	int opcion=0;
	int arbolIntroducido=-1;
	//Creo menu
	while (menuAbierto==V){
		printf("\n"
		"1.Crear arbol \n"
		"2.Mostrar Arbol \n"
		"3.Salir \n");
		//Leo Opcion
		printf("Opcion: ");
		scanf("%d", &opcion);
		
		switch (opcion){
			case 1:{
				if (bosque.numArbolesIntroducidos < bosque.tam){
					bosque.arboles[bosque.numArbolesIntroducidos] = crearArbol();
					bosque.numArbolesIntroducidos++;
				} else {
					printf("ERROR: Numero maximos de arboles introducido\n");
				}
			}break;
			case 2:{
				arbolIntroducido=-1;
				while (arbolIntroducido < 0 || arbolIntroducido > bosque.numArbolesIntroducidos){
					printf("Que arbol quieres ver(0-%d):", bosque.numArbolesIntroducidos - 1);
					scanf("%d", &arbolIntroducido);
				}
				mostrarArbol(bosque.arboles[arbolIntroducido]);
			}break;
			case 3:{
				menuAbierto=F;
			}break;
			default:{
				printf("ERROR: Entrada Incorrecta\n");
			}break;
		}
	}
	
	return 0;
}

arbol_t crearArbol(){
	arbol_t a1;
	int arbol=0;
	printf("Introduce el numero de hojas: ");
	scanf("%lld", &a1.numHojas);
	while(getchar()!='\n');
	printf("Introduce el numero de ramas: ");
	scanf("%d", &a1.numRamas);
	while(getchar()!='\n');
	printf("Introduce el numero de raices: ");
	scanf("%hd", &a1.numRaices);
	while(getchar()!='\n');
	while (arbol > 4 || arbol < 1){
		printf("Introduce el numero correspondiente al tipo del arbol:\n"
		"1.Pino\n"
		"2.Haya\n"
		"3.Roble\n"
		"4.Eucalipto\n");
		printf("Opcion: ");
		scanf("%d", &arbol);
		while(getchar()!='\n');
		if (arbol > 4 || arbol < 1){
			printf("ERROR: Arbol No Existe\n");
		}
	}
	a1.nombreArbol = arbol;
	return a1;
}

void mostrarArbol(arbol_t arbol){
	printf("Tipo: %s\n", nombresArboles[arbol.nombreArbol-1]);
	printf("Numero de Hojas: %lld\n", arbol.numHojas);
	printf("Numero de Ramas: %d\n", arbol.numRamas);
	printf("Numero de Raices: %hd\n", arbol.numRaices);
}