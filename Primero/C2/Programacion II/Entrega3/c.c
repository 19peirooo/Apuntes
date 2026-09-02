#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum bool_e{V=1,F=0}bool_e;

typedef enum estado_e{
    guardado=0,no_guardado=1
}estado_e;

char* tiposEstado[2] = {"Guardado", "Sin Guardar"}; //Array de definicion de la estructura estado 

typedef struct alumno_t{
    char* nombre;
    char* apellido;
    int edad;
    estado_e estado;
}alumno_t;

typedef struct listaAlumnos_t{
    alumno_t* alumno;
    int tam;
}listaAlumnos_t;

bool_e existeFichero(char* nombreFichero);
listaAlumnos_t cargarFichero(char* nombreFichero);
char* leeLineaDFichero(FILE *f);
char* copiaCadena(char* original);
void imprimirAlumnos(listaAlumnos_t lista);
void mostrarAlumno(alumno_t alumno);
alumno_t nuevoAlumno();
void introducirAlumnoEnLista(listaAlumnos_t* lista);
void guardarAlumnosEnFichero(listaAlumnos_t lista, char* nombreFichero);
listaAlumnos_t buscarAlumnoEnLista(char* linea, listaAlumnos_t lista);

int main(int argc, char** argv){
    FILE *f = NULL;
    listaAlumnos_t alumnos={NULL,0};
    listaAlumnos_t coincidencias = {NULL,0};
    bool_e menuAbierto = V;
    int opcion =0;
    char* linea = NULL;
    //Comprueba si existe el fichero --> Si no existe, lo creo 
    if (!(existeFichero("alumnos.txt"))){
        f = fopen("alumnos.txt","wb");
        fclose(f);
    }
    //Cargo el fichero
    alumnos = cargarFichero("alumnos.txt");
    
    //Menu
    while (menuAbierto){
        //Imprimo menu
        printf("----------------------------------\n");
        printf("\t1. Listar Alumnos\n");
        printf("\t2. Nuevo Alumno\n");
        printf("\t3. Guardar Alumnos\n");
        printf("\t4. Buscar Alumnos\n");
        printf("\t5. Salir\n");
        printf("----------------------------------\n");
        //Pido al usuario un opcion
        printf("Opcion: ");
        scanf("%d", &opcion);
        while (getchar() != '\n'); //Limpio Buffer
        //Analizo opcion del usuario
        switch(opcion){
            //Si 1 --> Imprimir Lista
            case 1:{
                if (alumnos.tam == 0){
                    fprintf(stderr,"ERROR: No hay alumnos aun --> Crea alumnos antes\n");
                }
                else {
                    imprimirAlumnos(alumnos);
                }
            }break;
            //Si 2 --> Creo un nuevo alumno y lo guardo en la lista
            case 2:{
                introducirAlumnoEnLista(&alumnos);
            }break;
            //Si 3 --> Actualizo el fichero
            case 3:{
                guardarAlumnosEnFichero(alumnos,"alumnos.txt");
            }break;
            //Si 4 --> Pido linea a usuario y busco por nombre y apellido
            case 4:{
                //Pido linea
                printf("Introduce el nombre o apellidos de los alumnos que quieras buscar: ");
                linea = leeLineaDFichero(stdin);
                //Guardo las coincidencia en otra lista de alumnos
                coincidencias = buscarAlumnoEnLista(linea,alumnos);
                //Imprimo los alumnos que cumplen el criterio
                imprimirAlumnos(coincidencias);
            }break;
            //Si 5 --> Salir del Programa y Guardo el fichero
            case 5:{
                printf("Saliendo del Programa...");
                menuAbierto = F;
                guardarAlumnosEnFichero(alumnos,"alumnos.txt");
            }break;
            //Cualquier otra cosa --> ERROR
            default:{
                fprintf(stderr,"ERROR: Entrada incorrecta\n");
            }break;
        }
        

    }
    //Libero memoria
    //Por cada alumno
    for (int i = 0; i < alumnos.tam; i++){
        //Libero nombre y apellido
        free(alumnos.alumno[i].nombre);
        free(alumnos.alumno[i].apellido);
    }
    //Por cada alumno en la lista de coincidencias
    for (int i = 0; i < coincidencias.tam; i++){
        //Libero nombre y apellido
        free(coincidencias.alumno[i].nombre);
        free(coincidencias.alumno[i].apellido);
    }
    //Libero ambas listas enteras
    free(alumnos.alumno);
    free(coincidencias.alumno);
    return 0;
}

bool_e existeFichero(char* nombreFichero){
    bool_e existe = V;
    //Intento abrir el fichero
    FILE *f = fopen(nombreFichero,"rb");
    //Si no puedo --> No existe
    if (f == NULL){
        existe = F;
    }
    return existe;
}

listaAlumnos_t cargarFichero(char* nombreFichero){
    listaAlumnos_t lista={.alumno = NULL,0};
    char* linea=NULL;
    char* token = NULL;

    //Abro fichero
    FILE *f = fopen(nombreFichero, "rb");
    //Mientras que no se haya leido todo el fichero
    while (!feof(f)){
        //Leo linea
        linea = leeLineaDFichero(f);
        if (strcmp(linea,"\0") != 0){
            //Reservo memoria para cada usuario
            lista.alumno = (alumno_t*)realloc(lista.alumno,sizeof(alumno_t)*(lista.tam+ 1));
            //Busco un espacio --> Busco una coma y guardo el nombre
            token = strtok(linea," ");
            token = strtok(NULL,",");
            lista.alumno[lista.tam].nombre = copiaCadena(token);
            //Hago lo mismo con el apellido y con la edad busco el \n en vez de la coma
            token = strtok(NULL," ");
            token = strtok(NULL,",");
            //Guardo el apellido
            lista.alumno[lista.tam].apellido = copiaCadena(token);
            token = strtok(NULL," ");
            token = strtok(NULL,"\n");
            lista.alumno[lista.tam].edad = (int)strtol(token,NULL,10);
            //Estado = guardado
            lista.alumno[lista.tam].estado = guardado;
            lista.tam++;
        }
    }
    fclose(f);
    //Devuelvo lista
    return lista;
}

char* leeLineaDFichero(FILE *f){
    char* linea = NULL;
    int chars=0;

    do{
        linea = (char*)realloc(linea, sizeof(char)*(chars+1));
        linea[chars++] = getc(f);
    }while(linea[chars-1]!='\n' && (!feof(f)));
    if (chars > 0){
        linea[chars-1] = '\0';
    }
    return linea;
}

char* copiaCadena(char* original){
    char *copia=NULL;
    copia = (char*)realloc(copia,strlen(original)+1);
    strcpy(copia,original);
    return copia;
}

void imprimirAlumnos(listaAlumnos_t lista){
    for (int i = 0; i < lista.tam; i++){
        printf("---------Alumno %d---------\n",i);
        mostrarAlumno(lista.alumno[i]);
    }
}

void mostrarAlumno(alumno_t alumno){
    printf("Nombre: %s\n",alumno.nombre);
    printf("Apellido: %s\n",alumno.apellido);
    printf("Edad: %d\n",alumno.edad);
    printf("Estado: %s\n", tiposEstado[alumno.estado]);
}

void introducirAlumnoEnLista(listaAlumnos_t* lista){
    //Reservo memoria para el alumno
    lista->alumno = (alumno_t*)realloc(lista->alumno,sizeof(alumno_t)*(lista->tam+1));
    //Lo creo
    lista->alumno[lista->tam++] = nuevoAlumno();
}

alumno_t nuevoAlumno(){
    alumno_t a={NULL,NULL,0};
    int err=0;
    int edad = 0;
    //Pido el nombre al usuario
    printf("Introduce el nombre del alumno: ");
    a.nombre = leeLineaDFichero(stdin);
    //Pido apellido al usuario
    printf("Introduce el apellido del alumno: ");
    a.apellido = leeLineaDFichero(stdin);
    //Pido edad al usuario
    //Compruebo si introduce un numero
    do{
        printf("Introduce la edad del alumno: ");
        err = scanf("%d", &edad);
        while(getchar() != '\n'); //Limpio buffer
        if (err != 1){
            fprintf(stderr,"ERROR: Dato introducido no numerico\n");
        }
        else {
            a.edad = edad;
        }
    }while(err != 1);
    //Establezco el estado de sin guardar
    a.estado = no_guardado;
    //Devuelvo el alumno
    return a;
}

void guardarAlumnosEnFichero(listaAlumnos_t lista, char* nombreFichero){
    //Abro fichero en modo escritura binaria
    FILE *fOut = fopen(nombreFichero,"wb");
    //Por cada alumno en la lista, imprimir en formato requerido
    for (int i = 0; i < lista.tam; i++){
        fprintf(fOut, "Nombre: %s,Apellido: %s,Edad: %d\n",lista.alumno[i].nombre,lista.alumno[i].apellido,lista.alumno[i].edad);
        //Cambio estado a guardado
        if (lista.alumno[i].estado == no_guardado){
            lista.alumno[i].estado = guardado;
        }
    }
    //Cierro fichero
    fclose(fOut);
}

listaAlumnos_t buscarAlumnoEnLista(char* linea, listaAlumnos_t lista){
    listaAlumnos_t c = {NULL,0};
    bool_e encontrado = F;
    char* copia = NULL;
    char* token = NULL;
    //Por cada alumno
    for (int i = 0; i < lista.tam; i++){
        //Compruebo con el nombre
        //Si son iguales
        if (strcmp(linea,lista.alumno[i].nombre) == 0){
            c.alumno = (alumno_t*)realloc(c.alumno, sizeof(alumno_t)*(c.tam+1));
            //Asigno memoria para guardar nombre y apellidos
            c.alumno[c.tam].nombre = malloc(strlen(lista.alumno[i].nombre)+1);
            c.alumno[c.tam].apellido = malloc(strlen(lista.alumno[i].apellido)+1);
            //Copio los datos
            strcpy(c.alumno[c.tam].nombre,lista.alumno[i].nombre);
            strcpy(c.alumno[c.tam].apellido,lista.alumno[i].apellido);
            c.alumno[c.tam].edad = lista.alumno[i].edad;
            c.alumno[c.tam].estado = lista.alumno[i].estado;
            c.tam++;
        }
        //Si no son iguales compruebo el apellido
        else{
            //Hago copia del apellido
            copia = (char*)realloc(copia, strlen(lista.alumno[i].apellido)+1);
            strcpy(copia,lista.alumno[i].apellido);
            //Busco si hay un espacio
            token = strtok(copia," ");
            //Comparo directamente
            if (strcmp(linea,lista.alumno[i].apellido) == 0){
                c.alumno = (alumno_t*)realloc(c.alumno, sizeof(alumno_t)*(c.tam+1));
                //Asigno memoria para guardar nombre y apellidos
                c.alumno[c.tam].nombre = malloc(strlen(lista.alumno[i].nombre)+1);
                c.alumno[c.tam].apellido = malloc(strlen(lista.alumno[i].apellido)+1);
                //Copio los datos
                strcpy(c.alumno[c.tam].nombre,lista.alumno[i].nombre);
                strcpy(c.alumno[c.tam].apellido,lista.alumno[i].apellido);
                c.alumno[c.tam].edad = lista.alumno[i].edad;
                c.alumno[c.tam].estado = lista.alumno[i].estado;
                c.tam++;
            }
            //Si hay espacio, comparo con cada apellido
            else{
                if (strcmp(linea,token) == 0){
                    c.alumno = (alumno_t*)realloc(c.alumno, sizeof(alumno_t)*(c.tam+1));
                    //Asigno memoria para guardar nombre y apellidos
                    c.alumno[c.tam].nombre = malloc(strlen(lista.alumno[i].nombre)+1);
                    c.alumno[c.tam].apellido = malloc(strlen(lista.alumno[i].apellido)+1);
                    //Copio los datos
                    strcpy(c.alumno[c.tam].nombre,lista.alumno[i].nombre);
                    strcpy(c.alumno[c.tam].apellido,lista.alumno[i].apellido);
                    c.alumno[c.tam].edad = lista.alumno[i].edad;
                    c.alumno[c.tam].estado = lista.alumno[i].estado;
                    c.tam++;
                }
                else {
                    token = strtok(NULL,"\0");
                    if (token != NULL){
                        if (strcmp(linea,token) == 0){
                            c.alumno = (alumno_t*)realloc(c.alumno, sizeof(alumno_t)*(c.tam+1));
                            //Asigno memoria para guardar nombre y apellidos
                            c.alumno[c.tam].nombre = malloc(strlen(lista.alumno[i].nombre)+1);
                            c.alumno[c.tam].apellido = malloc(strlen(lista.alumno[i].apellido)+1);
                            //Copio los datos
                            strcpy(c.alumno[c.tam].nombre,lista.alumno[i].nombre);
                            strcpy(c.alumno[c.tam].apellido,lista.alumno[i].apellido);
                            c.alumno[c.tam].edad = lista.alumno[i].edad;
                            c.alumno[c.tam].estado = lista.alumno[i].estado;
                            c.tam++;
                        }
                    }
                }
            }
        }
    }
    //Devuelvo la lista de coincidencias
    return c;
}