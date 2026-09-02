#include <stdio.h>
#include <stdlib.h>

// Se le van a pasar 2 numeros enteros
// Standard: Tocho que te tienes que leer para documentar

int main(int argc, char **argv){
	float media;
	for (int i = 1; i < argc ; i++){
		media+=atof(argv[i]); //Convierte el parametro a float. atoi para integer. atol par long int
	}
	printf("La media es: %f\n", media/(float)(argc-1));
	return 0;
}