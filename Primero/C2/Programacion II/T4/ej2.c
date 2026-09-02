#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void leeFichero(char *nombreFichero, int numLineas);
char *leeLineaDinamicaFic(FILE *f);

int main(int argc, char **argv){
    int numLineas = 0;
    char *error=NULL;
    if (argc == 3){
        numLineas = (int)strtol(argv[1],&error, 10);
        if (*error == '\0'){
            leeFichero(argv[2],numLineas);
        } else {
            printf("ERROR: Primero parametro no es numerico");
        }
    }else{
        printf("ERROR: Numero de parametros no correcto");
    }
    return 0;
}

void leeFichero(char *nombreFichero, int numLineas){
    char *cadena = NULL;
    FILE *f = fopen(nombreFichero, "rb");
    for (int i = 0; i < numLineas; i++){
        cadena = leeLineaDinamicaFic(f);
        printf("Linea %d %s\n", i+1, cadena);
    }
    free(cadena);
}

char *leeLineaDinamicaFic(FILE *f){
    char* linea = NULL;
    int chars = 0;

    do{
        linea = (char*)realloc(linea,chars+1);
        linea[chars++] = getc(f);
    }while (linea[chars-1] != '\n' && (!feof(f)));
    if (chars > 0){
        linea[chars-1] = '\0';
    }
    
    return linea;
}