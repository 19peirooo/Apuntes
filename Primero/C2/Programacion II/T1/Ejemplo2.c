#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	float media = 0;
	char *error=NULL;
	float parcial = 0;
	int correcto = 1;
	
	for (int i = 1; i < argc; i++){
		parcial=(float)strtol(argv[i], &error, 10); //Segundo parametro para deteccion de errores
		if (*error != '\0'){
			correcto = 0;
			printf("Error. EL argumento %s no es un entero\n", argv[i]);
		} else {
			media+=parcial;
		}
	}
	if (correcto){
		printf("La media es: %f", media/(float)(argc-1));
	} else {
		printf("No se ha podido calcular la media");
	}
	
	return 0;
}