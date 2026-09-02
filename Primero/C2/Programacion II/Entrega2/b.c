#include <stdio.h>
#include <stdlib.h>

typedef enum bool_e{V=1,F=0}bool_e;

typedef enum tipoAudio_e{
	WAV=0,MP3=1,OGG=2
}tipoAudio_e;

char *nombresAudios[3]={"WAV","MP3","OGG"};

typedef struct estacion_t{
	char *nombre;
	float latitud,longitud;
}estacion_t;

typedef struct grabacion_t{
	char *nombre;
	char *fecha;
	tipoAudio_e formato;
	estacion_t *estacion;
}grabacion_t;

typedef struct listaGrabaciones_t{
		grabacion_t *grabaciones;
		int numGrabaciones;
}listaGrabaciones_t;

typedef struct listaEstaciones_t{
		estacion_t *estaciones;
		int numEstaciones;
}listaEstaciones_t;

char* leeLineaDinamica();
grabacion_t nuevaGrabacion();
void imprimirGrabacion(grabacion_t g);
void imprimirEstacion(estacion_t e);
estacion_t nuevaEstacion();
bool_e comprobarFecha(char *fecha);
bool_e comparaCadenas(char c1[], char c2[]);

int main(int argc, char **argv){
	bool_e menuAbierto = V;
	bool_e estacionEncontrada=F;
	
	listaEstaciones_t est={.numEstaciones=0};
	listaGrabaciones_t gr={.numGrabaciones=0};
	
	char *nombreEstacion=NULL;
	int opcion=0,grabacionesPorEstacion=0;
	
	while(menuAbierto == V){
		printf("\t-----------------------------------------\n"
		"\t 1. Introducir datos de una grabacion\n"
		"\t 2. Introducir datos de una estacion\n"
		"\t 3. Asignar grabaciones a estaciones\n"
		"\t 4. Mostrar datos de estaciones\n"
		"\t 5. Salir\n"
		"\t-----------------------------------------\n"
		"Opcion: "
		);
		scanf("%d",&opcion);
		while(getchar()!='\n');
		switch (opcion){
			case 1:{
				gr.grabaciones = (grabacion_t*)realloc(gr.grabaciones,sizeof(grabacion_t)*(gr.numGrabaciones+1));
				if (gr.grabaciones == NULL){
					printf("ERROR: No hay memoria disponible");
					menuAbierto = F;
				}
				else {
					gr.grabaciones[gr.numGrabaciones++] = nuevaGrabacion();
				}
			}break;
			case 2:{
				est.estaciones = (estacion_t*)realloc(est.estaciones,sizeof(estacion_t)*(est.numEstaciones+1));
				if (est.estaciones == NULL){
					printf("ERROR: No hay memoria disponible");
					menuAbierto = F;
				}
				else {
					est.estaciones[est.numEstaciones++] = nuevaEstacion();
				}
			}break;
			case 3:{
				if (est.numEstaciones == 0){
					printf("ERROR: Aun no las introducido ninguna estacion\n");
				}
				else if (gr.numGrabaciones == 0){
					printf("ERROR: Aun no has introducido ninguna grabacion\n");
				}
				else {
					for(int i = 0; i < gr.numGrabaciones; i++){
						estacionEncontrada=F;
						if (gr.grabaciones[i].estacion == NULL){
							imprimirGrabacion(gr.grabaciones[i]);
							printf("Estacion no asignada\n");
							printf("Introduzca el nombre de la estacion: ");
							nombreEstacion = leeLineaDinamica();
							for (int j = 0; j < est.numEstaciones && estacionEncontrada == F; j++){
								estacionEncontrada = comparaCadenas(nombreEstacion,est.estaciones[j].nombre);
								if (estacionEncontrada == V){
									gr.grabaciones[i].estacion = &est.estaciones[j];
								}
							}
							if (estacionEncontrada == F){
								printf("ERROR: Estacion no encontrada\n");
								gr.grabaciones[i].estacion = NULL;
							}
						}
					}
				}
				
			}break;
			case 4:{
				if (est.numEstaciones == 0){
					printf("ERROR: Aun no las introducido ninguna estacion\n");
				}
				else{
					for (int i = 0; i < est.numEstaciones; i++){
						printf("\n\t Estacion %d\n", i);
						imprimirEstacion(est.estaciones[i]);
						grabacionesPorEstacion=0;
						for (int j = 0; j < gr.numGrabaciones; j++){
							if (comparaCadenas(est.estaciones[i].nombre,gr.grabaciones[j].estacion->nombre)==V){
								printf("-----------------Grabacion %d-----------------\n",grabacionesPorEstacion);
								imprimirGrabacion(gr.grabaciones[j]);
								grabacionesPorEstacion++;
							}
						}
					}
				}
				
			}break;
			case 5:{
				menuAbierto = F;
			}break;
			default:{
				printf("ERROR: Entrada Invalida\n");
			}break;
		}
	}
	for (int i = 0; i < gr.numGrabaciones; i++){
		free(gr.grabaciones[i].nombre);
		free(gr.grabaciones[i].fecha);
	}
	free(gr.grabaciones);
	for (int i = 0; i < est.numEstaciones; i++){
		free(est.estaciones[i].nombre);
	}
	free(est.estaciones);
	free(nombreEstacion);
	return 0;
}

char *leeLineaDinamica(){
	char *linea=NULL;
	int chars=0;
	linea = (char*)malloc(chars);
	
	do{
		linea = (char*)realloc(linea,chars+1);
		linea[chars] = getchar();
		chars++;
	}while (linea [chars-1] != '\n');
	linea[chars-1] = '\0';
	return linea;
}

grabacion_t nuevaGrabacion(){
	grabacion_t g;
	bool_e fechaValida = F;
	int f = -1;
	printf("Introduce el nombre del fichero: ");
	g.nombre = leeLineaDinamica();
	while(fechaValida == F){
		printf("Introduce la fecha de grabacion: ");
		g.fecha = leeLineaDinamica();
		fechaValida = comprobarFecha(g.fecha);
	}
	while(f < 0 || f > 2){
		printf("Introduce la opcion correspondiente al formato de video:\n"
		"0. WAV\n"
		"1. MP3\n"
		"2. OGG\n"
		"Opcion: ");
		scanf("%d",&f);
		while(getchar()!='\n');
		if (f < 0 || f > 2){
			printf("ERROR: Opcion incorrecta\n");
		}
	}
	
	g.formato = f;
	g.estacion=NULL;
	return g;
}

void imprimirGrabacion(grabacion_t g){
	printf("Nombre Archivo: %s\n",g.nombre);
	printf("Fecha de Grabacion: %s\n",g.fecha);
	printf("Formato: %s\n",nombresAudios[g.formato]);
}

void imprimirEstacion(estacion_t e){
	printf("Nombre de la Estacion: %s\n",e.nombre);
	printf("Latitud: %f\n", e.latitud);
	printf("Longitud: %f\n", e.longitud);
}

bool_e comprobarFecha(char *fecha){
	bool_e esCorrecta = V;
	char *errDia,*errMes,*errAnyo;
	int diaI,mesI,anyoI;
	char dia[3],mes[3],anyo[5];
	int i = 0;
	int tamCadena = 0;
	
	while(fecha[i] != '\0'){
		tamCadena++;
		i++;
	}
	if (tamCadena != 10){
		esCorrecta = F;
		printf("ERROR: Tamanyo de fecha incorrecto\n");
	}
	else {
		if (fecha[2] != '/' || fecha[5] != '/' || fecha[10] != '\0'){
			esCorrecta = F;
			printf("ERROR: Formato Incorrecto de fecha\n");
		}
	}
	if (esCorrecta == V){
		for (int i = 0; i < 2; i++){
			dia[i] = fecha[i];
		}
		dia[2] = '\0';
		for (int i = 3; i < 5; i++){
			mes[i-3] = fecha[i];
		}
		mes[2] = '\0';
		for (int i = 6; i < 10; i++){
			anyo[i-6] = fecha[i];
		}
		anyo[4] = '\0';
		diaI = (int)strtol(dia,&errDia,10);
		if(*errDia != '\0' || diaI > 31 || diaI < 1){
			printf("ERROR: Dia incorrecto\n");
			esCorrecta = F;
		}
		mesI = (int)strtol(mes,&errMes,10);
		if(*errMes != '\0' || mesI > 12 || mesI < 1){
			printf("ERROR: Mes incorrecto\n");
			esCorrecta = F;
		} 
	
		anyoI = (int)strtol(anyo,&errAnyo,10);
		if(*errAnyo != '\0' || anyoI > 9999 || anyoI < 1){
			printf("ERROR: Anyo incorrecto\n");
			esCorrecta = F;
		}
	}
	return esCorrecta;
}

estacion_t nuevaEstacion(){
	estacion_t e;
	int err=0;
	printf("Introduce el nombre de la estacion: ");
	e.nombre = leeLineaDinamica();
	while (err != 1){
		printf("Introduce la latidud: ");
		err = scanf("%f",&e.latitud);
		while (getchar() != '\n');
		if (err != 1){
			printf("ERROR: Latitud no numerica\n");
		}
	}
	err = 0;
	while (err != 1){
		printf("Introduce la longitud: ");
		err = scanf("%f",&e.longitud);
		while (getchar() != '\n');
		if (err != 1){
			printf("ERROR: Longitud no numerica\n");
		}
	}
	return e;
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