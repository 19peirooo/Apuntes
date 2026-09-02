#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	FILE *fOut=NULL;
	char dato;
	fOut = fopen("ejemplo4.txt","r+");
	fseek(fOut,8,SEEK_SET); //Leo desde el caracter 7, SEEK_SET para empezar desde el principo, SEEK_END para empezar por el final
	dato = getc(fOut);
	printf("Dato Leido: %c", dato);
	fclose(fOut);
}