#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estructura que guarda todos valores de x e y. Tambien el numero de puntos que tenemos para esa funcion
typedef struct funcion_t{              
    double* x;                 
    double* y;                
    int numPuntosIntroducidos;  
} funcion_t;

//Funcion que copia una cadena en otra
char* copiarCadena(const char* original) {
    //Asigna memoria para la copia
    char* copia = (char*)malloc(strlen(original) + 1);
    if (copia) {
        strcpy(copia, original); //Copia la cadena
    }
    return copia;
}

//Lee una linea de un fichero y la guarda
char* leeLineaDFichero(FILE* f) {
    char c = 0;
    int tam = 0;
    char* l = NULL;

    //Lee letra por letra hasta leer un /n o el final del fichero
    while ((c = getc(f)) != EOF && c != '\n') {
        l = (char*)realloc(l, sizeof(char) * (tam + 1)); //Asigna memoria para el caracter
        l[tam++] = c; //Lo añade a la cadena
    }

    //Comprueba si la cadena es vacia
    if (tam == 0 && c == EOF) {
        free(l);
        return NULL;
    }

    //Añade el \0
    l = (char*)realloc(l, sizeof(char) * (tam + 1));
    l[tam] = '\0';

    /*Esta parte sirve para corregir un error. El salto de linea en windows a veces se interpreta como \r 
    Con esto nos aseguramos que el salto de linea sea \n*/
    if (l[tam-1] == '\r'){
        l[tam-1] = '\n';
    }
    return l;
}

//Recibe una cadena con las coordenadas x e y. Salen ambas coordenadas dentro del string
void parseaLinea(char* linea, funcion_t* datos) {

    char* token = strtok(linea, "\t"); //Lee la coordenada x
    //Asigna memoria para la nueva coordenada
    datos->x = (double*)realloc(datos->x,sizeof(double)*(datos->numPuntosIntroducidos+1));
    datos->y = (double*)realloc(datos->y,sizeof(double)*(datos->numPuntosIntroducidos+1));

    //Si lee algo, añade la coordenada x a la función
    if (token != NULL) {
        datos->x[datos->numPuntosIntroducidos] = strtod(token, NULL); //strtod --> Pasa de cadena a double
    }

    token = strtok(NULL, "\n") ; //Lee la coordenada y
    //Si la lee, añade la coordenada y a la función
    if (token != NULL) {
        datos->y[datos->numPuntosIntroducidos] = strtod(token, NULL); 
    }
    //Incrementa el numero de puntos introducidos
    datos->numPuntosIntroducidos++;
}

//Funcion encargada de rellanar todos los puntos
funcion_t rellenaPuntos(char* fName){

    FILE* f = fopen(fName, "rb"); //Abre el fichero con los puntos
    funcion_t f_x = {NULL, NULL, 0};  

    char* ficheroLineas;

    //Lee el fichero linea a linea y agrega sus coordenadas
    while ((ficheroLineas = leeLineaDFichero(f)) != NULL) {
        parseaLinea(ficheroLineas, &f_x);
        free(ficheroLineas);  
    }

    fclose(f); //Cierra el fichero
    return f_x; //Devuelve la funcion con todos sus puntos
}
