#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void dimensionesMatriz(int *n, int *m);
void rellenarMatriz(int n,int m,float mat[n][m]);
void calcularEstadisticas(int n, int m, float mat[n][m]);

void main(){
	srand(time(NULL));
	int N,M;
	dimensionesMatriz(&N,&M);
	float matriz[N][M];
	rellenarMatriz(N,M,matriz);
	for (int i = 0; i < N;i++){
		for (int j = 0; j < M; j++){
			printf("%.5f ", matriz[i][j]);
		}
		printf("\n");
	}
	calcularEstadisticas(N,M,matriz);
}

void dimensionesMatriz(int *n, int *m){
	int err = 0;
	while (err != 1){
		printf("Introduce el numero de filas: ");
		err = scanf("%d", n);
		while (getchar() != '\n');
	}
	err = 0;
	while (err != 1){
		printf("Introduce el numero de Columnas: ");
		err = scanf("%d", m);
		while (getchar() != '\n');
	}
}

void rellenarMatriz(int n,int m,float mat[n][m]){
	float randnum; 
	for (int i = 0; i < n;i++){
		for (int j = 0; j < m; j++){
			randnum = (float)rand()/(float)RAND_MAX;
			mat[i][j] = randnum;
		}
	}
}

void calcularEstadisticas(int n, int m, float mat[n][m]){
	float min[m];
	float max[m];
	float suma[m];
	float promedio[m];
	float sigma[m];
	float suma_cuadrada;
	
	for (int j = 0; j < m; j++){
		min[j] = 1;
		max[j] = 0;
		suma[j] = 0;
		suma_cuadrada = 0;
		for (int i = 0; i < n; i++){
			suma[j] =+ mat[i][j];
			if (mat[i][j] > max[j]){
				max[j] = mat[i][j];
			}
			if (mat[i][j] < min[j]){
				min[j] = mat[i][j];
			}
		}
		promedio[j] = suma[j]/m;
		for (int i = 0; i < n; i++){
			suma_cuadrada =+ pow(mat[i][j]-promedio[j],2);
		}
		sigma[j] = sqrt(suma_cuadrada/m);
	}
	for (int i = 0; i < m; i++){
		printf("Columna %d - ", i);
		printf("min: %f ", min[i]);
		printf("max: %f ", max[i]);
		printf("suma: %f ", suma[i]);
		printf("promedio: ", promedio[i]);
		printf("desviacion tipica: %f\n", sigma[i]);
	}
}