#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef enum bool_e{V=1,F=0}bool_e;

typedef struct partida_t{
    int* turnos;
    int numTurnos;
}partida_t;

void generarCarton(int carton[3][5]);
void  imprimirCarton(int carton[3][5]);
void lanzaBingo(int c1[3][5], int c2[3][5], partida_t *partida);

void Cantar(int carton[3][5], int *estado);
int main(int argc, char* argv){
    int carton1[3][5] = {0};
    int carton2[3][5] = {0};
    partida_t partida = {NULL,0};
    bool_e partidaFinalida = F;
    srand(time(NULL));
    generarCarton(carton1);
    generarCarton(carton2);
    printf("Carton 1: \n");
    imprimirCarton(carton1);
    printf("Carton 2: \n");
    imprimirCarton(carton2);
    lanzaBingo(carton1,carton2,&partida);
    free(partida.turnos);
    return 0;    
}

void generarCarton(int carton[3][5]){
    int nums[15] = {0};
    int num = 0;
    int k = 0;
    bool_e repetido = F;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 5; j++){
            repetido = V;
            while (repetido){
                num = rand()%100+1;
                repetido = F;
                for (int i = 0; i < 15 && !repetido; i++){
                    if (num == nums[i]){
                        repetido = V;
                    }
                }
                if (!repetido){
                    carton[i][j] = num;
                    nums[k++] = num;
                }
            }
            
        }
    }
}

void  imprimirCarton(int carton[3][5]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 5; j++){
            printf("| %d ",carton[i][j]);
        }
        printf("|\n");
    }
}

void lanzaBingo(int c1[3][5], int c2[3][5], partida_t* partida){
    bool_e partidaFinalizada = F;
    int num = 0;
    bool_e repetido = F;
    int estado = 0;
    bool_e lineaCantada = F;
    printf("Pulse Enter para pasar al siguente turno: \n");
    while (!partidaFinalizada){
        while (getchar() != '\n');
        do{
            num = rand()%100+1;
            repetido = F;
            for (int i = 0; i < partida->numTurnos; i++){
                if (partida->turnos[i] == num){
                    repetido = V;
                }
            }
            if(!repetido){
                partida->turnos = (int*)realloc(partida->turnos, sizeof(int)*(partida->numTurnos+1));
                partida->turnos[partida->numTurnos++] = num;
            }
        }while(repetido);
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 5; j++){
                if (c1[i][j] == num){
                    c1[i][j] = 0;
                }
                if (c2[i][j] == num){
                    c2[i][j] = 0;
                }
            }
        }
        printf("Numero: %d\n",num);
        printf("Numeros que ya han salido: [");
        for (int i = 0; i < partida->numTurnos; i++){
            printf("%d,", partida->turnos[i]);
        }
        printf("]\n");
        Cantar(c1,&estado);
        if (estado == 1 && !lineaCantada){
            printf("El jugador 1 ha cantado linea\n");
            lineaCantada = V;
        }
        else if (estado == 2){
            printf("El jugador 1 ha cantado bingo\n");
            partidaFinalizada = V;
        }
        Cantar(c2,&estado);
        if (estado == 1 && !lineaCantada){
            printf("El jugador 2 ha cantado linea\n");
            lineaCantada = V;
        }
        else if (estado == 2){
            printf("El jugador 2 ha cantado bingo\n");
            partidaFinalizada = V;
        }
        printf("Carton 1: \n");
        imprimirCarton(c1);
        printf("Carton 2: \n");
        imprimirCarton(c2);
    }
}

void Cantar(int carton[3][5], int *estado){
    bool_e esLinea = V;
    int numFilasCompletas = 0;
    for (int i = 0; i < 3; i++){
        esLinea = V;
        for (int j = 0; j < 5; j++){
            if (carton[i][j] != 0){
                esLinea = F;
            }
        }
        if (esLinea){
            numFilasCompletas++;
            if (*estado == 0){
                *estado = 1;
            }
        }
        if (numFilasCompletas == 3){
            *estado = 2;
        }
    }
}