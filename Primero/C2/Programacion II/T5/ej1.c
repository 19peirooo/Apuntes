#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct string_t{
    char *cadena;
    int tam;
}string_t;

typedef struct alumno_t{
    string_t nombre;
    string_t apellido;
}alumno_t;

string_t leeLineaDinamicaFichero(FILE *f);
alumno_t leeAlumno(const char* nombreFic);
string_t concatenaCadenas(string_t p1, string_t p2);
int main(int argc, char **argv){
    const char* nombreFichero = "datos.txt";
    alumno_t alumno=leeAlumno(nombreFichero);
    string_t nombreEntero = {.cadena = NULL, .tam = 0};
    nombreEntero = concatenaCadenas(alumno.nombre,alumno.apellido);
    printf("%s", nombreEntero.cadena);
}

string_t leeLineaDinamicaFichero(FILE *f){
    char *linea = NULL;
    int chars = 0;
    char c = '\0';

    string_t str;

    do{
        c = getc(f);
        if (c != EOF){
            linea = (char*)realloc(linea,chars+1);
            linea[chars++] = c;
        }
        
    }while( linea[chars-1] != '\n' && (!feof(f)));
    if (chars > 0){
		    linea[chars-1] = '\0';
	}
    str.cadena = linea;
    str.tam = chars;
    return str;
}

alumno_t leeAlumno(const char* nombreFic){
    alumno_t a={.nombre=NULL, .apellido=NULL};
    FILE *f = fopen(nombreFic,"rb");
    if (f == NULL){
        printf("ERROR\n");
    }
    else {
        a.nombre = leeLineaDinamicaFichero(f);
        a.apellido = leeLineaDinamicaFichero(f);
        fclose(f);
    }
    return a;
}

string_t concatenaCadenas(string_t p1, string_t p2){
    string_t c;
    const char* espacio = " ";
    c.tam = strlen(p1.cadena)+strlen(p2.cadena)+2;
    c.cadena = (char*)realloc(c.cadena,sizeof(char)*c.tam);
    c.cadena[0]='\0';

    strcat(c.cadena,p1.cadena);
    strcat(c.cadena,espacio);
    strcat(c.cadena, p2.cadena);

    return c;
}