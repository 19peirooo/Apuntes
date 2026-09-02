#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define H "<head>"
#define B "<body>"
#define CH "</head>"
#define CB "</body>"

int main (int argc, char **argv){
    const char *frase = "esto es una  prueba de strtok";
    char* prompt = NULL;
    char* copia = malloc(strlen(frase)+1);
    int numPalabras = 0;
    memcpy(copia,frase,sizeof(char)*(strlen(frase)+1));
    prompt = strtok(copia, " ");
    while(prompt != NULL){
        numPalabras++;
        prompt = strtok(NULL, " ");
        while (prompt && *prompt==' '){
            prompt = strtok(NULL, " ");
        }
    }
    printf("%s\n", frase);
    printf("%d palabras\n",numPalabras);
    free(copia);
    return 0;
}