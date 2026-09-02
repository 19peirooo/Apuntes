#include <stdio.h>
#include <stdlib.h>

int main(int argc , char **argv){
	
	FILE* fic1 = stdout; //Variable de tipo fichero
	FILE* fic2 = stdin;
	FILE* ficTxt = NULL;
	char *datosLeidos = (char*)malloc(100);
	
	//fwrite("Hola Mundo\n",11,1,fic1); //11 caracteres de un byte
	//fread(datosLeidos,100,1,fic2); //100 caracteres de un byte, NO PARA HAS QUE SE INTRODUCEN LOS 100
	
	//printf y scanf para ficheros
	fscanf(stdin,"%s",datosLeidos);
	fprintf(stdout,"%s",datosLeidos);
	
	ficTxt = fopen("prueba1.txt","w"); //Crear un archivo, formato: nombre,modo de apertura(lectura,escritura,...)
	fwrite("HolaMundo\n",10,1,ficTxt); //Escribir en un fichero
	fclose(ficTxt); //Cierra el fichero
	
	ficTxt = fopen("prueba1.txt","r+"); //Lectura y escritura al inicio
	fprintf(ficTxt,"%d %d\n",5,3);
	fclose(ficTxt); 
	
	ficTxt = fopen("prueba1.txt","a+"); //escibir al final
	fprintf(ficTxt,"%d %d\n",7,8);
	fclose(ficTxt); 
	
	free(datosLeidos);
	return 0;
}

