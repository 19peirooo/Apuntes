#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum bool_e{V=1,F=0}bool_e;

bool_e existeFichero(char* nombreFic);
char* leeLineaDFichero(FILE* f);
void copiaFichero(char* entrada, char* salida);

int main(int argc, char** argv){
    if (argc != 3){
        printf("ERROR: Numero de parametros incorrectos\n");
    }
    else if (strlen(argv[1]) > 16 || strlen(argv[2]) > 16){
        printf("ERROR: Longitud de nombre muy larga para alguno de los ficheros\n");
    }
    else if (!existeFichero(argv[1])){
        printf("ERROR: Fichero de entrada no existe\n");
    }
    else if (strcmp(argv[1],argv[2]) == 0){
        printf("ERROR: El fichero de entrada y salida son el mismo\n");
    }
    else{
        copiaFichero(argv[1], argv[2]);
    }
    return 0;
}

bool_e existeFichero(char* nombreFic){
    bool_e existe = F;
    FILE *f = fopen(nombreFic,"rb");
    if (f != NULL){
        existe = V;
        fclose(f);
    }
    return existe;
}

char* leeLineaDFichero(FILE* f){
    char* linea = NULL;
    int chars = 0;

    do{
        linea = (char*)realloc(linea, chars+1);
        linea[chars++] = getc(f);
    }while(linea[chars-1] != '\n' && !feof(f));
    if (chars > 0){
        linea[chars-1] = '\0';
    }
    return linea;
}

void copiaFichero(char* entrada, char* salida){
    FILE *fIn = fopen(entrada, "rb");
    FILE *fOut = fopen(salida, "wb");
    char* linea = NULL;
    int numLinea = 1;
    do{
        linea = leeLineaDFichero(fIn);
        printf("Linea %d: %s\n",numLinea,linea);
        fprintf(fOut,"Linea %d: %s\n",numLinea,linea);
        numLinea++;
    }while (!feof(fIn));
    fclose(fIn);
    fclose(fOut);
}