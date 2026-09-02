#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
    char *origen = "cadena origen";
    char *copia = NULL;

    copia = (char*)realloc(copia,sizeof(char)*(strlen(origen)+1)); //strlen(cadena): Tamaño de una cadena sin \0

    printf("Cadena 2: %s\n", copia);
    strcpy(copia,origen); // strcpy(destino,origen): Copia una cadena en otra. Incluye \0
    printf("Cadena 2: %s\n", copia);
    free(copia);
    return 0;
}