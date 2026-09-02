#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
	char *letras=NULL;
	char ultimaLetraLeida='\0';
	int numLetrasLeidas=0;
	int numLetrasMax=10;
	
	//Inicializar array letras
	//letras = (char*)malloc(NULL,sizeof(char)*numLetrasMax);Sintaxis: (tipo_array)malloc(tamaño maximo);
	letras = (char*)realloc(letras,sizeof(char)*numLetrasMax);//Sintaxis: (tipo_array)realloc(array anterior,tamaño maximo);
	printf("Introduce letras hasta acabar con \n");
	
	//bucle
	//mientras que la letra no sea \n, leer y almacenar
	while (ultimaLetraLeida = '\n'){
		
		ultimaLetraLeida=getchar();
		if (numLetrasLeidas == numLetrasMax){
			//Redimensionar array
			numLetrasMax+=10;
			letras = (char*)realloc(letras,sizeof(char)*numLetrasMax);
			if (letras == NULL){
				printf("ERROR: No hay memoria");
				//Liberar Memoria, cerrar ficheros,avisar procesos/usuarios de cierre
				exit(0);
			}
		}
		letras[numLetrasLeidas]=ultimaLetraLeida;
		numLetrasLeidas++;
	}
	if (numLetrasLeidas == numLetrasMax){ //Para poder controlar si el ultimo es '\n'
		numLetrasMax+=1;
		letras = (char*)realloc(letras,sizeof(char)*numLetrasMax);
	}
	letras[numLetrasLeidas]='\0';
	printf("Las Letras Leidas han sido: %s\n", letras);
	memset(letras,0,numLetrasMax); //Reinicia Memoria
	free(letras); //Liberar memoria reservada no usada
	return 0;
}