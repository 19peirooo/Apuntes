#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum bool_e{V=1,F=0}bool_e;

typedef struct producto_t{
    char* nombre;
    char* id;
    int cantidad;
}producto_t;

typedef struct almacen_t{
    producto_t* prod;
    int tam;
}almacen_t;

void imprimirEstado(almacen_t a);
void añadirProducto(almacen_t* a);
char* leeLineaDinamica();
bool_e validarID(char* id);
char* copiaCadena(char* original);
void retirarProducto(almacen_t *a);

int main(int argc, char** argv){
    bool_e menuAbierto = V;
    int opcion = 0;
    almacen_t almacen = {NULL,0};
    while (menuAbierto){
        opcion = 0;
        printf("\n1. Introducir Producto\n");
        printf("2. Sacar Producto\n");
        printf("3. Mostrar Estado Almacen\n");
        printf("4. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);
        while(getchar() != '\n');
        printf("\n");
        switch (opcion){
            case 1:{
                añadirProducto(&almacen);
            }break;
            case 2:{
                if (almacen.tam == 0){
                    printf("ERROR: No se ha introducido ningun producto aun\n");
                }
                else {
                    retirarProducto(&almacen);
                }
            }break;
            case 3:{
                imprimirEstado(almacen);
            }break;
            case 4:{
                menuAbierto = F;
            }break;
            default:{
                printf("ERROR: Opcion no valida\n");
            }break;
        }
    }
    for (int i = 0; i < almacen.tam; i++){
        free(almacen.prod[i].nombre);
        free(almacen.prod[i].id);
    }
    free(almacen.prod);
    return 0;
}

void imprimirEstado(almacen_t a){
    for (int i = 0; i < a.tam; i++){
        printf("Producto %d:\n", i+1);
        printf("Nombre: %s\n",a.prod[i].nombre);
        printf("ID: %s\n", a.prod[i].id);
        printf("Cantidad: %d\n", a.prod[i].cantidad);
        printf("\n");
    }
}

char* leeLineaDinamica(){
    char* linea = NULL;
    int chars = 0;

    do {
        linea = (char*)realloc(linea, chars+1);
        linea[chars++] = getchar();
    }while (linea[chars-1] != '\n');
    linea[chars-1] = '\0';
    return linea;
}

void añadirProducto(almacen_t *a){
    producto_t p = {NULL,NULL,0};
    bool_e nombreValido = V;
    bool_e idValido = V;
    int idCoincidente = 0;
    bool_e encontrado = F;
    a->prod = (producto_t*)realloc(a->prod, sizeof(producto_t)*(a->tam+1));
    do{
        printf("Introduce el nombre (max 15 chars): ");
        p.nombre = leeLineaDinamica();
        if (strlen(p.nombre) > 16){
            nombreValido = F;
            printf("ERROR: Nombre demasiado largo\n");
        }
        else if (p.nombre == NULL){
            nombreValido = F;
            printf("ERROR: No se ha introducido nada\n");
        }
        else {
            nombreValido = V;
        }
    }while (!nombreValido);
    do{
        printf("Introduce el ID del Producto: ");
        p.id = leeLineaDinamica();
        idValido = validarID(p.id);
    }while(!idValido);
    printf("Introduce la cantidad de stock a añadir: ");
    scanf("%d", &p.cantidad);
    while(getchar() != '\n');

    for (int i = 0; i < a->tam; i++){
        if (strcmp(p.id,a->prod[i].id) == 0){
            idCoincidente = i;
            encontrado = V;
        }
    }
    if (encontrado){
        a->prod[idCoincidente].cantidad += p.cantidad;
        printf("ERROR: ID ya introducido. Se añadira la cantidad al stock\n");
    }
    else {
        a->prod[a->tam].nombre = copiaCadena(p.nombre);
        a->prod[a->tam].id = copiaCadena(p.id);
        a->prod[a->tam].cantidad = p.cantidad; 
        a->tam++;
    }
    free(p.nombre);
    free(p.id);
}

bool_e validarID(char* id){
    bool_e idValido = V;
    int numID = 0;
    char *error = NULL;
    numID = (int)strtol(id,&error,10);
    if (strlen(id) != 5){
        printf("ERROR: Id no tiene 5 cifras\n");
        idValido = F;
    }
    else{
        if (*error != '\0'){
            idValido = F;
            printf("ERROR: Entrada no numerica\n");
        }
        else if (numID > 99999){
            idValido = F;
            printf("ERROR: ID tiene mas de 5 cifras\n");
        }
    }
    
    return idValido;
}

char* copiaCadena(char* original){
    char* copia = malloc(strlen(original+1));
    strcpy(copia,original);
    return copia;
}

void retirarProducto(almacen_t *a){
    char* id = NULL;
    int producto = 0;
    int cantidad = 0;
    bool_e productoEncotrado = F;
    do {
        printf("ID del Producto a retirar: ");
        id = leeLineaDinamica();
        for (int i = 0; i < a->tam; i++){
            if (strcmp(id,a->prod[i].id)==0){
                productoEncotrado = V;
                producto = i;
            }
        }
        if (!productoEncotrado){
            printf("ERROR: Producto no encontrado\n");
        }
    }while(!productoEncotrado);
    printf("Cuanto stock deseas retirar: ");
    scanf("%d", &cantidad);
    while(getchar() != '\n');
    a->prod[producto].cantidad -= cantidad;
    if (a->prod[producto].cantidad < 0){
        a->prod[producto].cantidad = 0;
    }
}