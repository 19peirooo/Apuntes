#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	
}

char *leeLineaDinamicaFichero(FILE *f){
    char *linea = NULL;
    int chars = 0;
    do{
        linea = (char*)realloc(linea,sizeof(char)*(chars+1));
        linea[chars++] = getc(f);           
    }while((linea[chars-1] != '\n') && (!feof(f)));
    if (chars > 0){
        linea[chars-1] = '\0';
    }
    return linea;
}