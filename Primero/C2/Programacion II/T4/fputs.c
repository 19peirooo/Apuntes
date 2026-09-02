#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	FILE *fOut=NULL;
	fOut = fopen("ejemplo4.txt","w");
	fputs("Hola Mundo fputs\n",fOut); //Para introducir cadenas
	fclose(fOut);
}