#include <stdio.h>
#include <stdlib.h>

#define PI 3.141592

typedef enum tipoFigura_e{
	circulo=0,cuadrado=1
}tipoFigura_e;

char* tiposFiguras[2]={"circulo","cuadrado"};

typedef struct figura_t{
	tipoFigura_e tipo;
	union{
		float radio;
		float lado;
	}
	float area;
}figura_t; 

int comparaCadenas(char *c1, char *c2)
float calcularArea(figura_t fig);

int main(int argc, char **argv){
	figura_t f;
	int error = 0;
	char *errNum;
	float dato = 0;
	if (argc != 3){
		printf("ERROR: Numero de parametros incorrectos\n");
	} else {
		if (comparaCadenas(argv[1],"circulo")){
			f.tipo = circulo;
		} 
		else if (comparaCadenas(argv[1],"cuadrado"){
			f.tipo = cuadrado;
		}
		else {
			printf("ERROR: Figura no valida\n");
			error = 1;
		}
		
		if (!error){
			dato = strtof(argv[2], &errNum);
			if (*errNum != '\0'){
				printf("ERROR: Dato no numerico\n");
			}
			else {
				if (f.tipo == circulo) f.radio= dato;
				else if (f.tipo == cuadrado) f.lado = dato;
				calcularArea(f);
				printf("El area de la figura es: %f\n", f.area);
			}
		}
	}
}



int comparaCadenas(char *c1, char *c2){
	while(*c1!='\0' && *c2 != '\0' && (*(c1++)==*(c2++)));
	return *(--c1)==*(--c2);
}

float calcularArea(figura_t fig){
	float area;
	switch (fig.tipo){
		case circulo:{
			area = PI * fig.radio * fig.radio;
		}break;
		case cuadrado:{
			area = fig.lado * fig.lado;
		}break;
	}
	return area;
}