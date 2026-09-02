#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
    //cuenta letras leidas
    int letrasLeidas=0;
    int vocales = 0;
    char c = '\0';
    while ((c = getc(stdin)) != '\n'){
        //Tratar cadena caracter a caracter
        putc(c,stdout);
        if (c == 'A' || c == 'a' || c == 'E' || c == 'e' || c == 'I' || c == 'i' || c == 'O' || c == 'o' || c == 'U' || c == 'u'){
            vocales++;
        }
        letrasLeidas++;
    }
    putc('\n',stdout);
    fprintf(stdout,"Letras Leidas: %d\n", letrasLeidas);
    fprintf(stdout,"Vocales Leidas: %d", vocales);
    return 0;
}