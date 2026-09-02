#include <stdio.h>
#include <stdlib.h>

int *leeNumerosDinamicos();

typedef struct listaEnteros_t{
	int *numeros;
	int num;
}listaEnteros_t;

int main(int argc, char **argv){
	listaEnteros_t lista={.numeros=NULL,.num=0};
	int num1 = 0, salir=0;
	int num;
	int error;
	do{
		printf("Introduzca un numero: ");
		error = scanf("%d",&num);
		while(getchar() != '\n');
		if (error==1){
			if (lista.num == 0){
				num1 = num;
				lista.numeros=(int*)realloc(lista.numeros,sizeof(int)*(lista.num+1));
				lista.numeros[lista.num++] = num;
			}
			else {
				if (num1 < num){
					salir = 1;
				}
				else {
					lista.numeros=(int*)realloc(lista.numeros,sizeof(int)*(lista.num+1));
					lista.numeros[lista.num++] = num;
				}
			}
		}
		else{
			printf("ERROR: Parametro no numerico\n");
		}
	}while(!salir);
	
	for (int i = 0; i < lista.num; i++){
		printf("%d\n",lista.numeros[i]);
	}
	free(lista.numeros);
}