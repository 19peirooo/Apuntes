#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#define TAM 50

void movimiento_nave(int *pos, int x); //Funcion para mover los oponentes. Parametros x para ver que oponente es 

int main(){
	char pista[TAM];//Pista
	char opcion;
	int obstaculo, posiciones; //Variables para obtener numeros aleatorios
	int pos_j = 0,pos_op1 = 0,pos_op2 = 0;//Para ver la posicion de cada nave
	int i; // Variables Intermedias
	int valido = 0; //Para comprobar si la entrada es correcta
	int GameOver = 0; // Variable para comprobar si se ha acabado el juego
	
	pista[0] = 'J';//Coloco como placeholder a la nave del jugador para las 3 naves
	
	//Relleno el array de guiones
	for (i = 1; i < sizeof(pista)/sizeof(char);i++){
		pista[i] = '-';
	}
	
	//Imprimo pista inicial
	for (i = 0; i < TAM; i++){
		printf("%c", pista[i]);
	}
	printf("|\n");
	
	while (!GameOver){
		valido = 0;
		srand(time(NULL)); //Semilla para los numero aleatorios
		while(!valido){
			opcion = 'f';
			printf("Introduce que quieres hacer(f/a): ");
			scanf("%c", &opcion);
			if (opcion == 'f'){ //Si frena
				printf("Jugador: Freno\n");
				if (pos_j > 0){ //Comprueba si puede moverse para atras
					pos_j -= 1;
				}
				else{
					printf("No puedes retroceder. Te mantenienes en la misma posicion\n");
				}
				valido = 1;
			}
			else if (opcion == 'a'){ //Si acelera
				printf("Jugador: Acelero\n");
				obstaculo = rand()%10+1;
				if (obstaculo == 2 || obstaculo == 1){
					printf("Has topado con un obstaculo. Penalización: Retrocede 3 casillas\n");
					if (pos_j > 2){ //Comprueba si puede moverse para atras
						pos_j -= 3;
					}
					else{
						pos_j = 0;
					}
				}
				else{
					posiciones = rand()%10+1;
					printf("Avanza %d posiciones\n", posiciones);
					pos_j += posiciones;
					if (pos_j > 49){ // Compruebo si se pasa de la meta
						pos_j = 49;
					}
				}
				valido = 1;
			}
		}
		movimiento_nave(&pos_op1,1); // Movimiento de nave 1
		movimiento_nave(&pos_op2,2); // Movimiento de nave 2
		
		//Actualizar pista
		for (i = 0; i < sizeof(pista)/sizeof(char);i++){
				pista[i] = '-';
		}
		pista[pos_j] = 'J';
		if (pos_op1 != pos_j){
			pista[pos_op1] = 'O';
		}
		if (pos_op2 != pos_j){
			pista[pos_op2] = 'O';
		}
		for (i = 0; i < sizeof(pista)/sizeof(char); i++){
			printf("%c", pista[i]);
		}
		printf("|\n");
		//Comprobar si ha acabado el juego
		if (pos_j == 49 || pos_op1 == 49 || pos_op2 == 49){
			GameOver = 1;
			if (pos_j == 49){
				printf("Has ganado la carrera");
			}
			else{
				printf("Has perdido la carrera");
			}
		}
	}
	return 0;
}

void movimiento_nave(int *pos, int x){
	int movimiento = rand()%10+1;
	int obstaculo = rand()%10+1;
	int posicion = rand()%10+1;
	if (movimiento <= 3 && movimiento >= 1){
		printf("Oponente %d : Freno\n", x);
		if (*pos > 0){
			*pos -= 1;
		}
		else{
			printf("Nave no pudo retroceder\n");
		}
	}
	else{
		printf("Oponente %d : Acelero\n", x);
		if (obstaculo == 2 || obstaculo == 1){
			printf("Oponente %d topado con un obstaculo. Penalización: Retrocede 3 casillas\n",x);
			if (*pos > 2){
				*pos -= 3;
			}
			else{
				*pos = 0;
			}
		}
		else{
			printf("Avanza %d posiciones\n", posicion);
			*pos += posicion;
			if (*pos > 49){
				*pos = 49;
			}
		}
	}
}