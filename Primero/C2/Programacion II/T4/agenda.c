#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum bool_e{V=1,F=0}bool_e;

typedef enum tiposLista_e{
	contacto,string,integer
}tiposLista_e;

//Lista Generica
typedef struct lista_t{
	union{
		struct contacto_t *contactos;
		char *cadena;
		int *arrayInt;
	};
	tiposLista_e tipo;
	int tam;
}lista_t;

typedef struct contacto_t{
	lista_t nombre;
	lista_t apellidos;
	lista_t telefono;
}contacto_t;

bool_e existeFichero(char* nombre);
contacto_t pedirContacto();
lista_t leeLineaDinamicaFichero(FILE *f);
lista_t leeNumerosDinamicosFichero(FILE *f);
void introducirContactoEnLista(lista_t* agenda);
void mostrarContactos(lista_t *agenda);
void salvaContactos(char *nombreFichero, lista_t *agenda);
void cargaContactos(char *nombreFichero, lista_t *agenda);
int main(int argc , char **argv){
	//Crear lista de contactos
	lista_t agenda={.tipo = contacto,.contactos=NULL, .tam = 0};
	char *fichero = "agenda.txt";
	bool_e menuAbierto = V;
	int opcion=0;
	//Si existe fichero
	if (existeFichero(fichero)){
		//cargar datos
		cargaContactos(fichero,&agenda);
	}

	//Menu
	while (menuAbierto){
		printf("1-Nuevo Contacto\n");
		printf("2-Mostrar Contactos\n");
		printf("3-Salir\n");
		printf("Opcion: ");
		scanf("%d",&opcion);
		while(getchar() != '\n');
		switch (opcion){
			case 1:{
				introducirContactoEnLista(&agenda);
			}break;
			case 2:{
				mostrarContactos(&agenda);
			}break;
			case 3:{
				menuAbierto = F;
				printf("Saliendo del programa... \n");
			}break;
			default:{
				printf("ERROR: Opcion No Valida\n");
			}break;
		}
	}
	//guardar lista
	salvaContactos(fichero,&agenda);
	//Liberar lista
	for (int i = 0; i < agenda.tam;i++){
		free(agenda.contactos[i].nombre.cadena);
		free(agenda.contactos[i].apellidos.cadena);
		free(agenda.contactos[i].telefono.arrayInt);
	}
	free(agenda.contactos);
	return 0;
}

bool_e existeFichero(char *nombre){
	FILE *f = fopen(nombre,"rb");
	bool_e existe = V;
	if (f == NULL){
		existe = F;
	}
	else {
		fclose(f);
		existe = V;
	}
	return existe;
}

contacto_t pedirContacto(){
	contacto_t c ={.nombre=NULL,.apellidos=NULL,.telefono=NULL};
	printf("Introduzca nombre: ");
	c.nombre = leeLineaDinamicaFichero(stdin);
	printf("Introduzca apellidos: ");
	c.apellidos = leeLineaDinamicaFichero(stdin);
	printf("Introduzca telefono: ");
	c.telefono = leeNumerosDinamicosFichero(stdin);
	return c;
}

lista_t leeLineaDinamicaFichero(FILE*f){
	
	lista_t lista = {.tipo = string, .cadena = NULL, .tam = 0};
	char *linea;
	char c;
	int chars;
	
	do{
		c = getc(f);
		if (c != EOF){
			linea = (char*)realloc(linea,sizeof(char)*chars+1);
			linea[chars++] = c;
		}
	}while (linea [chars-1] != '\n' && (!feof(f))); //Mientras que no hayamos leido el ultimo caracter o no se acabe el fichero
	if (chars > 0){
		linea[chars-1] = '\0';
	}
	lista.cadena = linea;
	lista.tam = chars;
	return lista;
}

lista_t leeNumerosDinamicosFichero(FILE*f){
	
	lista_t lista = {.tipo = integer, .arrayInt = NULL, .tam = 0};
	int *linea=NULL;
	int tam=0;
	int c;
	
	do{
		//Lee el numero
		c = getc(f);
		if (c != EOF && c >='0' && c <='9'){
			c-='0';
			linea = (int*)realloc(linea,sizeof(int)*tam+1);
			linea[tam++] = c;
		}
	}while (c != '\n' && (!feof(f))); //Mientras que no hayamos leido el ultimo caracter o no se acabe el fichero
	lista.arrayInt = linea;
	lista.tam = tam;
	return lista;
}

void introducirContactoEnLista(lista_t* agenda){
	//redimensionar
	agenda->contactos = (contacto_t*)realloc(agenda->contactos,sizeof(contacto_t)*(agenda->tam+1));
	//pedir contacto
	agenda->contactos[agenda->tam] = pedirContacto();
	agenda->tam++;
}

void mostrarContactos(lista_t *agenda){
	printf("\n");
	for (int i = 0; i < agenda->tam;i++){
		printf("Nombre: %s", agenda->contactos[i].nombre.cadena);
		printf("Apellido: %s", agenda->contactos[i].apellidos.cadena);
		printf("Telefono: ");
		for (int j = 0; j < agenda->contactos[i].telefono.tam; j++){
			printf("%d ",agenda->contactos[i].telefono.arrayInt[j]);
		}
		printf("\n");
	}
	printf("\n");
}

void salvaContactos(char *nombreFichero, lista_t *agenda){
	//Abrir fichero
	FILE* fOut = fopen(nombreFichero,"wb");
	int len=0;
	//Guardo el numero de contactos
	fwrite(&agenda->tam,sizeof(int),1,fOut);
	//Por cada contacto
	for (int i = 0; i < agenda->tam; i++){
		//Escribir nombre y su tamaño
		len = agenda->contactos[i].nombre.tam;
		fwrite(&len,sizeof(int),1,fOut);
		fwrite(agenda->contactos[i].nombre.cadena,sizeof(char),len,fOut);
		//Escribir apellido y su tamaño
		len = agenda->contactos[i].apellidos.tam;
		fwrite(&len,sizeof(int),1,fOut);
		fwrite(agenda->contactos[i].apellidos.cadena,sizeof(char),len,fOut);
		//Escribir numero y su tamaño
		fwrite(&agenda->contactos[i].telefono.tam,sizeof(int),1,fOut);
		fwrite(agenda->contactos[i].telefono.arrayInt,sizeof(int),agenda->contactos[i].telefono.tam,fOut);
	}
	fclose(fOut);
}

void cargaContactos(char *nombreFichero, lista_t *agenda){
	int numContactos=0;
	//Abrir fichero
	FILE* fIn = fopen(nombreFichero,"rb");
	//Leer numero de contactos
	fread(&agenda->tam, sizeof(int),1,fIn);
	agenda->contactos=(contacto_t*)realloc(agenda->contactos,sizeof(contacto_t)*agenda->tam);
	//Por cada contacto
	for (int i = 0; i < agenda->tam; i++){
		//Leer nombre
			//leer tamaño
		fread(&agenda->contactos[i].nombre.tam,sizeof(int),1,fIn);
			//leer nombres
		agenda->contactos[i].nombre.cadena = (char*)malloc(sizeof(char)*agenda->contactos[i].nombre.tam);
		fread(agenda->contactos[i].nombre.cadena,sizeof(char),agenda->contactos[i].nombre.tam,fIn);
		//Leer apellido
			//leer tamaño
		fread(&agenda->contactos[i].apellidos.tam,sizeof(int),1,fIn);
			//leer nombres
		agenda->contactos[i].apellidos.cadena = (char*)malloc(sizeof(char)*agenda->contactos[i].apellidos.tam);
		fread(agenda->contactos[i].apellidos.cadena,sizeof(char),agenda->contactos[i].apellidos.tam,fIn);
		//Leer numero
			//leer tamaño
		fread(&agenda->contactos[i].telefono.tam,sizeof(int),1,fIn);
			//leer nombres
		agenda->contactos[i].telefono.arrayInt = (int*)malloc(sizeof(int)*agenda->contactos[i].telefono.tam);
		fread(agenda->contactos[i].telefono.arrayInt,sizeof(int),agenda->contactos[i].telefono.tam,fIn);
	}
	fclose(fIn);
}