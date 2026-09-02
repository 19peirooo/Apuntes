#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum bool_e{V=1,F=0}bool_e;

bool_e existeFichero(char* nombreFic);
void cuentaNotas(FILE* fIn, int* histo);
void creaHistograma(FILE* fOut, int* histo);
char* leeLineaDFichero(FILE* f);

int main(int argc, char** argv){
    FILE *fIn = NULL;
    FILE* fOut = NULL;
    int histograma[11] = {0};
    if (argc != 2){
        printf("ERROR: Numero de parametros incorrectos\n");
    }
    else if (!(existeFichero(argv[1]))){
        printf("ERROR: Fichero de entrada no existe\n");
    }
    else{
        fIn = fopen(argv[1],"rb");
        fOut = fopen("histograma.txt","wb");
        cuentaNotas(fIn,histograma);
        creaHistograma(fOut, histograma);
        fclose(fIn);
        fclose(fOut);
    }

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

void cuentaNotas(FILE* fIn, int* histo){
    char* numero = NULL;
    int notaEntera = 0;
    char *error = NULL;
    while (!feof(fIn)){
        numero = leeLineaDFichero(fIn);
        if (numero[0] != '\0'){
            notaEntera = (int)strtof(numero,&error);
            if (*error == '\0'){
                histo[notaEntera]+=1;
            }
        }
        free(numero);
    }
}

char* leeLineaDFichero(FILE* f){
    char* linea = NULL;
    int chars = 0;

    do{
        linea = (char*)realloc(linea,sizeof(char)*(chars+1));
        linea[chars++] = getc(f);
    }while (linea[chars-1] != '\n' && (!feof(f)));
    if (chars > 0){
        linea[chars-1] = '\0';
    }
    return linea;
}

void creaHistograma(FILE* fOut, int* histo){
    for (int i = 0; i < 11; i++){
        fprintf(fOut,"%d\t", i);
        for (int j = 0; j < histo[i]; j++){
            fprintf(fOut,"*");
        }
        fprintf(fOut,"\n");
    }
}