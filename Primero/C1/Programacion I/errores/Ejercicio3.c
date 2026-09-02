/*
  programa que calcula el area de un circulo y el volumen de un cilindro
  */

#include <stdio.h>

void main() {

    // Variables para el radio y altura​

    float radio=0.0, areaCirculo=0.0;
    double altura=0.0, volumenCilindro=0.0;
    
    // Constante para el valor de PI​

    const double PI = 3.14159265359;
    
    // Solicitar al usuario que ingrese el radio del círculo​

    printf("Ingrese el radio del círculo: ");
    scanf("%f", &radio);
    
     // Calcular el área del círculo (usando float)​

    areaCirculo = PI * radio * radio;
    // Solicitar al usuario que ingrese la altura del cilindro​

    printf("Ingrese la altura del cilindro: ");
    scanf("%lf", &altura);
    
    // Calcular el volumen del cilindro (usando double)​

    volumenCilindro = PI * radio * radio * altura;
    
    // Imprimir los resultados​

    printf("El área del círculo es: %.2f\n", areaCirculo);//Comilla incluyen las variables

    printf("El volumen del cilindro es: %.2lf\n", volumenCilindro);
}