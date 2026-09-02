#include <stdio.h>
#include <string.h>

int main() {
    char cadena[] = "Hola mundo, este es un ejemplo";
    char subcadena[] = "mundo";

    // Busca la primera ocurrencia de la subcadena dentro de la cadena
    char *resultado = strstr(cadena, subcadena);

    if (resultado != NULL) {
        printf("La subcadena \"%s\" fue encontrada en la posición %ld.\n", subcadena, resultado - cadena);
    } else {
        printf("La subcadena \"%s\" no fue encontrada.\n", subcadena);
    }

    return 0;
}
