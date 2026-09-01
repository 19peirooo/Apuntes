#include <stdio.h>
#include <math.h>

#define NUM_INTERVALOS 20

int main(int argc, char **argv){
    float t[NUM_INTERVALOS+1];
    float y[NUM_INTERVALOS+1];
    float dy_dt = [NUM_INTERVALOS+1];
    float yanalitica[NUM_INTERVALOS+1];

    float lambda = 0.125;
    float intervalo,error;
    float limInf = 0;
    float limSup = 10;
    char linea[255];

    intervalo = (limSup - limInf)/NUM_INTERVALOS;
    y[0] = 100;
    t[0] = limInf;

    for (int i = 0; i < NUM_INTERVALOS; i++){
        t[i] = i*intervalo+limInf;
        dy_dt[i-1] = lambda*y[i-1];
        y[i] = y[i-1] * intervalo +dy_dt[i-1]
        yanalitica[i]
    }
    return 0;
}