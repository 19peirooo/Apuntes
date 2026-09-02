#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef enum bool_e{V=1,F=0}bool_e;

char* cargarFichero(char* nombreFichero);
bool_e existeFichero(char* nombreFic);
int main(int argc, char** argv){
    char* fichero = NULL;
    char display[21] = {'\0'};
    int pos = 0;
    if (argc != 2){
        printf("ERROR: Numero parametros insuficiente");
    }
    else if (!existeFichero(argv[1])){
        printf("ERROR: Fichero no existe");
    }
    else{
        fichero = cargarFichero(argv[1]);
        for (int i = 0; i < 21; i++){
            display[i] = fichero[i];
        }
        while (fichero[pos+21] != '\0'){
            printf("%s", display);
            sleep(1);
            system("clear");
            for (int i = 1; i < 21; i++){
                display[i-1] = display[i];
            }
            display[20] = fichero[pos+21];
            pos++;
        }
    }
}

char* cargarFichero(char* nombreFichero){
    FILE *f = NULL;
    char* linea=NULL;
    char c = '\0';
    int tamFic = 0;
    f = fopen(nombreFichero,"rb");
    while (!feof(f)){
        c = getc(f);
        linea = (char*)realloc(linea,tamFic+1);
        if (c == '\n'){
            c = ' ';
        }
        linea[tamFic++] = c;
    }
    if (tamFic > 0){
        linea[tamFic-1] = '\0';
    }
    else {
        linea[0] = '\0';
    }
    
    return linea;
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