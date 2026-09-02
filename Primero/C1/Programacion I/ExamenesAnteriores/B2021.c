#include <stdio.h>
#include <math.h>

#define INTERMEDIOS 10

void calcularIntemedios(float x1, float x2, float y1, float y2, float *interX, float *interY);
void mostrarDatos(float *interX, float *interY);
float distanciaXY(float x1, float x2, float y1, float y2);

void main(){
	int err=0;
	float x1,y1,x2,y2,dist;
	float intermedios_x[INTERMEDIOS];
	float intermedios_y[INTERMEDIOS];
	while (err != 2){
		printf("Introduce las coordenadas del punto 1 en formato x,y: ");
		err = scanf("%f,%f", &x1,&y1);
		while (getchar() != '\n');
		if (err != 2){
			printf("Entrada no se ha leido correctamente, verifica los datos. \n");
		}
	}
	err = 0;
	while (err != 2){
		printf("Introduce las coordenadas del punto 2 en formato x,y: ");
		err = scanf("%f,%f", &x2,&y2);
		while (getchar() != '\n');
		if (err != 2){
			printf("Entrada no se ha leido correctamente, verifica los datos. \n");
		}
	}
	calcularIntemedios(x1,x2,y1,y2,intermedios_x,intermedios_y);
	dist = distanciaXY(x1,x2,y1,y2);
	mostrarDatos(intermedios_x, intermedios_y);
	printf("Distancia: %f", dist);
}

void calcularIntemedios(float x1, float x2, float y1, float y2, float *interX, float *interY){
	float intervaloX, intervaloY, resX, resY;
	intervaloX = (x2-x1)/9;
	intervaloY = (y2-y1)/9;
	resX = x1;
	resY = y1;
	*interX = resX;
	*interY = resY;
	interX++;
	interY++;
	for (int i = 1; i < INTERMEDIOS; i++){
		resX += intervaloX;
		resY += intervaloY;
		*interX = resX;
		*interY = resY;
		interX++;
		interY++;	
	}

}

void mostrarDatos(float *interX, float *interY){
	for(int i = 0; i < INTERMEDIOS; i++){
		printf("Punto %d < %f , %f>\n",i,*interX, *interY);
		interX++;
		interY++;
	}
}

float distanciaXY(float x1, float x2, float y1, float y2){
	return sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)));
}