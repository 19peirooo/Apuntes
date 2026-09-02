#include <stdio.h>
#include <stdlib.h>

int tamFichero (char *fileName);

int main(int argc, char **argv){
	printf("Tam Fichero: %d",tamFichero(argv[1]));
	return 0;
}

int tamFichero (char *fileName){
	int size = 0;
	FILE *fout;
	fout = fopen(fileName,"r+");
	if (fout != NULL){
		fseek(fout,0,SEEK_END);
		size = ftell(fout);
		fclose(fout);
	}
	return size;
}