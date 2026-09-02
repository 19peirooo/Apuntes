#include <stdio.h>
#include <math.h>

#define NUMPUNTOS 5

void aPolares(float x[NUMPUNTOS], float y[NUMPUNTOS], float *radio, float *angulo);

void main(){
	float coord_x[NUMPUNTOS] = {1,1,-1,1.2,8};
	float coord_y[NUMPUNTOS] = {1,9,0,-1,2.7};
	float radio[NUMPUNTOS],*pradio;
	float angulo[NUMPUNTOS],*pangulo;
	
	pradio = radio;
	pangulo = angulo;
	aPolares(coord_x, coord_y, pradio, pangulo);
	
	for(int i = 0; i < NUMPUNTOS; i++){
		printf("El punto cartesiano (%.1f,%.1f) equivale en polares a radio = %.3f y angulo = %.3f\n", coord_x[i],coord_y[i],radio[i],angulo[i]);
	}
}

void aPolares(float x[NUMPUNTOS], float y[NUMPUNTOS], float *radio, float *angulo){
	for (int i = 0; i < NUMPUNTOS; i++){
		*radio = sqrt((x[i]*x[i]) + (y[i]*y[i]));
		*angulo = atan(y[i]/x[i]);
		radio++;
		angulo++;
	}
}