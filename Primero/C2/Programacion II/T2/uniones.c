#include <stdio.h>

typedef struct vector3f{
	union{ //Utiles para tener 2 maneras de representar datos
		float x,y,z; 
		float coords[3];
	};
}vector3f;

typedef union numeros_t{
	int numI;
	float numF;
	char numC;
}numeros_t;

typedef struct numeros1_t{
	int numI;
	float numF;
	char numC;
}numeros1_t;

int main(int argc, char **argv){
	
	numeros_t nums;
	
	printf("Size Union: %ld \n", sizeof(numeros_t)); //Tamaño de una union --> Numeros de Bytes del tipo interno mas grande. TAM 4
	printf("Size Struct: %ld \n", sizeof(numeros1_t)); //Tamaño del struct --> Alinea todo a un multiplo de 4. TAM: 12
	
	printf("Introduzca un Numero Entero: ");
	scanf("%d", &nums.numI);
	printf("%d\n", nums.numI);
	printf("Introduzca un Numero en coma flotante: ");
	scanf("%f", &nums.numF);
	printf("%.2f\n", nums.numF);
	printf("%d\n", nums.numI); //Muestra Completa Basura ya que numF le ha quitado el sitio
	
}