#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum bool_e{V=1,F=0}bool_e;

//Enumerado de armas
typedef enum arma_e{
	espada = 0,lanza=1
}arma_e;

char *tiposArma[]={"espada","lanza"}; //Array de definición

//Struct del gladiador
typedef struct gladiador_t{
	char nombre[11];
	int fuerza;
	int salud;
	arma_e arma;
}gladiador_t;

typedef struct listaGladiadores_t{
	gladiador_t gladiadores[2];
	int numGladiadoresMax;
	int gladActivo; //Puede tomar valores 0 o 1
	
}listaGladiadores_t;

gladiador_t crearGladiador(char datos[], bool_e *valido);
bool_e comparaCadenas(char c1[], char c2[]);
int atacar(gladiador_t atacante, gladiador_t *receptor);
void mostrarVencedor(gladiador_t g);


int main(int argc, char **argv){
	bool_e peleaActiva = V, gladValido=V;
	//Creo los gladiadores
	listaGladiadores_t glads={
		.gladActivo = 0,
		.numGladiadoresMax = 2
	};
	int opcion=0,randnum=0;
	//Si no se introducen 2 gladiadores
	//No ejecutar el resto
	if (argc != 3){
		printf("ERROR: Numero de parametros incorrecto");
	}
	else {
		//Creo los gladiadores
		for (int i = 0; i < glads.numGladiadoresMax; i++){
			gladValido=V;
			glads.gladiadores[i] = crearGladiador(argv[i+1],&gladValido);
			if (gladValido == F){
				printf("ERROR: Formato de Entrada Incorrecto para el Gladiador %d\n", i+1);
				peleaActiva = F;
			}
		}
		//Pelea Activa
		while (peleaActiva==V){
			//Comprueba de quien es el turno
			printf("Turno de %s:\n", glads.gladiadores[glads.gladActivo]);
			if (glads.gladActivo == 0){	
				//Turno Jugador
				do {
					printf("1. Atacar\n"
					"2. Defender\n"
					"Opcion: ");
					scanf("%d", &opcion);
					while (getchar() != '\n');
					
					//Si 1 atacar
					//Si 2 defender
					//Si ninguno error
					switch (opcion){
						case 1:{
							printf("Atacas a %s haciendo %d de danyo\n",glads.gladiadores[1].nombre,atacar(glads.gladiadores[0], &glads.gladiadores[1]));
						}break;
						case 2:{
							printf("Te has defendido\n");
						}break;
						default:{
							printf("ERROR: Opcion Incorrecta. Prueba de nuevo\n");
						}break;
					}
				}while (opcion != 1 && opcion != 2);
				glads.gladActivo = 1;
			} 
			else {
				//Turno Maquina
				//Genero numero aleatorio del 0 al 1
				srand(time(NULL));
				randnum = rand()%2;
				if (randnum == 0){
					printf("%s te ataca haciendo %d de danyo\n",glads.gladiadores[1].nombre,atacar(glads.gladiadores[1], &glads.gladiadores[0]));
				}
				else{
					printf("%s se defiende\n",glads.gladiadores[1].nombre);
				}
				glads.gladActivo = 0;
			}
			//Si la salud de alguno de los gladiadores es 0
			//Finalizar batalla
			if (glads.gladiadores[0].salud <= 0 || glads.gladiadores[1].salud <= 0){
				peleaActiva = F;
			} else {
				peleaActiva = V;
			}
		}
		//Si salud jugador menor que 0
		if (glads.gladiadores[0].salud <= 0){
			printf("Derrota\n");
			mostrarVencedor(glads.gladiadores[1]);
		} else {
			printf("Victoria\n");
			mostrarVencedor(glads.gladiadores[0]);
		} 
	}
	return 0;
}

gladiador_t crearGladiador(char datos[], bool_e *valido){
	int tam=0,tamArma=0,tamFuerza=0;
	char fuerza[3]={'\0'};
	char arma[7]={'\0'};
	int strength=0;
	char *error=NULL;
	bool_e errEscrito=F;
	gladiador_t g1={.salud=100};
	//Mientras que si habiendo cadena
	//Leer caracteres hasta encontrar una coma y guardar nombre
	
	while (datos[tam] != ','){
		if (tam < 10){
			g1.nombre[tam] = datos[tam];
		}
		else if (errEscrito == F && tam >= 10){
			printf("ERROR: Nombre demasiado largo, se cogeran solo los primero 10 caracteres\n");
			errEscrito = V;
		}
		tam++;
	}
	if (tam < 10){
		g1.nombre[tam]='\0';
	}
	else {
		g1.nombre[10]='\0';
	}
	tam++;
	//Leer caracteres hasta encontrar una coma y convertir fuerza a entero y guardarlo
	while (datos[tam] != ','){
		//Permito solo numeros del 0 al 99
		if (tamFuerza < 3){
			fuerza[tamFuerza]=datos[tam];
		}
		tamFuerza++;
		tam++;
	}
	if (tamFuerza < 3){
		fuerza[tamFuerza] = '\0';
	}
	else{
		fuerza[2] = '\0';
		printf("ERROR: Fuerza Introducida demasiado grande\n");
		*valido = F;
	}
	strength=(int)strtol(fuerza,&error,10);
	//Si la fuerza no es un entero, error
	if (*error != '\0' && *valido == V){
		printf("ERROR: Fuerza introducida no es un entero\n");
		*valido = F;
	}
	else{
		g1.fuerza = strength;
	}
	
	tam++;
	errEscrito = F;
	//Leer caracteres hasta final y ver si concuerda con un arma
	while (datos[tam] != '\0'){
		if (tamArma < 7){
			arma[tamArma] = datos[tam];
		}
		else if (errEscrito == F && tam >= 7){
			printf("ERROR: Arma Introducida no corresponde con las permitadas\n");
			*valido = F;
			errEscrito = V;
		}
		tam++;
		tamArma++;
	}
	if (tamArma < 7){
		arma[tamArma]='\0';
	}
	else {
		arma[6]='\0';
	}
	
	if (comparaCadenas(tiposArma[0],arma) == V && tamArma < 7){
		g1.arma = espada;
	}
	else if (comparaCadenas(tiposArma[1],arma) == V && tamArma < 7){
		g1.arma = lanza;
	}
	else {
		printf("ERROR: Arma Introducida no corresponde con las permitadas\n");
		*valido = F;
	}
	//Devolver gladiador
	return g1;
}

bool_e comparaCadenas(char c1[], char c2[]){
	bool_e esIgual=V;
	while (esIgual == V && (*c1 != '\0' || *c2 != '\0')){
		if (*c1 != *c2){
			esIgual = F;
		}
		else{
			c1++;
			c2++;
		}
	}
	return esIgual;
}

int atacar(gladiador_t atacante, gladiador_t *receptor){
	int multiplicador = 1;
	int dam = 0;
	//Si el arma es la lanza, hacer el doble de daño
	if (atacante.arma == lanza){
		multiplicador = 2;
	}
	dam = multiplicador * atacante.fuerza;
	//Le resto la vida al receptor
	receptor->salud -= dam;
	//Devuelvo el daño que hace el atacante
	return dam;
}

void mostrarVencedor(gladiador_t g){
	printf("Nombre: %s\n", g.nombre);
	printf("Tipo de Arma: %s\n",tiposArma[g.arma]);
	printf("Fuerza: %d\n", g.fuerza);
	printf("Salud: %d\n", g.salud);
}