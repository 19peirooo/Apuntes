#include <stdio.h>
#include <stdlib.h>

#define PI 3.141592

typedef enum tipoUnidades_e{
	cm=0,in=1
}tipoUnidades_e;

char* tiposUnidades[2]={"cm","in"};

typedef struct conversion_t{
	tipoUnidades_e unidadIn;
	tipoUnidades_e unidadOut;
	double valor;
}figura_t; 

int comparaCadenas(char *c1, char *c2)
double convertirLongitud(conversion_t c);

int main(int argc, char **argv){
	conversion_t c;
	int error = 0;
	char *errNum='\0';
	double dato = 0;
	double valorNuevo=0;
	
	if (argc != 4){
		printf("ERROR: Numero de parametros incorrectos\n");
	} else {
		if (comparaCadenas(argv[2],"cm")){
			c.tipoIn = cm;
		} 
		else if (comparaCadenas(argv[2],"in")){
			c.tipoIn = in;
		}
		else{
			printf("ERROR: Medida 1 erronea");
			error = 1;
		}
		
		if (!error){
			if (comparaCadenas(argv[3],"cm")){
				c.tipoOut = cm;
			} 
			else if (comparaCadenas(argv[3],"in")){
				c.tipoOut = in;
			}
			else{
				printf("ERROR: Medida 2 erronea");
				error = 1;
			}
		}
		if (!error){
			dato = strtof(argv[1], &errNum);
			if (*errNum != '\0'){
				printf("ERROR: Dato no numerico\n");
			}
			else {
				c.valor = dato;
				valorNuevo=convertirLongitud(c)
			}
		}
	}
}



int comparaCadenas(char *c1, char *c2){
	while(*c1!='\0' && *c2 != '\0' && (*(c1++)==*(c2++)));
	return *(--c1)==*(--c2);
}

double convertirLongitud(conversion_t c){
	double valorNuevo=0;
	if (c.tipoIn == cm && c.tipoOut == in){
		valorNuevo = c.valor/2.53;
	} 
	else if (c.tipoIn == in && c.tipoOut == cm){
		valorNuevo = c.valor*2.53;
	}
	return valorNuevo;
}