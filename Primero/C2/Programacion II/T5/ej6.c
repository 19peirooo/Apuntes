#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct datos_t
{
    char *nombre;
    char *apellido;
    int edad;
}datos_t;

typedef struct lista_t
{
    union{
        datos_t *dato;
        char **linea;
    };
    int tam;
}lista_t;

char* copiaCadena(char* original);
datos_t parseaPersona(char *linea);
int cuentaComas(char *frase);
void leeFichero(char *nombreFichero, lista_t *lista);
void creaPersonas(lista_t lineas, lista_t *datos);
char *leeLineaDinamicaFichero(FILE *f);
void imprimePersonas(lista_t datos);
int main(int argc, char **argv){
    lista_t listaDatos = {NULL,0};
    lista_t listaLineas = {NULL,0};
    leeFichero(argv[1], &listaLineas);
    for (int i = 0; i < listaLineas.tam; i++){
        printf("%s\n", listaLineas.linea[i]);
    }
    creaPersonas(listaLineas,&listaDatos);
    imprimePersonas(listaDatos);
    for (int i = 0; i < listaDatos.tam; i++){
        free(listaDatos.dato[i].nombre);
        free(listaDatos.dato[i].apellido);
    }
    free(listaDatos.dato);
    return 0;
}

char *leeLineaDinamicaFichero(FILE *f){
    char *linea = NULL;
    int chars = 0;
    do{
        linea = (char*)realloc(linea,sizeof(char)*(chars+1));
        linea[chars++] = getc(f);           
    }while((linea[chars-1] != '\n') && (!feof(f)));
    if (chars > 0){
        linea[chars-1] = '\0';
    }
    return linea;
}

void leeFichero(char *nombreFichero, lista_t *lista){
    FILE *f = fopen(nombreFichero,"rb");
    char *linea=NULL;
    if (f != NULL){
        while (!feof(f)){
            lista->linea = (char**)realloc(lista->linea,sizeof(char*)*(lista->tam+1));
            lista->linea[lista->tam++] = leeLineaDinamicaFichero(f);
        }
        fclose(f);
    }
    else{
        printf("ERROR: No se ha podido abrir el fichero");
    }
}

int cuentaComas(char *frase){
    int numComas=0;
    char* token = frase;
    if (strlen(frase) >= 2){
        do{
            token = strstr(token+1,",");
            if (token != NULL){
                numComas++;
            }
        }while (token != NULL);    
    }
    return numComas;
}

datos_t parseaPersona(char *linea){
    datos_t p = {NULL,NULL,0};
    char *copia = NULL;
    char *token = NULL;
    char *error;

    copia = copiaCadena(linea);
    token = strtok(copia,",");
    p.nombre = copiaCadena(token);

    token = strtok(NULL, ",");
    p.apellido = copiaCadena(token);

    p.edad = (int)strtol(token,&error,10);
    if (*error != '\0'){
        printf("ERROR: Entrada no ese un numero\n");
    }
    
    free(copia);
    return p;
}
void creaPersonas(lista_t lineas, lista_t *datos){
    int numComas = 0;
    for (int i = 0; i < lineas.tam; i++){
        numComas = cuentaComas(lineas.linea[i]);
        if (numComas == 2){
            datos->dato = (datos_t*)realloc(datos->dato,sizeof(datos_t)*(datos->tam +1));
            datos->dato[datos->tam++] = parseaPersona(lineas.linea[i]);
        }
        else{
            printf("ERROR: Numeros de comas no es 2\n");
        }
    }
}

char* copiaCadena(char* original){
    char *copia;
    copia = (char*)realloc(copia,strlen(original)+1);
    memcpy(copia,original, strlen(original)+1);
    return copia;
}

void imprimePersonas(lista_t datos){
    for (int i = 0; i < datos.tam; i++){
        printf("Persona %d: \n",
            "Nombre: %s\n",
            "Apellido: %s\n",
            "Edad: %d",
            i+1,
            datos.dato[i].nombre,
            datos.dato[i].apellido,
            datos.dato[i].edad);
    }
}