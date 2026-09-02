#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
    FILE *f = fopen("ej1.txt","wb");
    if (f != NULL){
        for (char i = 'A'; i <= 'Z'; i++){
            fprintf(f,"%c %c\n", i, i+32);
        }
        fclose(f);
    } else {
        printf("ERROR: No se pudo abrir el fichero\n");
    }
    return 0;
}