#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *dameFrase();

int main(int argc, char **argv){
    char *dato = dameFrase();
    printf("%s\n",dato);
    free(dato);
    return 0;
}

/* Esto es erroneo ya que "hola mundo" es un array estatico y dato es un array dinamico
const char *dameFrase(){
    return "hola mundo";
}*/

//Funcion corregida
char *dameFrase(){
    char *frase = NULL; //Frase dinamica
    const char *holaMundo = "hola mundo"; //Frase Estatica 
    frase = (char*)realloc(frase,strlen(holaMundo)+1);
    strcpy(frase,holaMundo);
    return frase;
}