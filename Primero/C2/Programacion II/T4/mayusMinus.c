#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	FILE *fOut=NULL;
	fOut = fopen("abecedario.txt","w");
	if (fOut == NULL){ //Si no ha sido abierto
		printf("Error abriendo fichero");
	}
	else {
		//Mayusculas
		for (char i = 'A'; i <= 'Z'; i++){
			fprintf(fOut,"%c;",i);
		}
		fprintf(fOut,"\n");
		//Minusculas
		for (char i = 'a'; i <= 'z'; i++){
			fprintf(fOut,"%c;",i);
		}
		fclose(fOut);
	}
	return 0;
}
