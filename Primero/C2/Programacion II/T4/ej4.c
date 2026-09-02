#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum bool_e{V=1,F=0}bool_e;

typedef enum tipoLista_e{contacto,integer}tipoLista_e;

typedef struct lista_t{
    union{
        struct usuario_t* usuario;
        int* arrayInt;
    };
    tipoLista_e tipo;
    int tam;
}lista_t,agenda_t;

typedef struct usuario_t{
    char* nombre;
    char* apellido;
    lista_t telefono;
}usuario_t;

agenda_t cargarFichero(char* nombreFichero);
void introducirContactoEnLista(agenda_t *agenda);
usuario_t nuevoContacto();
char* leelineaFichero(FILE *f);
lista_t leeNumerosFichero(FILE *f);
void mostrarAgenda(agenda_t agenda);
void mostrarContacto(usuario_t u);
void salvarFichero(char* nombreFichero, agenda_t agenda);

int main(int argc, char **argv){
    bool_e menuAbierto = V;
    agenda_t agenda=cargarFichero("agenda.txt");
    usuario_t usuario={NULL,NULL,NULL};
    int opcion=0;

    while (menuAbierto){
        printf("\t----------------------------------------\n");
        printf("\t1. Introducir Nuevo Contacto\n");
        printf("\t2. Mostrar Contactos\n");
        printf("\t3. Salir\n");
        printf("\t----------------------------------------\n");
        printf("Opcion: ");
        scanf("%d", &opcion);
        while(getchar() != '\n');
        switch(opcion){
            case 1:{
                introducirContactoEnLista(&agenda);
            }break;
            case 2:{
                mostrarAgenda(agenda);
            }break;
            case 3:{
                printf("Saliendo del programa...\n");
                menuAbierto = F;
                salvarFichero("agenda.txt",agenda);
            }break;
            default:{
                printf("ERROR: Opcion Incorrecta\n");
            }break;
        }
    }
    for (int i = 0; i < agenda.tam; i++){
        free(agenda.usuario[i].nombre);
        free(agenda.usuario[i].apellido);
        free(agenda.usuario[i].telefono.arrayInt);
    }
    free(agenda.usuario);
    return 0;
}

agenda_t cargarFichero(char* nombreFichero){
    FILE *f = fopen(nombreFichero,"rb");
    agenda_t agenda = {NULL,contacto,0};

    if (f == NULL){
        printf("ERROR: No se pudo cargar la agenda\n");
    } else {
        while(!feof(f)){
            agenda.usuario = (usuario_t*)realloc(agenda.usuario, sizeof(usuario_t)*(agenda.tam+1));
            agenda.usuario[agenda.tam].nombre = leelineaFichero(f);
            agenda.usuario[agenda.tam].apellido = leelineaFichero(f);
            agenda.usuario[agenda.tam].telefono= leeNumerosFichero(f);
            agenda.tam++;
        };
        fclose(f);
        agenda.tam--;
    }
    return agenda;
}

void introducirContactoEnLista(agenda_t *agenda){
    agenda->usuario = (usuario_t*)realloc(agenda->usuario,sizeof(usuario_t)*(agenda->tam+1));
    agenda->usuario[agenda->tam++] = nuevoContacto();
}

usuario_t nuevoContacto(){
    usuario_t u={NULL,NULL,NULL};
    printf("Introduce el nombre del Contacto: ");
    u.nombre = leelineaFichero(stdin);
    printf("Introduce el/los apellidos del Contacto: ");
    u.apellido = leelineaFichero(stdin);
    printf("Introduce el telefono del Contacto: ");
    u.telefono = leeNumerosFichero(stdin);
    return u;
}
char* leelineaFichero(FILE *f){
    char *linea=NULL;
    int chars=0;
    do{
        linea = (char*)realloc(linea,sizeof(char)*chars+1);
        linea[chars++] = getc(f);
    }while(linea[chars-1] != '\n' && (!(feof(f))));
    if (chars > 0){
        linea[chars-1] = '\0';
    }
    return linea;
}

lista_t leeNumerosFichero(FILE *f){
    int* nums=NULL;
    int tam = 0;
    int n;
    lista_t array = {NULL,integer,0};
    do{
        n = getc(f);
        if (n != EOF && (n <= '9' && n >= '0')){
            n -= '0';
            nums = (int*)realloc(nums,sizeof(int)*(tam+1));
            nums[tam++] = n;
        }
    }while(n != '\n' && (!feof(f)));
    array.arrayInt = nums;
    array.tam = tam;
    return array;
}

void mostrarAgenda(agenda_t agenda){
    for (int i = 0; i < agenda.tam; i++){
        printf("-------Contacto %d-------\n",i+1);
        mostrarContacto(agenda.usuario[i]);
        printf("\n");
    }
}

void mostrarContacto(usuario_t u){
    printf("Nombre: %s\n", u.nombre);
    printf("Apellido: %s\n", u.apellido);
    printf("Telefono: ");
    for (int i = 0; i < u.telefono.tam; i++){
        printf("%d",u.telefono.arrayInt[i]);
    }
}

void salvarFichero(char* nombreFichero, agenda_t agenda){
    FILE *f = fopen(nombreFichero, "wb");

    if (f == NULL){
        printf("ERROR: No se pudo guardar la agenda");
    } else {
        for (int i = 0; i < agenda.tam; i++){
            fwrite(agenda.usuario[i].nombre,1,strlen(agenda.usuario[i].nombre),f);
            fwrite("\n",1,1,f);
            fwrite(agenda.usuario[i].apellido,1,strlen(agenda.usuario[i].apellido),f);
            fwrite("\n",1,1,f);
            for (int j = 0; j < agenda.usuario[i].telefono.tam; j++){
                fwrite(&agenda.usuario[i].telefono.arrayInt[j],sizeof(int),1,f);
            }
            fwrite("\n",1,1,f);
        }
        fclose(f);
    }
}