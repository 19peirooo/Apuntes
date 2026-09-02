#include <stdio.h>

void ordenarNumeros(int *ordenada, int *nums,int tam);
int strToInt(char *str);


int main(int argc, char **argv){
	int nums = argc-1, j = 0;
	int orden[nums];
	int numeros[nums];
	
	if (argc > 6 || argc < 4){
		printf("Numero de parametros incorrecto");
	}
	else{
		for (int i = 1; i < argc; i++){
			nums[i-1]=strToInt(argv[i]);
		}
		for (int i = 0; i < nums; i++){
			printf("%d", nums[i]);
		}
	}
	return 0;
}

int strToInt(char *str){
	int res=0,digitos=0; 
	while (*str != '\0'){
		res+=((int)*(str)-48);
		str++;
		if (*str != '\0'){
			res*=10;
		}
	}
}