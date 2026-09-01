#include <stdio.h>
#include <stdlib.h>
#include "essentials.c"
#include "replacedot.c"

//d^2f(x)/dx^2 = -f(x) --> Se cumple solo para seno y coseno y para e^ix en variable compleja
//Intergrar entre t = 0 y t = 20. x(0) = 5 y v(0) = 0 m = 1 k = 1

# define NUM_INTERVALOS 50


int main(int argc, char** argv){

    char linea[255];
    double t[NUM_INTERVALOS+1];
    double x[NUM_INTERVALOS+1];
    double v[NUM_INTERVALOS+1];

    double t_0 = 0, t_20 = 20;
    double v_0 = 0, x_0 = 5, m = 1, k = 1;
    double dt = (t_20 - t_0)/NUM_INTERVALOS;
    t[0] = t_0;
    x[0] = x_0;
    v[0] = v_0;

    printf("t;x;v\n");
    for (int i = 1; i < NUM_INTERVALOS+1; i++){
        t[i] = t[i-1] + dt;
        /* Euler
        x[i] = x[i-1] + v[i-1]*dt;
        v[i] = v[i-1] - ((k*x[i-1])/m)*dt;*/

        v[i] = v[i-1] - ((k*x[i-1])/m)*dt;
        x[i] = x[i-1] + v[i]*dt;
        printf("%.2lf;%.2lf;%.2lf\n",t[i],x[i],v[i]);
    }

    return 0;
}