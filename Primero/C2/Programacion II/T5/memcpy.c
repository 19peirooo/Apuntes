#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char **argv){
    /*const char* p1 = "Hola Mundo";
    int len = strlen(p1), size = sizeof(char)+len+1;
    char* copia = NULL;
    copia = (char*)realloc(copia,size);

    memcpy(copia,p1,size);

    int lenOrigen = 6;
    int sizeOrigen = sizeof(int)*lenOrigen;
    int *intOrigen = (int*)malloc(sizeof(int)*lenOrigen);

    for (int i = 0; i < lenOrigen; i++){
        intOrigen[i] = i;
    }

    int *intCopia = (int*)malloc(sizeof(int)*lenOrigen);
    memcpy(intCopia,intOrigen,sizeOrigen);*/

    const char* dato1 = "hola";
    const char* dato2 = " ";
    const char* dato3 = "mundo";

    char *destino = (char*)calloc(sizeof(char)*(strlen("hola mundo")),sizeof(char));
    memcpy(destino+strlen(dato1)+strlen(dato2), dato3, sizeof(char)*(strlen(dato3)+1));
    memcpy(destino+strlen(dato1), dato2, sizeof(char)*strlen(dato2));
    memcpy(destino, dato1, sizeof(char)*strlen(dato1));
    printf("Destino: %s",destino);
    free(destino);
    return 0;
}