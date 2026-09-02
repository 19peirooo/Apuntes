#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct fichero_t{
    char** lineas;
    int numLineas;
}fichero_t;

fichero_t cargarFichero(char* nombreFichero);
char* leeLineaFichero(FILE *f);
void intercambiarLineas(fichero_t *fic, int l1, int l2);
void guardarFichero(char* nombreFichero, fichero_t fic);
int main(int argc, char **argv){
    int num1=0;
    int num2=0;
    char *errorNum1 = NULL;
    char *errorNum2 = NULL;
    char* nombreFichero = "ej3.txt";
    fichero_t fic1 = {NULL,0};

    if (argc != 3){
        printf("ERROR: Numero de parametros incorrecto\n");
    } else {        
        num1 = (int)strtol(argv[1],&errorNum1, 10);
        num2 = (int)strtol(argv[2],&errorNum2, 10);
        if (*errorNum1 != '\0' || *errorNum2 != '\0'){
            printf("ERROR: Parametros no numericos");
        } else {
            fic1 = cargarFichero(nombreFichero);
            if (num1 < fic1.numLineas && num2 < fic1.numLineas){
                intercambiarLineas(&fic1,num1,num2);
                for (int i = 0; i < fic1.numLineas; i++){
                    printf("%s\n", fic1.lineas[i]);
                }
                guardarFichero(nombreFichero,fic1);
            } else {
                printf("ERROR: Lineas no estan en el fichero");
            }
        }
    }

    for (int i = 0; i < fic1.numLineas; i++){
        free(fic1.lineas[i]);
    }
    free(fic1.lineas);
    return 0;
}

fichero_t cargarFichero(char* nombreFichero){
    FILE* f = fopen(nombreFichero, "rb");
    fichero_t fic={NULL,0};
    if (f != NULL){
        while (!feof(f)){
            fic.lineas = (char**)realloc(fic.lineas, sizeof(char*)*(fic.numLineas+1));
            fic.lineas[fic.numLineas++] = leeLineaFichero(f);
        }
        fclose(f);
    } else {
        printf("ERROR: No se pudo abrir el fichero\n");
    }
    return fic;
}

char* leeLineaFichero(FILE *f){
    char *linea=NULL;
    int chars=0;
    do{
        linea = (char*)realloc(linea,chars+1);
        linea[chars++] = getc(f);
    }while(linea[chars-1] != '\n' && (!feof(f)));
    if (chars > 0){
        linea[chars-1] = '\0';
    }
    return linea;
}

void intercambiarLineas(fichero_t *fic, int l1, int l2){
    char *temp = NULL;
    temp = fic->lineas[l1-1];
    fic->lineas[l1-1] = fic->lineas[l2-1];
    fic->lineas[l2-1] = temp;

}

void guardarFichero(char* nombreFichero, fichero_t fic){
    FILE *f = fopen(nombreFichero, "wb");
    if (f == NULL){
        printf("ERROR: No se pudo abrir el fichero\n");
    }else{
        for (int i = 0; i < fic.numLineas; i++){
            fwrite(fic.lineas[i],strlen(fic.lineas[i]),1,f);
            fwrite("\n",1,1,f);
        }
        fclose(f);
    }
    
}