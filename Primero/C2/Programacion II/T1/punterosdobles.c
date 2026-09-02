#include <stdio.h>
#include <stdlib.h>

void ejemplo1(); //Arrays de Punteros y Punteros dobles
void ejemplo2(); //Punteros dobles

//argc y argv son parametros de entrada. 
//int main --> los primeros 100 numeros se reservan para errores
int main(int argc, char **argv[]){
	ejemplo2();
	int ent = 15;
	int *ptr = 0;
	int **dPtr = 0;
	return 0;
}

void ejemplo1(){
	int numeros[10]={0};
	int numeros1[10]={1};
	int numeros2[10]={2};
	int numeros3[10]={3};
	
	int *pnumeros = numeros; //Puntero a array
	int *pnumerosAux[4]={NULL}; //Array de Punteros --> numeros2[4][10] --> Los arrays no tiene que tener el mismo tamaño
	int **ppnumeros2=NULL; //Puntero doble --> Apunta a 0 por ahora
	
	pnumeros[0] = 5;
	
	ppnumeros2 = &pnumerosAux[0]; //Puntero doble --> Puntero a puntero
	ppnumeros2[0] = numeros;
	ppnumeros2[1] = numeros1;
	ppnumeros2[2] = numeros2;
	ppnumeros2[3] = numeros3;
	
	for (int pos = 0; pos < 10 ; pos++){
		printf("Posicion %d. Valor: %d\n", pos, *(pos+pnumeros));
		printf("Posicion %d. Valor: %d\n", pos, numeros[pos]);
	}
	
	for (int fila = 0; fila < 4; fila++){
		for (int cols = 0; cols < 10; cols++){
			ppnumeros2[fila][cols] = fila*10+cols; //Rellena los arrays
		}
	}
	
	for (int fila = 0; fila < 4; fila++){
		for (int cols = 0; cols < 10; cols++){
			printf("Posicion %d %d. Valor: %d\n", fila, cols, ppnumeros2[fila][cols]);
		}
	}
}

void ejemplo2(){
	int ent = 15;
	int *ptr = 0;
	int **dPtr = 0;
	
	dPtr = &ptr;
	ptr = &ent;
	
	printf("El valor es: %d\n", **dPtr); // * es para dereferenciar el puntero --> Saca el valor de ent
	printf("El valor es: %d\n", *dPtr); // Valor de memoria del ent
	printf("El valor es: %d\n", *ptr);
}