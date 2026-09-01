#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "leeFichero.c"

//Constantes para el numero de euler y pi
#define E 2.71828
#define PI 3.14159

//Funcion que calcular el % de error del programa
double errorIntegral(double calculada, double precisa){
    return fabs((calculada - precisa)/precisa)*100; //error = area calculada - area real / area real
}

//Calcular el area por el metodo de Riemann
double calcularAreaAproximada(funcion_t f){
    double area = 0;
    double base = 0;

    //Hacemos un rectangulo por cada par de puntos
    for (int i = 0; i < f.numPuntosIntroducidos-1; i++){
        base = f.x[i+1] - f.x[i]; //Como no tenemos la ecuación de la función, la base de cada rectangulo es la diferencia de ese punto y el siguiente
        area += base * f.y[i]; //Area de un rectangulo = base * altura. El area debajo de la curva es la suma del area de cada rectangulo
    }
    return area;
}

int main(int argc, char** argv){
    //Creo ambas funciones. Estructura y funcion de archivo leeFichero.c
    funcion_t f_x = rellenaPuntos("INTEG_CURVA_A_puntos_curva_1.txt");
    funcion_t g_x = rellenaPuntos("INTEG_CURVA_A_puntos_curva_2.txt");
    double areaVerdadera = -1 + ((2*E)/PI); //Area teorica
    double areaf_x, areag_x, areaAprox;
    double error;

    //Calculo el area debajo de la funcion para ambas funciones
    areaf_x = calcularAreaAproximada(f_x);
    areag_x = calcularAreaAproximada(g_x);

    /*Veo que funcion esta por encima de la otra.
    Si f_x por encima de g_x, su area va a ser mayor ya que los rectangulos seran mas grandes*/
    if (areaf_x >= areag_x){
        areaAprox = areaf_x - areag_x;
    } else {
        areaAprox = areag_x - areaf_x;
    }

    //Imprimo los datos
    printf("Area f_x: %lf, Area g_x: %lf, Area Final: %lf\n", areaf_x, areag_x, areaAprox);
    printf("Area Verdadera: %lf\n", areaVerdadera);

    //Calculo y muestro el error
    error = errorIntegral(areaAprox,areaVerdadera);
    printf("Error: %lf%%", error);

    //Al ser arrays dinamicos, tengo que liberar su memoria
    free(f_x.x);
    free(f_x.y);
    free(g_x.x);
    free(g_x.y);
    return 0;
}