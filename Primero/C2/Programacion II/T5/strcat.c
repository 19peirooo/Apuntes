#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv){
    const char *frase1 = "hola ";
    const char *frase2 = "mundo";
    char *concat = NULL;

    concat = (char*)realloc(concat,strlen(frase1)+strlen(frase2)+1);
    strcat(concat,frase1); //strcat(destino,origen) --> Concatena cadenas
    strcat(concat,frase2);
    printf("%s\n",concat);
    free (concat);
    return 0;
}