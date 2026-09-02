#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cuentaLetras(char* linea, int* numConstantes, int* numVocales, int* numDigitos);

int main(int argc, char** argv){
    int vocales = 0;
    int consontantes = 0;
    int digitos = 0;
    char* cadena = "Hola123";
    cuentaLetras(cadena,&consontantes,&vocales,&digitos);
    printf("Vocales: %d\nConsonantes: %d\nDigitos: %d\n", vocales, consontantes, digitos);
    return 0;
}

void cuentaLetras(char* linea, int* numConstantes, int* numVocales, int* numDigitos){
    char* copia = NULL;
    const char* vocales= "aeiou";
    const char* digitos = "0123456789";
    const char* consonantes = "bcdfghjklmnñpqrstvwxyz";
    char* next = NULL;
    int index = 0;
    int lenLine = strlen(linea);
    //Copio cadena
    copia = (char*)realloc(copia,strlen(linea)+1);
    //Paso mayusculas a minusculas
    for (int i = 0; i < strlen(linea)+1; i++){
        if (linea[i] >= 'A' && linea[i] <= 'Z'){
            copia[i] = linea[i]+32;
        }
        else{
            copia[i] = linea[i];
        }
    }

    index = 0;
    next = copia;
    lenLine = strlen(linea);
    while (index < lenLine){
        index = strcspn(next,consonantes);
        if(index < lenLine){
            (*numConstantes)++;
        }
        next+=index+1;
        lenLine-=(index+1);
        index = 0;
    }

    index = 0;
    next = copia;
    lenLine = strlen(linea);
    while (index < lenLine){
        index = strcspn(next,vocales);
        if(index < lenLine){
            (*numVocales)++;
        }
        next+=index+1;
        lenLine-=(index+1);
        index = 0;
    }
    
    index = 0;
    next = copia;
    lenLine = strlen(linea);
    while (index < lenLine){
        index = strcspn(next,digitos);
        if(index < lenLine){
            (*numDigitos)++;
        }
        next+=index+1;
        lenLine-=(index+1);
        index = 0;
    }
}