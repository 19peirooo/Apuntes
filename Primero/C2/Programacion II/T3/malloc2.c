#include <stdio.h>
#include <stdlib.h>

int main(int argc , char **argv){
	
	void *ptrVoid = NULL;// Para reservar memoria
	int *ptrInt = NULL;
	char *ptrChar = NULL;
	
	ptrVoid = (void*)malloc(10);
	ptrInt = (int*)ptrVoid;
	
	ptrInt[0]=1;
	
	printf("El contenido es: %d...\n", ptrInt[0]);
	ptrChar=(char*)malloc(100);
	ptrChar[0]=1;
	printf("El contenido es: %c...\n", ptrChar[0]);
	
	free(ptrChar);
	free(ptrInt); //Liberar ptrInt y ptrVoid. Funciona tambien con free(ptrVoid)
}