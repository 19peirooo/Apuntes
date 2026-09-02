#include <stdio.h>

#define FILS 4
#define COLS 8

void inicializaCine(char sala);
void mostrarCine(char sala);
void leerAsiento(int *f, int *c);

void main(){
	char sala[FILS][COLS];
	int fila, columna;
	inicializaCine(sala);
	mostrarCine(sala);
	leerAsiento();
}

void inicializaCine(char sala[FILS][COLS]){
	for (int i = 0; i < FILS; i++){
		for (int j = 0; i < COLS; j++){
			sala[i][j] = 'O';
		}
	}
}

void mostrarCine(char sala[FILS][COLS]){
	for (int i = 0; i < FILS; i++){
		for (int j = 0; i < COLS; j++){
			printf("%c ",sala[i][j]);
		}
		printf("\n");
	}
}

void leerAsiento(int *f,int *c){
	int filaValida = 0;
	int colValida = 0;
	while (!filaValida){
		printf("Introduce una fila: \n");
		scanf("%d", f);
		while (getchar() != '\n'); //Limpiar Buffer
		if ((*f)<FILS && (*f)>=0){
			filaValida = 1;
		}
	}
	while (!colValida){
		printf("Introduce una columna: \n");
		scanf("%d", c);
		while(getchar()!='\n');
		if (*c<COLS && *c>0){
			colValida = 1;
		}
	}
}