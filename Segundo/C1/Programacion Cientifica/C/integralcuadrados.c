#include <stdio.h>
#include <math.h>

double funcion(double x) {
    return cos(x);
}

double errorIntegral(double calculada, double precisa){
    return fabs((calculada - precisa)/precisa)*100;
}

double calcularAproximacion(double (*f)(double),int numRectangulos, double limInf, double limSup){
    double area = 0;
    double base = (limSup - limInf)/numRectangulos;
    double inicio = limInf;    
    for (int i = 1; i <= numRectangulos; i++){
        area += (f(inicio) * base);
        inicio += base;
    }
    return area;
}

int main(int argc, char** argv){
    double areaCalculada = 0;
    double limSup = -1;
    double limInf = -1;
    double areaVerdadera = 0;
    double errorCalc = 0;
    int numRectangulos[] = {10,50,100,1000,5000,10000,50000,100000,500000,1000000};

    while (limInf < 0){
        printf("Introduce el limite inferior: ");
        scanf("%lf", &limInf);
        while(getchar() != '\n');
    }

    while (limSup < 0 || limSup < limInf){
        printf("Introduce el limite superior: ");
        scanf("%lf", &limSup);
        while(getchar() != '\n');
    }

    printf("Area;Aproximacion;NR;Error\n");
    for (int j = 0; j < 10; j++){
        areaVerdadera = sin(limSup)- sin(limInf);
        areaCalculada = calcularAproximacion(funcion,numRectangulos[j],limInf,limSup);
        errorCalc = errorIntegral(areaCalculada,areaVerdadera);
        printf("%.5lf;%.5lf;%d;%.5lf\n",areaCalculada,areaVerdadera,numRectangulos[j],errorCalc);
    }
    return 0;
}