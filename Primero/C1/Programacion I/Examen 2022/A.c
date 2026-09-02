#include <stdio.h>

#define TAM 100

void calcularRepetidos(int nums[TAM], int repes[9], int i);
void calcularConsecutivo(int nums[TAM], int *cons, int i);

void main(){
	int numeros[TAM] = {0};
	int repetidos[9] = {0};
	int mayor_consecutivo;
	int num,err,total=0;
	
	//Mientras que el numero no sea 0 o no se puedan poner mas numeros en el array
	while(num != 0 && total < TAM){
		num = 1;
		printf("Introduce un numero: ");
		err = scanf("%d", &num);
		while (getchar() != '\n'); //Limpia el buffer
		
		// Si no es un numero del 0 al 9
		if (err != 1 || num > 9 || num < 0){ 
			printf("El dato introducido no es correcto. \n");
		}
		else{
			if (num != 0){
				numeros[total] = num;
				total++;
			}
		}
	}
	calcularRepetidos(numeros,repetidos,total);
	calcularConsecutivo(numeros,&mayor_consecutivo,total);
	printf("Numero total de digitos introducidos: %d \n", total);
	for (int x = 0; x < 9; x++){
		if (repetidos[x] != 0){
			printf("Numero %d: %d\n",x+1,repetidos[x]);
		}
	}
	printf("El numero introducido mas veces de manera consecutiva es: %d", mayor_consecutivo);
}

void calcularRepetidos(int nums[TAM], int repes[9], int i){
	for (int x = 0; x < i; x++){
		repes[nums[x]-1]++;
	}
}

void calcularConsecutivo(int nums[TAM],int *cons, int i){
	int numsConsecutivos=1;
	int consecutivos[9] = {0};
	*cons = 1;
	for(int x = 0; x < i; x++){
		if (nums[x] == nums[x+1]){
			numsConsecutivos++;
		}
		else{
			if (consecutivos[nums[x]-1] < numsConsecutivos){
				consecutivos[nums[x]-1] = numsConsecutivos;
			}
			numsConsecutivos = 1;
		}
	}
	for (int x = 0; x < 9; x++){
		if (consecutivos[x] > consecutivos[*cons-1]){
			*cons = x+1;
		}
	}
}