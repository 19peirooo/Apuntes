#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	
	FILE *fOut=NULL;
	fOut = fopen("tablaAscii.csv","w");
	if (fOut == NULL){
		printf("ERROR: No se ha podido crear fichero");
	}
	else {
		for (char i = 'A'; i <= 'Z'; i++){
			fprintf(fOut,"%c\t%d\n",i,(int)i);
		}
		fprintf(fOut,"\n");
		for (char i = 'a'; i <= 'z'; i++){
			fprintf(fOut,"%c\t%d\n",i,(int)i);
		}
		fclose(fOut);
	}
	return 0;
}