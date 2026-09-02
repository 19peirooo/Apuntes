#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define H "<head>"
#define B "<body>"
#define CH "</head>"
#define CB "</body>"

int main (int argc, char **argv){
	const char *html = "<head></head><body>Hola mundo desde html</body>";
	char *mensaje = NULL;
	int lenghtHtml = strlen(html);
	int headPosicion = strstr(html,H)-html;
	int headEnd = headPosicion + strlen(H);
	int closeHeadPosicion = strstr(html,CH)-html;
	int closeHeadEnd = closeHeadPosicion + strlen(CH);
	int bodyPosicion = strstr(html,B)-html;
	int bodyEnd = bodyPosicion + strlen(B);
	int closeBodyPosicion = strstr(html,CB) - html;
	int closeBodyEnd = closeBodyPosicion + strlen(CB);
	int lenghtMensaje = 0;
	if ((headEnd < closeHeadEnd)&&(bodyEnd < closeBodyEnd)){
		if (closeHeadEnd <= bodyPosicion){
			lenghtMensaje = closeBodyEnd - bodyEnd;
			mensaje = (char*)realloc(mensaje, lenghtMensaje + 1);
			memcpy(mensaje,html+bodyEnd,lenghtMensaje);
			mensaje[lenghtMensaje] = '\0';
			printf("Mensaje: %s\n", mensaje);
			free(mensaje);
			mensaje = NULL;
		}
		else {
			printf("El head esta despues del body.\n");
		}
	}
	else {
		printf("Las etiquetas de apertura y cierre en orden incorrecto.\n");
	}
	return 0;
}