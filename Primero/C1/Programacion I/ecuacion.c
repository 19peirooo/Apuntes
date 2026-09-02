#include <stdio.h>
#include <math.h>

int main(){
	double xpos,xneg;
	float a,b,c;
	
	printf("Introduce el coeficiente de x^2: ");
	scanf("%f",&a);
	printf("Introduce el coeficiente de x: ");
	scanf("%f",&b);
	printf("Introduce el termino independiente: ");
	scanf("%f",&c);
	
	if(((b*b)-(4*a*c)) < 0){
		printf("No hay raices reales para la ecuacion: %fx^2 + %fx + %f", a, b, c);
	}
	else if(((b*b)-(4*a*c)) == 0){
		printf("Solo hay 1 raiz real para la ecuacion: %fx^2 + %fx + %f \n", a, b, c);
		xpos = (-b/(2*a));
		printf("La raiz es x=%.2lf", xpos);
	}
	else{
		xpos= (-b + sqrt((b*b)-(4*a*c)))/(2*a);
		xneg= (-b - sqrt((b*b)-(4*a*c)))/(2*a);
		printf("Hay 2 raices reales para la ecuacion: %fx^2 + %fx + %f \n", a, b, c);
		printf("La raiz positiva es x=%.2lf \n", xpos);
		printf("La raiz negativa es x=%.2lf", xneg);
	}
	
	return 0;
}