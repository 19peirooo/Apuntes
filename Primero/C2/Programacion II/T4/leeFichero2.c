#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct string_t{
    char* cadena;
    int tam;
}string_t;

int tamFichero(char *nombre);

int main(){
    string_t contenido={.cadena = NULL,.tam = 0};

    int tam = tamFichero("texto.txt");
    contenido.tam = tam;
    contenido.cadena = (char*)realloc(contenido.cadena,tam+1);

    FILE *f = fopen("texto.txt","rb");
    fread(contenido.cadena,tam,1,f);
    fclose(f);
    contenido.cadena[tam] = '\0';
    //mostrar
    printf("%s\n", contenido.cadena);

    //liberar
    free(contenido.cadena);
}

int tamFichero(char *nombre){
    FILE *f=fopen(nombre,"rb");
    if (f!=NULL){
        fseek(f,0,SEEK_END); //Te mueve al final del fichero
        int tam = (int)ftell(f); //Posicion en la que estas
        fseek(f,0,SEEK_SET);
        fclose(f);
    }
    else{
        printf("ERROR: Fichero no existe\n");
    }
}