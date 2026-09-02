#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum bool_e{V=1,F=0}bool_e; 
typedef enum tipoProducto_e{
    hardware = 0,sofware = 1, otro = 2
}tipoProducto_e;
char* tiposProd[3] = {"hardware","software","otro"};

typedef struct producto_t{
    tipoProducto_e tipo;
    char* nombre;
    float precio;
    int cantidad;
}producto_t;

typedef struct lista_t{
    producto_t* prod;
    int tam;
}lista_t;

void mostrarAlmacen(lista_t l);
void introducirProductoEnLista(lista_t *l);
producto_t nuevoProducto(bool_e *entradaValida);
char* leeLineaDinamica();

int main(int argc, char** argv){
    bool_e menuAbierto = V;
    lista_t almacen = {NULL,0};
    int opcion = 0;
    while (menuAbierto){
        opcion = 0;
        printf("\n1. Nuevo Producto\n");
        printf("2. Mostrar Producto\n");
        printf("3. Salir\n");
        printf("Opción: ");
        scanf("%d", &opcion);
        while(getchar() != '\n');
        printf("\n");
        switch (opcion){
            case 1:{
                introducirProductoEnLista(&almacen);
            }break;
            case 2:{
                mostrarAlmacen(almacen);
            }break;
            case 3:{
                menuAbierto = F;
            }break;
            default:{
                printf("ERROR: Opcion Invalida\n");
            }break;
        }
    }
    for (int i = 0; i < almacen.tam; i++){
        free(almacen.prod[i].nombre);
    }
    free(almacen.prod);
    return 0;
}

void mostrarAlmacen(lista_t l){
    printf("Hay %d productos\n",l.tam);
    for (int i = 0; i < l.tam; i++){
        printf("\nProducto %d: \n", i+1);
        printf("Tipo: %s\n", tiposProd[l.prod[i].tipo]);
        printf("Nombre: %s\n", l.prod[i].nombre);
        printf("Precio: %.2f€\n", l.prod[i].precio);
        printf("Stock: %d\n",l.prod[i].cantidad);
    }
}

void introducirProductoEnLista(lista_t *l){
    bool_e entradaValida = F;
    producto_t p = nuevoProducto(&entradaValida);
    if (entradaValida){
        l->prod = (producto_t*)realloc(l->prod,sizeof(producto_t)*(l->tam+1));
        l->prod[l->tam++] = p;
    }
    else {
        free(p.nombre);
    }
}

producto_t nuevoProducto(bool_e *entradaValida){
    bool_e tipoValido = F;
    bool_e precioValido = F;
    bool_e cantidadValida = F;

    char* linea = NULL;
    char* token = NULL;
    char *error = NULL;
    producto_t p = {0,NULL,0,0};
    tipoValido = F;
    precioValido = F;
    cantidadValida = F;
    printf("Introduce los datos del producto separados por ;: ");
    linea = leeLineaDinamica();
    token = strtok(linea, ";");
    if (token != NULL){
        //Tipo
        for (int i = 0; i < 3; i++){
            if (strcmp(token,tiposProd[i]) == 0){
                tipoValido = V;
                p.tipo = i;
            }
        }
        if (tipoValido){
            token = strtok(NULL, ";");
            if (token != NULL){
                p.nombre = (char*)realloc(p.nombre,strlen(token)+1);
                strcpy(p.nombre,token);
                token = strtok(NULL,";");
                if (token != NULL){
                    p.precio = strtof(token,&error);
                    if (*error == '\0'){
                        precioValido = V;
                        token = strtok(NULL,"\0");
                        if (token != NULL){
                            p.cantidad = (int)strtol(token,&error,10);
                            if (*error == '\0'){
                                cantidadValida = V;
                            }
                            else{
                                printf("ERROR: Entrada para cantidad no numerica\n");
                            }
                        }
                        else {
                            printf("ERROR: Formato de entrada diferente al especificado\n");
                        }
                    }
                    else{
                        printf("ERROR: Entrada para precio no numerica\n");
                    }
                }
                else{
                    printf("ERROR: Formato de entrada diferente al especificado\n");
                }
            }
            else {
                printf("ERROR: Formato de entrada diferente al especificado\n");
            }    
        }
        else {
            printf("ERROR: Tipo No Valido\n");
        }   
    }
    else{
        printf("ERROR: Formato de entrada diferente al especificado\n");
    }
    if (cantidadValida && precioValido && tipoValido){
        *entradaValida = V;
    }
    return p;
}

char* leeLineaDinamica(){
    char* linea = NULL;
    int chars = 0;
    do{
        linea = (char*)realloc(linea,sizeof(char)*(chars+1));
        linea[chars++] = getchar();
    }while (linea[chars-1] != '\n');
    if (chars > 0){
        linea[chars-1] = '\0';
    }
    return linea;
}