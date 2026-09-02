#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum bool_e{V=1,F=0}bool_e;

typedef struct producto_t{
    char* nombre;
    float precio;
    int cantidad;
    int cantidadMin;
    int cantidadMax;
}producto_t;

typedef struct almacen_t{
    producto_t* prod;
    int tam;
}almacen_t;

almacen_t cargarFichero(char* nombreFic);
bool_e existeFichero(char* nombreFic);
char* leeLineaDFichero(FILE* f);
char* copiaCadena(char* original);
void comprobarStock(almacen_t a);
void imprimirResultado();

int main(int argc, char** argv){
    almacen_t almacen = {NULL,0};
    almacen = cargarFichero("almacen.txt");
    comprobarStock(almacen);
}

almacen_t cargarFichero(char* nombreFic){
    almacen_t a = {NULL,0};
    FILE* f = NULL;
    char* linea = NULL;
    char* token = NULL;
    if (!existeFichero(nombreFic)){
        printf("ERROR: Fichero no existe\n");
    }
    else{
        f = fopen(nombreFic,"rb");
        while(!feof(f)){
            linea = leeLineaDFichero(f);
            if (linea[0] != '\0'){
                a.prod = (producto_t*)realloc(a.prod, sizeof(producto_t)*(a.tam+1));
                token = strtok(linea,";");
                a.prod[a.tam].nombre = copiaCadena(token);
                token = strtok(NULL, ";");
                a.prod[a.tam].precio = atof(token);
                token = strtok(NULL, ";");
                a.prod[a.tam].cantidad = atoi(token);
                token = strtok(NULL, ";");
                a.prod[a.tam].cantidadMin = atoi(token);
                token = strtok(NULL, "\0");
                a.prod[a.tam].cantidadMax = atoi(token);
                a.tam++;
            }
        }
        fclose(f);
    }
    return a;
}

bool_e existeFichero(char* nombreFic){
    bool_e existe = F;
    FILE *f = fopen(nombreFic, "rb");
    if (f != NULL){
        existe = V;
        fclose(f);
    }
    return existe;
}

char* leeLineaDFichero(FILE* f){
    char* linea = NULL;
    int chars = 0;

    do{
        linea = (char*)realloc(linea,chars+1);
        linea[chars++] = getc(f);
    }while(linea[chars-1] != '\n' && (!feof(f)));
    if (chars > 0){
        linea[chars-1] = '\0';
    }
    else {
        linea[0] = '\0';
    }
    return linea;
}

char* copiaCadena(char* original){
    char* copia = malloc(strlen(original)+1);
    strcpy(copia,original);
    return copia;
}

void comprobarStock(almacen_t a){
    int stock = 0;
    FILE *f = fopen("compra.txt", "wb");
    for (int i = 0; i < a.tam; i++){
        if (a.prod[i].cantidad < a.prod[i].cantidadMin){
            stock = a.prod[i].cantidadMax - a.prod[i].cantidad;
            fprintf(f,"%s;%.2f;%d\n",a.prod[i].nombre,a.prod[i].precio,stock);
        }
    }
    fclose(f);
}