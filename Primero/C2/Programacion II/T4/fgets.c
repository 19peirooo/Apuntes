#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	FILE *fOut=NULL;
	char datos[100];
	fOut = fopen("ejemplo4.txt","r+");
	fgets(datos,100,fOut); //Lee una linea
	printf("%s\n",datos);
	fclose(fOut);
}