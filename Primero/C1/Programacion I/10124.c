#include <stdio.h>

#define FILS 4
#define COLS 3


void main(){
int mat[FILS][COLS];
	int i,j,k;
	for (i = 0; i < FILS; i++){
		k = 1;
		for (j = 0; j < COLS; j++){
			mat[i][j] = k;
			k++;
		}
	}
	for (i = 0; i < FILS; i++){
		for (j = 0; j < COLS; j++){
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
}

