//Ejercicio 1 - Analisis de Palabras
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum bool_e{V=1,F=0}bool_e;

typedef enum tipoLista_e{palabras,enteros}tipoLista_e;

//Lista generica --> Guarda Palabras y array de enteros
typedef struct lista_t{
    union{
        struct palabrasInfo_t* palabras;
        int* arrayInt;
    };
    tipoLista_e tipo;
    int tam;
}listaPalabras_t,lista_t;

//Estructura de las palabras a buscar. Guarda la palabra, su numero de ocurrencias y en que linea estan
typedef struct palabrasInfo_t{
    char* palabra;
    int numOcc;
    lista_t lineas;
}palabrasInfo_t;

char* leeLineaDFichero(FILE *f);
void insertarPalabrasEnLista(listaPalabras_t *lista, char* palabra);
bool_e existeFichero(char* nombreFichero);
void examinaLinea(char* linea, int numLinea, listaPalabras_t* lista);
char* crearFicheroSalida(char* nombreFicheroEntrada);
void guardarResultado(listaPalabras_t lista, char* nombreFicheroEntrada);

int main(int argc, char** argv){
    listaPalabras_t palabrasABuscar={.palabras=NULL,palabras,0};
    FILE *f=NULL;
    char* linea=NULL;
    int numLinea = 1;
    //Si no le paso el numero minimo(2) de parametros(el fichero y una palabra) --> ERROR
    if (argc < 3){
        fprintf(stderr,"ERROR: Numero de Parametros Insuficientes");
    }
    else {
        //Si el numero si es suficiente, compruebo si existe el fichero
        // Si existe --> Guardo palabra a buscar y inicializo sus paramentros
        if (!(existeFichero(argv[1]))){
            fprintf(stderr, "ERROR: Fichero no existe");
        }
        else {
            // tam es argc-2 ya que tengo que quitar el nombre del archivo y la ruta
            for (int i = 0; i < argc-2; i++){
                insertarPalabrasEnLista(&palabrasABuscar,argv[i+2]);
            }
            //Abro el fichero
            //Leo el fichero linea por linea y busco si aparecen las palabras
            f = fopen(argv[1],"rb");
            while (!feof(f)){
                linea = leeLineaDFichero(f);
                examinaLinea(linea,numLinea,&palabrasABuscar);
                numLinea++;
            }
            //Creo el nombre del fichero de salida
            //Guardo los resultado 
            guardarResultado(palabrasABuscar,argv[1]);

            

        }
    }

    //Libero memoria
    for(int i = 0; i < palabrasABuscar.tam; i++){
        free(palabrasABuscar.palabras[i].palabra);
        free(palabrasABuscar.palabras[i].lineas.arrayInt);
    }
    free(palabrasABuscar.palabras);
    free(linea);
    return 0;     
}

bool_e existeFichero(char* nombreFichero){
    bool_e existe = V;

    //Intento abrir el fichero
    FILE *f = fopen(nombreFichero, "rb");
    //Si no puedo abrirlo --> No existe
    if (f == NULL){
        existe = F;
    } else {
        //Si existe lo cierro
        fclose(f);
    }
    return existe;
}

char* leeLineaDFichero(FILE *f){
    char* linea=NULL;
    int chars=0;

    //Mientras que no se acabe la linea del fichero o no se acabe el fichero
    do{
        //Asigno memoria para el caracter y lo introduzco en la cadena
        linea = (char*)realloc(linea,sizeof(char)*(chars+1));
        linea[chars++] = getc(f);
    }while(linea[chars-1] != '\n' && (!feof(f)));
    
    if (chars > 0){
        linea[chars-1] = '\0';
    }
    //Devuelvo la cadena
    return linea;
}

void insertarPalabrasEnLista(listaPalabras_t *lista, char* p){
    //Asigno memoria para guardar la palabra
    lista->palabras = (palabrasInfo_t*)realloc(lista->palabras,sizeof(palabrasInfo_t)*(lista->tam + 1));
    //Asigno memoria para guardar la palabra
    lista->palabras[lista->tam].palabra = NULL;
    lista->palabras[lista->tam].palabra = (char*)realloc(lista->palabras[lista->tam].palabra, sizeof(char)*(strlen(p)+1)); 
    //Copio una cadena en otra
    strcpy(lista->palabras[lista->tam].palabra,p);
    lista->palabras[lista->tam].numOcc = 0;
    lista->palabras[lista->tam].lineas.arrayInt = NULL;
    lista->palabras[lista->tam].lineas.tam = 0;
    lista->tam++;
}

void examinaLinea(char* linea, int numLinea, listaPalabras_t* lista){
    char* copia = NULL;
    char* token = NULL;
    //Creo una copia de la linea
    copia = (char*)realloc(copia,strlen(linea)+1);
    strcpy(copia,linea);
    //Separo la linea por palabras y compara cada palabra con ellas a buscar
    token = strtok(copia," ");
    //Hasta que no lee toda la linea --> No encuentre mas espacios
    while (token != NULL){
        //Comparo palabra con las que busco
        //Si la encuentro --> 1 occurencia mas y apunto su linea
        if (token != NULL){
            for (int i = 0; i < lista->tam; i++){
                if (strcmp(token,lista->palabras[i].palabra) == 0){
                    lista->palabras[i].numOcc++;
                    //Asigno memoria para la linea
                    lista->palabras[i].lineas.arrayInt = (int*)realloc(lista->palabras[i].lineas.arrayInt,sizeof(int)*(lista->palabras[i].lineas.tam+1));
                    lista->palabras[i].lineas.arrayInt[lista->palabras[i].lineas.tam++] = numLinea;
                }
            }
        }
        token = strtok(NULL, " ");
    }
    //Libero la copia
    free(copia);
}

char* crearFicheroSalida(char* nombreFicheroEntrada){
    char* ficSalida = NULL;
    int posPunto = 0;
    const char* salida = ".out";
    //Encuentro la posicion del punto
    posPunto = strcspn(nombreFicheroEntrada, ".");
    //Copia la cadena del entrada en la de salida
    ficSalida = (char*)realloc(ficSalida, sizeof(char)*(strlen(nombreFicheroEntrada)+5)); //Reservo 5 mas para el \0 y el .out
    strcpy(ficSalida,nombreFicheroEntrada);
    //Sustitito el .txt por .out y añado el .txt al final
    for (int i = posPunto; i < strlen(ficSalida);i++){
        ficSalida[i] = salida[i-posPunto];
    }
    strcat(ficSalida, ".txt");
    return ficSalida;
}

void guardarResultado(listaPalabras_t lista, char* nombreFicheroEntrada){
    char* nombreficheroSalida = NULL;
    FILE *fOut = NULL; 
    nombreficheroSalida = crearFicheroSalida(nombreFicheroEntrada);
    fOut = fopen(nombreficheroSalida, "wb");
    for (int i = 0; i < lista.tam; i++){
        fprintf(fOut, "%s. Numero de Ocurrencias: %d. Lineas: ", lista.palabras[i].palabra, lista.palabras[i].numOcc);
        for (int j = 0; j < lista.palabras[i].lineas.tam; j++){
            fprintf(fOut, "%d ", lista.palabras[i].lineas.arrayInt[j]);
        }
        fprintf(fOut,"\n");
    }
    fclose(fOut);
}