#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum bool_e{V=1,F=0}bool_e;
bool_e existeFichero(char* nombreFichero);
char* leeLineaDFichero(FILE* f);
char* concatenaCadenas(char* c1, char* c2);
void separarLinea(char* linea, int maxChars);
void desplazarLineaDer(char* linea,int posInicial,int posFinal, int numChars);
char* copiaCadena(char* original);

int main(int argc, char** argv){
    bool_e entradaCorrecta = F;
    char *error = NULL;
    char* cadena = NULL;
    char* ficheroLinea = NULL;
    int numCaracteres=0;
    int tamFichero  = 0;
    FILE* fIn = NULL;
    FILE* fOut = NULL;

    //Compruebo que el usuario haya introducido los paramentros necesarios
    //Si argc no es 4 --> ERROR
    if (argc != 4){
        printf("ERROR: Numero de parametros incorrectos");
    } else{
        //Si lo es --> Compruebo que el primer fichero existente y que el tercer parametro es un numero
        //Si no existe el fichero --> ERROR
        if (!(existeFichero(argv[1]))){
            printf("ERROR: Fichero de entrada no existe");
        } else {
            //Si existe --> Compruebo numero
            numCaracteres = (int)strtol(argv[3],&error,10);
            //Si es un numero --> Paso al programa normal
            if (*error == '\0'){
                entradaCorrecta = V;    
            }
            else{
                printf("ERROR: Tercer parametro no es un numero");
            }
        }
    }

    if (entradaCorrecta){
        //Abro el fichero de entrada en modo lectura y el de salida en modo escritura
        fIn = fopen(argv[1], "rb");
        fOut = fopen(argv[2], "wb");
        //Mientras que no llegue al final del fichero
        while (!feof(fIn)){
            //Leo linea dek fichero
            cadena = leeLineaDFichero(fIn);
            //Concateno cadena
            ficheroLinea=concatenaCadenas(ficheroLinea,cadena);
            free(cadena);
        }
        separarLinea(ficheroLinea,numCaracteres);
        fprintf(fOut,"%s",ficheroLinea);
        fclose(fIn);
        fclose(fOut);
    }
    free(ficheroLinea);
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

char* concatenaCadenas(char* c1, char* c2){
    //Reservo memoria
    if (c1 == NULL){
        c1 = copiaCadena(c2); 
    } else {
        c1 = (char*)realloc(c1,strlen(c1)+strlen(c2)+2);
        strcat(c1, " ");
        //Concateno
        strcat(c1,c2);
    }
    return c1;
}

void separarLinea(char* linea, int maxChars){ //Falta concatenar linea con la anterior --> Hacer en main
    int i = 0, j = 0;
    char c = '\0';
    //Mientras que no hay llegado al fin de linea
    while (i < strlen(linea)){
        //Si llego al numero de caracteres maximo
        if (j == maxChars){
            //Si el caracter es un espacio o un salto de linea
            if (linea[i] == ' ' || linea[i] == '\n'){
                //Sustituyo el espacio por \n
                linea[i] = '\n';
            }
            //Si es cualquier otra cosa
            else{
                //Si el caracter anterior es no es un espacio o un salto de linea , el espacio es un salto de linea
                if (linea[i-1] != ' ' && linea[i-1] != '\n'){
                    //Sustituyo el caracter por un - y me guardo que caracter es
                    c = linea[i];
                    linea[i] = '-';
                    //Hayo hueco para el salto de linea y el caracter que tenia antes
                    desplazarLineaDer(linea,i,strlen(linea),2);
                    //Los pongo
                    linea[++i] = '\n';
                    linea[i+1] = c;
                }
                else {
                   //Sustituyo el caracter por un \n y me guardo que caracter es 
                   c = linea[i];
                   linea[i] = '\n';
                   //Hayo hueco para el caracter que tenia antes
                   desplazarLineaDer(linea,i,strlen(linea),1);
                   //Lo pongo
                   linea[i+1] = c;
                }
            }
        }
        i++;
        if (j == maxChars){
            j = 0;
        } else {
            j++;
        }
    }
}

void desplazarLineaDer(char* linea,int posInicial,int posFinal, int numChars){
    linea = (char*)realloc(linea,strlen(linea)+numChars+1);
    for (int i = posFinal; i > posInicial; i--){
        linea[i+numChars] = linea[i];
        linea[i] = ' ';
    }
}
char* copiaCadena(char* original){
    char *copia=NULL;
    copia = (char*)realloc(copia,strlen(original)+1);
    strcpy(copia,original);
    return copia;
}