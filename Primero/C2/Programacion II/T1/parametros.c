#include <stdio.h>

void ejemplo1();

//argc --> Numero de parametros
//argv --> Parametros que se pasan --> Array
int main(int argc, char **argv){
	printf("argc: %d. argv: %s\n", argc, argv[0]); //Imprime argc y argv. Si no se pasa nada, argc = 1 y argv = ruta del archivo
	
	for (int i = 1; i < argc; i++){ // No empieza en 0 ya que en 0 esta la ruta al ejecutable
		printf("argv[%d]: %s\n", i , argv[i]);
	}
	
	//Seguir en mediaAlturas.c
}

void ejemplo1(){
	int num = 157;
	char *cnum = "157";
	
	printf("%d", num);
	printf("%s", cnum);
	
	int res=num+5;
	char *cres=cnum+5; //Suma 5 a la direccion de memoria
}