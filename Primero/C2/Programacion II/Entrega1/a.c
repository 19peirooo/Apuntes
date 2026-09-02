#include <stdio.h>
#include <stdlib.h>

#define TAMMAX 41
#define MAX_CHARS 10

typedef enum bool_e{V=1,F=0}bool_e;

//Esta estructura almacena los caracteres introducidos y cuantas veces aparecen
typedef struct listaCaracteres_t{
	char caracteres[MAX_CHARS];
	int ocurrencias[MAX_CHARS];
	int numCaracteresMax;
	int numCaracteresIntroducidos;
}listaCaracteres_t;

void introducirCadena(char frase[]);
int ocurrenciasPorLetra(char frase[], char letra);
void mostrarOccurencias(listaCaracteres_t c1);

int main(int argc, char **argv){
	bool_e menuAbierto=V;
	int opcion=0;
	char frase[TAMMAX];
	
	listaCaracteres_t chars={
		.numCaracteresMax=MAX_CHARS,
		.numCaracteresIntroducidos=argc
	};
	
	
	//Compruebo si el usuario a introducido entre 1 y 10 caracteres
	//Sino Error
	if (chars.numCaracteresIntroducidos < 2){
		printf("ERROR: Numero de Caracteres Insuficiente");
	}
	else if (chars.numCaracteresIntroducidos > 11){
		printf("ERROR: El Programa a recibido demasiado caracteres");
	}
	else{
		//Guardo los caracteres introducidos en un array
		for (int i = 1; i < chars.numCaracteresIntroducidos; i++){
			if (argv[i][1] != '\0'){
				printf("ERROR: Parametro %d contiene mas de un caracter", i-1);
				menuAbierto=F;
			} 
			else {
				for (int j = 0; j < i; j++){
					if (argv[i][0] == chars.caracteres[j]){
						printf("ERROR: Has repetido un caracter. No se pueden repetir\n");
						menuAbierto = F;
					}
				}
				chars.caracteres[i-1] = argv[i][0];
			}
			
		}
		//Creo el menu
		while (menuAbierto == V){
			opcion=0;
			printf("	----------------------------------------\n"
			"	Pulse 1 para introducir una nueva frase\n"
			"	Pulse 2 para mostrar el resultado\n"
			"	Pulse 3 para salir del Programa\n"
			"	----------------------------------------\n");
			printf("Opcion: ");
			scanf("%d", &opcion);
			while (getchar()!='\n');
			
			//Control de Entrada
			switch (opcion){
				//Caso 1: Introducir Frase
				case 1:{
					introducirCadena(frase);
					for (int i = 0; i < chars.numCaracteresIntroducidos-1; i++){
						chars.ocurrencias[i] += ocurrenciasPorLetra(frase, chars.caracteres[i]);
					}
				}break;
				//Caso 2: Mostrar cuantas veces aparece cada caracter
				case 2:{
					mostrarOccurencias(chars);
				}break;
				//Caso 3: Salir del programa
				case 3:{
					menuAbierto=F;
					printf("Finalizando Programa...");
				}break;
				//Caso Erroneo: Mostrar error
				default:{
					printf("ERROR: Opcion Incorrecta\n");
				}break;
			}
		}
	}
	return 0;
}

void introducirCadena(char frase[]){
	char c;
	int tamCadena=0;
	printf("Introduce la frase: ");
	//Introduccion de cadena
	while(((c=getchar())!='\n') && tamCadena < TAMMAX-1){
		frase[tamCadena] = c;
		tamCadena++;
	}
	
	if (tamCadena == TAMMAX-1){
		printf("ERROR: Te has excedido de los caracteres maximos. Se cojeran los primeros 40 caracteres\n");
		while (getchar()!='\n');
	}
	frase[tamCadena] = '\0';
}

int ocurrenciasPorLetra(char frase[], char letra){
	int occ=0;
	int i = 0;
	while (frase[i] != '\0'){
		//Si la letra de la frase es igual a la letra que buscamos
		if (frase[i] == letra){
			occ++;
		}
		i++;
	}
	//Devolver las occurrecias
	return occ;
}

void mostrarOccurencias(listaCaracteres_t c1){
	//Por cada caracter introducido
	//Imprimir en formato caracter: occurrencias
	for (int i = 0; i < c1.numCaracteresIntroducidos-1; i++){
		printf("%c: %d\n", c1.caracteres[i],c1.ocurrencias[i]);
	}
}