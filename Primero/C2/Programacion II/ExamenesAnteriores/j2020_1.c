 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

int existeFichero(char* nombreFichero);
int tamFichero(char* nombreFichero);

 int main(int argc, char** argv){
    int existe = 0;
    int tam = 0;
    if (argc > 2){
        printf("ERROR: Demasiados parametros\n");
    }
    else if (argc < 2){
        printf("ERROR: No se ha pasado el nombre del fichero");
    }
    else{
        existe = existeFichero(argv[1]);
        if (!existe){
            printf("ERROR: Fichero no existe\n");
        }
        else{
            tam = tamFichero(argv[1]);
            printf("El tamaño del fichero es: %d bytes", tam);
        }
    }
    return 0;
 }

 int existeFichero(char* nombreFichero){
    int existe = 0;
    FILE* f = fopen(nombreFichero, "rb"); //Intento abrir el fichero
    if (f != NULL){ //Si el puntero al fichero no es nulo, existe
        existe = 1;
        fclose(f); //Cierro el fichero
    }
    return existe;
 }

 int tamFichero(char* nombreFichero){
    int size = 0;
    FILE *f = fopen(nombreFichero, "rb");
    fseek(f,0,SEEK_END);
    size = ftell(f);
    fclose(f);
    return size;
 }