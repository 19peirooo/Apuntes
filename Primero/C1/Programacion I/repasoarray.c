#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void array1();
void array2();

int main(){
	array2();
	return 0;
}

//Arrays
void array1(){
	//Array de 5 posiciones
	int arr1[5] = {1,2,3,4,5};
	//Asignar el valor 10 a la segunda posicion
	arr1[1] = 10;
	//Mostrar contenido de la quinta posicion
	printf("%d",arr1[4]);
	//Mostrar el contenido del array
	for (int x = 0; x < (sizeof(arr1)/sizeof(int)); x++){
		printf("Posicion: %d, Elemento: %d \n", x+1,arr1[x]);
	}
	
	//Pedirle al usuario que rellene el 3 elemento
	printf("Introduce un numero entero:");
	scanf("%d \n",&arr1[2]);
}

void array2(){
	int arr2[10];
	int randnum,num,encontrado = 0,i, repetido = 0, pos;
	srand((unsigned int)getpid);
	//Asigna un numero aleatorio a cada elemento del array
	for(i = 0; i < (sizeof(arr2)/sizeof(int)); i++){
		repetido = 0;
		while (!repetido){
			randnum = (rand()%31);
			//Comprueba si el numero aleatorio ya existe en el array
			for(int x = 0; x < (sizeof(arr2)/sizeof(int)); x++){
				if (arr2[x] == randnum){
					repetido = 1;
				}
			}
			if (!repetido){
				arr2[i] = randnum;
				repetido = 1;
			}
			else{
				repetido = 0;
			}
		}
	}
	//Imprime el array
	for (int x = 0; x < (sizeof(arr2)/sizeof(int)); x++){
		printf("Posicion: %d, Elemento: %d \n", x+1,arr2[x]);
	}
	//Pide un numero al usuario, si esta dentro del array, para el programa
	while (!encontrado){
		printf("Introduce un numero: ");
		scanf("%d",&num);
		//Comprueba si el numero esta en el array
		for (i = 0; i < (sizeof(arr2)/sizeof(int)); i++){
			if (arr2[i] == num){
				encontrado = 1;
				pos = i;
			}
		}
		if (encontrado){
			printf("Numero encontrado en la posicion: %d \n", pos+1);
		}
		else{
			printf("Numero No Encontrado\n");
			encontrado = 0;
		}
	}
}