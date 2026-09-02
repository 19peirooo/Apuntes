#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum hab_e{
    lanzallamas=0,cuchilla=1,catapulta=2,martillo=3,NUMHABILIDADES=4,ERRHAB = -1
}hab_e;

char* str hab_str[NUMHABILIDADES+1] = {"lanzallamas","cuchilla","catapulta","martillo","Error de Habilidad"};

typedef struct robot_t{
    char* nombre;
    int nivel;
    int pot;
    int res;
    int vel;
    hab_e habilidad;
}

char* leeFichero(FILE* f);
hab_e parseaHab(char* habs);
int main(int argc, char** argv){
    char* nombreFIn = "robots.txt";
    char* nombreFOut = "lanzallamas.txt";
    char* data = leeFichero(nombreFIn);
    float media = 0;
    int numRobots = 0;
    fOut = fopen(nombreFOut,"wb");
    robot_t r = {NULL,0,0,0,0,NULL};
    r.nombre = strtok(data,":");
    do{
        r.nivel=atoi(strtok(NULL),":");
        r.pot=atoi(strtok(NULL),":");
        r.res=atoi(strtok(NULL),":");
        r.vel=atoi(strtok(NULL),":");
        r.habilidad=parseaHab(strtok(NULL,"\n"));
        printf("Nombre: %s, Nivel: %d, Potencia: %d, Resistencia: %d, Habilidad: %s\n", r.nombre, r.nivel, r.pot, r.res, r.vel, hab_str[r.habilidad]);
        media+= r.res;
        numRobots++;
    }while((r.nombre=strtok(NULL,":")) != NULL && );
    printf("Media de resistencias: %f", media/numRobots);
    if (parseaHab(hab_str[r.habilidad]) == lanzallamas){
        fprintf("%s:%d:%d:%d:%s\n", r.nombre, r.nivel, r.pot, r.res, r.vel, hab_str[r.habilidad]);
    }
    fclose(fOut);
    free(data);
}

char* leeFichero(char* fName){
    FILE* f = fopen(fName,"rb");
    char* data = NULL;
    if (f != NULL){
        fseek(f,0,SEEK_END);
        int size = ftell(f);
        fseek(f,0,SEEK_SET);
        data = malloc(size);
        fread(data,size,1,f);
        fclose(f);
        data[size] = '\0';
    }
}

hab_e parseaHab(char* habs){
    hab_e hab=ERRHAB;
    for (hab_e i = lanzallamas; i < NUMHABILIDADES; i++){
        if(strcmp(hab_str[i],habs)==0){
            hab = i;
        }
    }
    return hab;
}