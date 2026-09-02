#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum bool_e{V=1,F=0}bool_e;

typedef struct string_t{
    char* cadena;
    int tamCadena;
}string_t;

typedef struct socio_t{
    string_t dni;
    string_t fecha;
}socio_t;

typedef struct listaSocios_t{
    socio_t* socio;
    int numSocios;
}listaSocios_t;

void introducirSocioEnLista(listaSocios_t* lista);
string_t leeLineaDinamica();
socio_t nuevoSocio();
void imprimirListaSocios(listaSocios_t lista);
bool_e validarFecha(string_t fecha);
bool_e validarDNI(string_t dni);

int main(int argc, char **argv){
    listaSocios_t socios={NULL,0};
    bool_e menuAbierto = V;
    int opcion = 0;

    while (menuAbierto){
        opcion = 0;
        printf("---------------------------------------\n");
        printf("\t1. Nuevo Socio\n");
        printf("\t2. Mostrar Lista Socios\n");
        printf("\t3. Salir\n");
        printf("---------------------------------------\n");
        printf("Opcion: ");
        scanf("%d", &opcion);
        while(getchar()!= '\n'); //Limpio Buffer
        switch (opcion){
            case 1:{
                introducirSocioEnLista(&socios);
            }break;
            case 2:{
                imprimirListaSocios(socios);
            }break;
            case 3:{
                menuAbierto = F;
            }break;
            default:{
                printf("ERROR: Opcion Incorrecta\n");
            }break;
        }
    }
    for (int i = 0; i < socios.numSocios; i++){
        free(socios.socio[i].fecha.cadena);
        free(socios.socio[i].dni.cadena);
    }
    free(socios.socio);
    return 0;
}

void introducirSocioEnLista(listaSocios_t* lista){
    lista->socio = (socio_t*)realloc(lista->socio, sizeof(socio_t)*(lista->numSocios+1));
    lista->socio[lista->numSocios++] = nuevoSocio();
}

socio_t nuevoSocio(){
    socio_t s;
    bool_e fechaValida = F;
    bool_e dniValido = F;
    s.dni.cadena = NULL;
    s.dni.tamCadena = 0;
    s.fecha.cadena = NULL;
    s.fecha.tamCadena = 0;
    while (!fechaValida){
        printf("Introduce la fecha de ingreso en formato (dd/mm/aaaa): ");
        s.fecha = leeLineaDinamica();
        fechaValida = validarFecha(s.fecha);
        if (!fechaValida){
            printf("ERROR: Fecha no valida\n");
        }
    }
    while (!dniValido){
        printf("Introduce el DNI del Socio: ");
        s.dni = leeLineaDinamica();
        dniValido = validarDNI(s.dni);
        if (!dniValido){
            printf("ERROR: DNI no valido\n");
        }
    }
    return s;
}

string_t leeLineaDinamica(){
    string_t linea = {NULL,0};
    do{
        linea.cadena = (char*)realloc(linea.cadena, linea.tamCadena+1);
        linea.cadena[linea.tamCadena++] = getchar();
    }while(linea.cadena[linea.tamCadena-1] != '\n');
    linea.cadena[linea.tamCadena -1] = '\0';
    return linea;
}

void imprimirListaSocios(listaSocios_t lista){
    for (int i = 0; i < lista.numSocios; i++){
        printf("\n--------Socio %d--------\n", i+1);
        printf("Fecha de Ingreso: %s. DNI: %s\n", lista.socio[i].fecha.cadena, lista.socio[i].fecha.cadena);
        printf("------------------------\n");
    }
    printf("\n");
}

bool_e validarFecha(string_t fecha){
    bool_e valido = V;
    char* copia = NULL;
    char* token = NULL;
    int num = 0;
    char *error = NULL;
    if (fecha.tamCadena != 11){
        valido = F;
    }
    else{
        copia = (char*)realloc(copia,fecha.tamCadena);
        strcpy(copia,fecha.cadena);
        token = strtok(copia,"/");
        if (token != NULL){
            num = (int)strtol(token,&error,10);
            if (*error != '\0'){
                valido = F;
            }
            else if (num > 31 && num < 1){
                valido = F;
            }
            else{
                token = strtok(NULL,"/");
                if (token != NULL){
                    num = (int)strtol(token,&error,10);
                    if (*error != '\0'){
                        valido = F;
                    }
                     else if (num > 12 && num < 1){
                        valido = F;
                    }
                    else{
                        token = strtok(NULL,"\0");
                        if (token != NULL){
                            num = (int)strtol(token,&error,10);
                            if (*error != '\0'){
                                valido = F;
                            }
                        }
                        else{
                            valido = F;
                        }

                    }
                }
                else{
                    valido = F;
                }
            }
        }else{
            valido = F;
        }

    }
    free(copia);
    return valido;
}

bool_e validarDNI(string_t dni){
    bool_e valido = V;
    if (dni.tamCadena != 10){
        valido = F;
    }
    else if (dni.cadena[9] < 'A' && dni.cadena[9] > 'Z'){
        valido = F;
    }
    return valido;
}