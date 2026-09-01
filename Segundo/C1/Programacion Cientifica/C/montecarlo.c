#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NUM_PUNTOS 10000
#define PI 3.141592

void muestraAleatoria(double* muestra){
    for(int i = 0; i < NUM_PUNTOS; i++){
        muestra[i] = (double)rand() / RAND_MAX;
        muestra[i] = 2*muestra[i] - 1;
    }
}

int main(int argc, char **argv){
    double x[NUM_PUNTOS], y[NUM_PUNTOS];
    int nPuntos[] = {50,100,1000,2500,5000,10000}; 
    int puntosDentro = 0;
    double radio = 1;
    double area = 0, areaAprox = 0;
    double error = 0;
    srand(time(NULL));
    for (int np = 0; np < 6; np++){
        puntosDentro = 0;
        muestraAleatoria(x);
        muestraAleatoria(y);

        for (int i = 0; i < nPuntos[np]; i++){
            if (pow(x[i],2) + pow(y[i],2) <= pow(radio,2)){
                puntosDentro++;
            }
        }

        area = PI *pow(radio,2);
        areaAprox = (pow((2*radio),2)*puntosDentro)/nPuntos[np];
        error = fabs(area-areaAprox)*100;

        printf("%d,%.5lf,%.5lf,%.5lf\n",nPuntos[np], area, areaAprox,error);
    }
    
    return 0;
}