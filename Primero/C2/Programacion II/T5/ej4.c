#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listaCadenas_t{
    char **cadenas;
    int numCadenas;
}listaCadenas_t;

void bubbleSort(listaCadenas_t *lista);

int main(int argc, char **argv){
    listaCadenas_t lista= {.cadenas=NULL, .numCadenas = 4};
    const char *frases[4] = {"La educacion ayuda a la persona a aprender a ser lo que es capaz de ser",
    "Dime y lo olvido, enseñame y lo recuerdo, involucrame y lo aprendo",
    "En cuestiones de cultura y de saber, solo se pierde lo que se guarda; solo se gana lo que se da",
    "Para viajar lejos no hay mejor nave que un libro"};
    int len=0;

    lista.cadenas = (char**)realloc(lista.cadenas,sizeof(char*)*lista.numCadenas);

    for (int i = 0; i < lista.numCadenas; i++){
        len = strlen(frases[i]);
        lista.cadenas[i] = (char*)realloc(lista.cadenas[i],sizeof(char)*(len+1));
        strcpy(lista.cadenas[i],frases[i]);
    }

    printf("Cadenas Desordenadas: \n");
    for (int i = 0; i < lista.numCadenas; i++){
        printf("Cadena %d: %s\n", i+1, lista.cadenas[i]);
    }
    bubbleSort(&lista);
    printf("Cadenas Ordenadas: \n");
    for (int i = 0; i < lista.numCadenas; i++){
        printf("Cadena %d: %s\n", i+1, lista.cadenas[i]);
    }

    for (int i = 0; i < lista.numCadenas; i++){
        free(lista.cadenas[i]);
    }
    free(lista.cadenas);
    return 0;
}

void bubbleSort(listaCadenas_t *lista){
    char *temp = NULL;
    for (int i = 0; i < lista->numCadenas; i++){
        for (int j = i+1; j < lista->numCadenas; j++){
            if (strcmp(lista->cadenas[i],lista->cadenas[j]) > 0){
                temp = lista->cadenas[i];
                lista->cadenas[i] = lista->cadenas[j];
                lista->cadenas[j] = temp;
            }
        }
    }
}