#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct usuario_t{
    char* nombre;
    char* ape1;
    char* ape2;
}usuario_t;

usuario_t* pideUsuario();
char *leeLineaFichero(FILE* f);
usuario_t* copiarUsuario(usuario_t *user);
void guardarUsuario(char *nombreFichero, usuario_t *user);

int main(int argc, char **argv){

    usuario_t* usuario = (usuario_t*)malloc(sizeof(usuario_t));
    usuario_t *userCopia = (usuario_t*)malloc(sizeof(usuario_t));
    memset(usuario,0,sizeof(usuario_t)); //Permite inicializar estructuras a NULL
    usuario = pideUsuario();

    printf("%s %s %s",usuario->nombre,usuario->ape1,usuario->ape2);
    guardarUsuario("usuarios.txt", usuario);
    free(usuario->nombre);
    free(usuario->ape1);
    free(usuario->ape2);
    free(usuario);

    free(userCopia->nombre);
    free(userCopia->ape1);
    free(userCopia->ape2);
    free(userCopia);
}

char *leeLineaFichero(FILE* f){
    char *linea=NULL;
    int chars = 0;
    char c;

    do{
        c = getc(f);
        if (c != EOF){
            linea = (char*)realloc(linea,chars+1);
            linea[chars++] = c;
        }
    }while(linea[chars-1] != '\n' && (!feof(f)));
    if (chars > 0){
        linea[chars-1] = '\0';
    }
    return linea;
}
usuario_t* pideUsuario(){
    usuario_t* u1;
    printf("Introduce el nombre de el usuario: ");
    u1->nombre = leeLineaFichero(stdin);
    printf("Introduce el primer apellido de el usuario: ");
    u1->ape1 = leeLineaFichero(stdin);
    printf("Introduce el segundo apellido de el usuario: ");
    u1->ape2 = leeLineaFichero(stdin);
    return u1;
}

usuario_t* copiarUsuario(usuario_t* user){
    usuario_t* copia = (usuario_t*)malloc(sizeof(usuario_t));
    copia->nombre=(char*)realloc(copia->nombre, sizeof(char)*(strlen(user->nombre)+1));
    copia->ape1=(char*)realloc(copia->ape1, sizeof(char)*(strlen(user->ape1)+1));
    copia->ape2=(char*)realloc(copia->ape2, sizeof(char)*(strlen(user->ape2)+1));

    copia->nombre[0] = '\0';
    copia->ape1[0] = '\0';
    copia->ape2[0] = '\0';

    strcpy(copia->nombre, user->nombre);
    strcpy(copia->ape1,user->ape1);
    strcpy(copia->ape2,user->ape2);

    return copia;
}
void guardarUsuario(char *nombreFichero, usuario_t *user){
    FILE *fOut = fopen(nombreFichero,"wb"); 
    if (fOut != NULL){
        fprintf(fOut,"%s\n",user->nombre);
        fprintf(fOut,"%s\n",user->ape1);
        fprintf(fOut,"%s\n",user->ape2);
        fclose(fOut);
    } else {
        printf("ERROR\n");
    }
    
}