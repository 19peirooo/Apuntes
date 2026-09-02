#include <stdio.h>
#include <stdlib.h>

typedef enum bool_e{V=1,F=0}bool_e;

typedef struct pareja_t{
	char nombre1[11];
	char nombre2[11];
	int victorias;
	int setsAFavor;
	int setsEnContra;
}pareja_t;

typedef struct listaParejas_t{
	pareja_t pareja[4];
	int numParejasMax;
	int numParejasIntroducidas;
}listaParejas_t;

typedef struct partidos_t{
	pareja_t equipos[2];
	int setsEquipo1;
	int setsEquipo2;
}partidos_t;

typedef struct jornadas_t{
	int numJornada;
	partidos_t partido[2];
}jornadas_t;

typedef struct listaJornadas_t{
	jornadas_t jornada[3];
	int numJornadasIntroducidas;
	int numJornadasMax;
}listaJornadas_t;

bool_e comparaCadenas(char c1[], char c2[]);
int calcularTamCadena(char c1[]);
partidos_t crearPartido(pareja_t equipo1, pareja_t equipo2);
void mostrarPartido(partidos_t partido);
void encontrarGanador(listaParejas_t parejas);


int main(int argc, char **argv){
	bool_e menuAbierto = V;
	bool_e nombreCorrecto = V;
	int i = 1, j = 0;
	int opcion;
	
	listaParejas_t parejas={
		.numParejasMax = 4,
		.numParejasIntroducidas = 0
	};
	
	listaJornadas_t jornadas={
		.numJornadasMax = 3,
		.numJornadasIntroducidas = 0
	};
	
	if (argc != 9){
		printf("ERROR: Numero de parametros incorrectos");
	}
	else{
		//Veo si hay nombres repetidos y si todos los nombres tiene menos de 10 caracteres
		for (int i = 1; i < 9; i++){
			if(calcularTamCadena(argv[i]) > 10){
				printf("ERROR: Has superado el maximo numero de caracteres\n");
				menuAbierto = F;
				nombreCorrecto = F;
			}
			for (int j = 1; j < 9 && menuAbierto == V; j++){
				if (comparaCadenas(argv[i],argv[j]) == V && i != j){
					printf("ERROR: No se pueden repetir nombres\n");
					menuAbierto=F;
					nombreCorrecto = F;
				}
			}
		}
		//Si los nombres introducidos son todos correctos, crear parejas
		if (nombreCorrecto == V){
			while(parejas.numParejasIntroducidas < parejas.numParejasMax){
				j = 0;
				while (argv[i][j] != '\0'){
					parejas.pareja[parejas.numParejasIntroducidas].nombre1[j] = argv[i][j];
					j++;
				}
				parejas.pareja[parejas.numParejasIntroducidas].nombre1[j] = '\0';
				j=0;
				while (argv[i+1][j] != '\0'){
					parejas.pareja[parejas.numParejasIntroducidas].nombre2[j] = argv[i+1][j];
					j++;
				}
				parejas.pareja[parejas.numParejasIntroducidas].nombre2[j] = '\0';
				i+=2;
				parejas.numParejasIntroducidas++;
			}
		}
		
		//Creo el menu
		while (menuAbierto == V){
			printf("1- Introducir Resultado de una jornada\n"
			"2- Mostrar Resultados\n"
			"3- Mostrar Pareja Ganadora\n"
			"4- Salir\n"
			"Opcion: ");
			scanf("%d",&opcion);
			while (getchar() != '\n');
			switch (opcion){
				case 1:{
					if (jornadas.numJornadasIntroducidas < jornadas.numJornadasMax){
						jornadas.jornada[jornadas.numJornadasIntroducidas].numJornada = jornadas.numJornadasIntroducidas+1;
						if (jornadas.numJornadasIntroducidas == 0){
							jornadas.jornada[jornadas.numJornadasIntroducidas].partido[0] = crearPartido(parejas.pareja[0],parejas.pareja[1]);
							//Resultados del partido
							if (jornadas.jornada[jornadas.numJornadasIntroducidas].partido[0].setsEquipo1 > jornadas.jornada[jornadas.numJornadasIntroducidas].partido[0].setsEquipo2){
								parejas.pareja[0].victorias++;
							} else {
								parejas.pareja[1].victorias++;
							}
							parejas.pareja[0].setsAFavor += jornadas.jornada[jornadas.numJornadasIntroducidas].partido[0].setsEquipo1;
							parejas.pareja[0].setsEnContra += jornadas.jornada[jornadas.numJornadasIntroducidas].partido[0].setsEquipo2;
							parejas.pareja[1].setsAFavor += jornadas.jornada[jornadas.numJornadasIntroducidas].partido[0].setsEquipo2;
							parejas.pareja[1].setsEnContra += jornadas.jornada[jornadas.numJornadasIntroducidas].partido[0].setsEquipo1;
							
							jornadas.jornada[jornadas.numJornadasIntroducidas].partido[1] = crearPartido(parejas.pareja[2],parejas.pareja[3]);
							if (jornadas.jornada[jornadas.numJornadasIntroducidas].partido[1].setsEquipo1 > jornadas.jornada[jornadas.numJornadasIntroducidas].partido[1].setsEquipo2){
								parejas.pareja[2].victorias++;
							} else {
								parejas.pareja[3].victorias++;
							}
							parejas.pareja[2].setsAFavor += jornadas.jornada[jornadas.numJornadasIntroducidas].partido[1].setsEquipo1;
							parejas.pareja[2].setsEnContra += jornadas.jornada[jornadas.numJornadasIntroducidas].partido[1].setsEquipo2;
							parejas.pareja[3].setsAFavor += jornadas.jornada[jornadas.numJornadasIntroducidas].partido[1].setsEquipo2;
							parejas.pareja[3].setsEnContra += jornadas.jornada[jornadas.numJornadasIntroducidas].partido[1].setsEquipo1;
						}
						else if(jornadas.numJornadasIntroducidas == 1){
							jornadas.jornada[jornadas.numJornadasIntroducidas].partido[0] = crearPartido(parejas.pareja[0],parejas.pareja[2]);
							if (jornadas.jornada[jornadas.numJornadasIntroducidas].partido[0].setsEquipo1 > jornadas.jornada[jornadas.numJornadasIntroducidas].partido[0].setsEquipo2){
								parejas.pareja[0].victorias++;
							} else {
								parejas.pareja[2].victorias++;
							}
							parejas.pareja[0].setsAFavor += jornadas.jornada[jornadas.numJornadasIntroducidas].partido[0].setsEquipo1;
							parejas.pareja[0].setsEnContra += jornadas.jornada[jornadas.numJornadasIntroducidas].partido[0].setsEquipo2;
							parejas.pareja[2].setsAFavor += jornadas.jornada[jornadas.numJornadasIntroducidas].partido[0].setsEquipo2;
							parejas.pareja[2].setsEnContra += jornadas.jornada[jornadas.numJornadasIntroducidas].partido[0].setsEquipo1;
							
							jornadas.jornada[jornadas.numJornadasIntroducidas].partido[1] = crearPartido(parejas.pareja[1],parejas.pareja[3]);
							if (jornadas.jornada[jornadas.numJornadasIntroducidas].partido[1].setsEquipo1 > jornadas.jornada[jornadas.numJornadasIntroducidas].partido[1].setsEquipo2){
								parejas.pareja[1].victorias++;
							} else {
								parejas.pareja[3].victorias++;
							}
							parejas.pareja[1].setsAFavor += jornadas.jornada[jornadas.numJornadasIntroducidas].partido[1].setsEquipo1;
							parejas.pareja[1].setsEnContra += jornadas.jornada[jornadas.numJornadasIntroducidas].partido[1].setsEquipo2;
							parejas.pareja[3].setsAFavor += jornadas.jornada[jornadas.numJornadasIntroducidas].partido[1].setsEquipo2;
							parejas.pareja[3].setsEnContra += jornadas.jornada[jornadas.numJornadasIntroducidas].partido[1].setsEquipo1;
						} else {
							jornadas.jornada[jornadas.numJornadasIntroducidas].partido[0] = crearPartido(parejas.pareja[0],parejas.pareja[3]);
							if (jornadas.jornada[jornadas.numJornadasIntroducidas].partido[0].setsEquipo1 > jornadas.jornada[jornadas.numJornadasIntroducidas].partido[0].setsEquipo2){
								parejas.pareja[0].victorias++;
							} else {
								parejas.pareja[3].victorias++;
							}
							parejas.pareja[0].setsAFavor += jornadas.jornada[jornadas.numJornadasIntroducidas].partido[0].setsEquipo1;
							parejas.pareja[0].setsEnContra += jornadas.jornada[jornadas.numJornadasIntroducidas].partido[0].setsEquipo2;
							parejas.pareja[3].setsAFavor += jornadas.jornada[jornadas.numJornadasIntroducidas].partido[0].setsEquipo2;
							parejas.pareja[3].setsEnContra += jornadas.jornada[jornadas.numJornadasIntroducidas].partido[0].setsEquipo1;
							jornadas.jornada[jornadas.numJornadasIntroducidas].partido[1] = crearPartido(parejas.pareja[1],parejas.pareja[2]);
							if (jornadas.jornada[jornadas.numJornadasIntroducidas].partido[1].setsEquipo1 > jornadas.jornada[jornadas.numJornadasIntroducidas].partido[1].setsEquipo2){
								parejas.pareja[1].victorias++;
							} else {
								parejas.pareja[2].victorias++;
							}
							parejas.pareja[1].setsAFavor += jornadas.jornada[jornadas.numJornadasIntroducidas].partido[1].setsEquipo1;
							parejas.pareja[1].setsEnContra += jornadas.jornada[jornadas.numJornadasIntroducidas].partido[1].setsEquipo2;
							parejas.pareja[2].setsAFavor += jornadas.jornada[jornadas.numJornadasIntroducidas].partido[1].setsEquipo2;
							parejas.pareja[2].setsEnContra += jornadas.jornada[jornadas.numJornadasIntroducidas].partido[1].setsEquipo1;
						}
						jornadas.numJornadasIntroducidas++;
					}
					else {
						printf("ERROR: Ya has introducido todas las jornadas\n");
					}
				}break;
				case 2:{
					if (jornadas.numJornadasIntroducidas != 0){
						for (int i = 0; i < jornadas.numJornadasIntroducidas;i++){
							mostrarPartido(jornadas.jornada[i].partido[0]);
							mostrarPartido(jornadas.jornada[i].partido[1]);
						}
					}
					else {
						printf("ERROR: No has introducido una jornada aun. Prueba de nuevo\n");
					}
				}break;
				case 3:{
					if (jornadas.numJornadasIntroducidas != 3){
						printf("ERROR: No has introducido todas las jornadas\n");
					} else {
						encontrarGanador(parejas);
					}
				}break;
				case 4:{
					printf("Finalizando Programa...");
					menuAbierto = F;
				}break;
				default:{
					printf("ERROR: Opcion Invalida\n");
				}break;
			}
		}
	}
	return 0;
}

//Compara 2 cadenas
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

//Devuelve el tamaño de 1 cadena
int calcularTamCadena(char c1[]){
	int tam=0;
	while (c1[tam] != '\0'){
		tam++;
	}
	return tam;
}


partidos_t crearPartido(pareja_t equipo1, pareja_t equipo2){
	partidos_t p1;
	bool_e resValido=F;
	p1.equipos[0] = equipo1;
	p1.equipos[1] = equipo2;
	printf("%s y %s vs %s y %s\n", equipo1.nombre1,equipo1.nombre2,equipo2.nombre1,equipo2.nombre2);
	while(resValido == F){
		printf("Introduzca el resultado del partido separado por espacio:");
		scanf("%d %d",&p1.setsEquipo1,&p1.setsEquipo2);
		while(getchar() != '\n');
		if ((p1.setsEquipo1 + p1.setsEquipo2 == 3) && (p1.setsEquipo1 != 0 && p1.setsEquipo2 != 0)){
			resValido = V;
		}
		else if ((p1.setsEquipo1 + p1.setsEquipo2 == 2) && (p1.setsEquipo1 != 1 && p1.setsEquipo2 != 1)){
			resValido = V;
		}
		else {
			resValido = F;
			printf("ERROR: Resultados no concuerdan con la normas del torneo\n");
		}
	}
	return p1;
}

void mostrarPartido(partidos_t partido){
	printf("%s y %s vs %s y %s: %d %d\n",partido.equipos[0].nombre1,partido.equipos[0].nombre2,partido.equipos[1].nombre1,partido.equipos[1].nombre2,partido.setsEquipo1, partido.setsEquipo2);	
}

void encontrarGanador(listaParejas_t parejas){
	int equipoGanador=0, diferenciaEquipo1=0, diferenciaEquipo2;
	pareja_t g1,g2;
	bool_e empate=F;
	for (int i = 0; i < parejas.numParejasMax; i++){
		if (parejas.pareja[equipoGanador].victorias < parejas.pareja[i].victorias){
			equipoGanador = i;
			empate = F;
		} 
		else if (parejas.pareja[equipoGanador].victorias == parejas.pareja[i].victorias && i != equipoGanador){
			diferenciaEquipo1 = parejas.pareja[equipoGanador].setsAFavor - parejas.pareja[equipoGanador].setsEnContra;
			diferenciaEquipo2 = parejas.pareja[i].setsAFavor - parejas.pareja[i].setsEnContra;
			if (diferenciaEquipo2 > diferenciaEquipo1){
				equipoGanador = i;
				empate = F;
			}
			else if (diferenciaEquipo2 == diferenciaEquipo1){
				empate = V;
				g1 = parejas.pareja[equipoGanador];
				g2 = parejas.pareja[i];
			}
		}
	}
	if (empate == V){
		printf("Empate entre %s-%s y %s-%s\n",g1.nombre1,g1.nombre2,g2.nombre1,g2.nombre2);
	}
	else {
		printf("Ganador: %s y %s\n",parejas.pareja[equipoGanador].nombre1,parejas.pareja[equipoGanador].nombre2);
	}
}