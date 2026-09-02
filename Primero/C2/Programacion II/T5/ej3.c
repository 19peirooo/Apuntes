#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listaCadenas_t{
    char **cadenas;
    int numCadenas;
}listaCadenas_t;

void ordenaCadenas(listaCadenas_t *lista);
listaCadenas_t leeCadenas(char *nomFic);
char *leeLineaFichero(FILE* f);
int main(int argc, char **argv){
    listaCadenas_t lista = {NULL,0};
    if (argc != 2){
        printf("ERROR: Argumentos");
    } else {
        lista=leeCadenas(argv[1]);
        ordenaCadenas(&lista);
        for (int i = 0; i < lista.numCadenas; i++){
            printf("%d %s", i+1,lista.cadenas[i]);
        }
        free(lista.cadenas);
        lista.cadenas = NULL;
        lista.numCadenas = 0;
    }
    for (int i = 0; i < lista.numCadenas; i++){
        free(lista.cadenas[i]);
    }
    free(lista.cadenas);
    return 0;
}
void ordenaCadenas(listaCadenas_t *lista){ //Bubble Sort
    char *temp = NULL;
    for (int i = 0; i < lista->numCadenas; i++){
        for (int j = i+1; j < lista->numCadenas; j++){
            if(strcmp(lista->cadenas[i],lista->cadenas[j]) > 0){
                temp = lista->cadenas[i];
                lista->cadenas[i] = lista->cadenas[j];
                lista->cadenas[j] = temp;
            }
        }
    }
    free(temp);
}

char *leeLineaFichero(FILE* f){
    char *linea=NULL;
    int chars = 0;
    char c;

    do{
        c = getc(f);
        linea = (char*)realloc(linea,sizeof(char)*(chars+1));
        linea[chars++] = c;
    }while(((!feof(f)) && linea[chars-1] != '\n'));
    if (chars > 0){
        linea[chars-1] = '\0';
    }
    return linea;
}
listaCadenas_t leeCadenas(char *nomFic){
    FILE *f = fopen(nomFic,"rb");
    listaCadenas_t lista={NULL,0};
    char *lineaAux=NULL;
    if (f != NULL){
        while (!feof(f)){
            lineaAux = leeLineaFichero(f);
            if (strlen(lineaAux)>0){
                lista.cadenas=(char**)realloc(lista.cadenas,sizeof(char*)*(lista.numCadenas+1));
                lista.cadenas[lista.numCadenas++] = lineaAux;
            }else{
                free(lineaAux);
            }
        }
        fclose(f);
    }else{
        printf("ERROR: No se pudo abrir fichero\n");
    }
    return lista;
}