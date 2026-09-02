#include <stdio.h>
#include <stdlib.h>

#define MAX_MESAS 100
#define MAX_MESAS_PEDIDOS 5

typedef enum bool_e{V=1,F=0}bool_e;

typedef enum material_e{
	plastico=0,madera=1,cristal=2,metal=3
}material_e;

char *materiales[4]={"Plastico","Madera","Cristal","Metal"};

typedef struct mesas_t{
	float ancho;
	float alto;
	float fondo;
	material_e material;
	float precio;
}mesas_t;

typedef struct listaMesas_t{
	mesas_t mesa[MAX_MESAS];
	int numMesasMax;
	int numMesasIntroducidas;
}listaMesas_t;

mesas_t nuevaMesa();
void mostrarMesa(mesas_t mesa);
void crearPedido(listaMesas_t mesas);
int calcularNumeroIndices(char *indices);

int main(int argc, char **argv){
	bool_e menuAbierto = V;
	int opcion=0;
	listaMesas_t mesas={
		.numMesasIntroducidas=0,
		.numMesasMax=MAX_MESAS
	};
	while (menuAbierto == V){
		printf("	-------------------------------\n"
		"	1- Introducir nueva mesa\n"
		"	2- Mostrar Mesas Disponibles\n"
		"	3- Calcular Precio Pedido\n"
		"	4- Salir\n"
		"	-------------------------------\n"
		"Opcion: ");
		scanf("%d", &opcion);
		while(getchar() != '\n');
		switch (opcion){
			case 1:{
				if (mesas.numMesasIntroducidas < mesas.numMesasMax){
					mesas.mesa[mesas.numMesasIntroducidas] = nuevaMesa();
					mesas.numMesasIntroducidas++;
				} else {
					printf("ERROR: Has alcanzado el numero maximo de mesas\n");
				}
			}break;
			case 2:{
				if (mesas.numMesasIntroducidas == 0){
					printf("ERROR: No has introducido ninguna mesa aun\n");
				} 
				else {
					for (int i = 0; i < mesas.numMesasIntroducidas; i++){
						printf("------------------------------------------------\n");
						printf("Mesa %d:\n", i+1);
						mostrarMesa(mesas.mesa[i]);
						printf("------------------------------------------------\n");
						printf("\n");
					}
				}
			}break;
			case 3:{
				crearPedido(mesas);
			}break;
			case 4:{
				printf("Finalizando Programa...");
				menuAbierto = F;
			}break;
			default:{
				printf("ERROR: Opcion Invalida");
			}break;
		}
	}
	return 0;
}

mesas_t nuevaMesa(){
	mesas_t m1;
	printf("Introduce el ancho de la mesa: ");
	scanf("%f", &m1.ancho);
	while(getchar() != '\n');
	printf("Introduce el alto de la mesa: ");
	scanf("%f", &m1.alto);
	while(getchar() != '\n');
	printf("Introduce el fondo de la mesa: ");
	scanf("%f", &m1.fondo);
	while(getchar() != '\n');
	printf("Introduce el precio de la mesa: ");
	scanf("%f", &m1.precio);
	while(getchar() != '\n');
	do{
		printf("Introduce el valor correspondiente a el material de la mesa: \n"
		"0-Plastico\n"
		"1-Madera\n"
		"2-Cristal\n"
		"3-Metal\n"
		"Valor: ");
		scanf("%d", &m1.material);
		while(getchar() != '\n');
		if (m1.material < 0 || m1.material > 3){
			printf("ERROR: Valor no corresponde con ningun material\n");
		}
	}while (m1.material < 0 || m1.material > 3);
	return m1;
}

void mostrarMesa(mesas_t mesa){
	printf("Tamanio Mesa ancho/alto/fondo: %.2f/%.2f/%.2f\n", mesa.ancho,mesa.alto,mesa.fondo);
	printf("Material: %s\n", materiales[mesa.material]);
	printf("Precio: %.2f\n", mesa.precio);
}

void crearPedido(listaMesas_t mesas){
	bool_e entradaCorrecta = F;
	char indices[12]={'\0'};
	char numero[4]={'\0'};
	char *error = NULL;
	int num;
	float precio=0;
	int j=0,k=0,tam=0,numIndices=0;
	
	for (int i = 0; i < mesas.numMesasIntroducidas; i++){
		printf("------------------------------------------------\n");
		printf("Mesa %d:\n", i+1);
		mostrarMesa(mesas.mesa[i]);
		printf("------------------------------------------------\n");
		printf("\n");
	}
	while (entradaCorrecta == F){
		entradaCorrecta = V;
		precio=0;
		printf("Introduce los indices de las mesas que quieres comprar separadas por comas(max 5): ");
		scanf("%s",indices);
		while (getchar() != '\n');
		k=calcularNumeroIndices(indices);
		if (k > 5){
			entradaCorrecta = F;
			printf("ERROR: Numero de indices superior a 5\n");
		}
		while (numIndices != k && entradaCorrecta == V){
			if (indices[tam] != ',' && indices [tam] != '\0'){
				numero[j] = indices[tam];
				j++;
				tam++;
			}
			else if (indices[tam] == ',' || indices [tam] == '\0'){
				numero[j] = '\0';
				num = atof(numero);
				if (num > mesas.numMesasIntroducidas){
					printf("ERROR: Indice mayor que numero de mesas introducidas\n");
					entradaCorrecta = F;
				}
				else{
					precio += mesas.mesa[num-1].precio;
					j=0;
					tam++;
					numIndices++;
				}
			}
		}
		printf("Precio Final: %.2f euros\n",precio);
	}
}

int calcularNumeroIndices(char *indices){
	int numIndices=1;
	while(*indices != '\0'){
		if (*indices == ','){
			numIndices++;
		}
		indices++;
	}
	return numIndices;
}