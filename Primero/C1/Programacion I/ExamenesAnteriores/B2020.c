#include <stdio.h>

#define TAM 10

int validarDNI(char dni[TAM]);
void NuevoIdentificador(char *p_Cadena, char *p_nuevaCadena);

void main(){
	char dni[TAM];
	char nuevoDni[TAM];
	char c;
	int dniValido = 0;
	
	while (!dniValido){
		printf("Introduce tu DNI: ");
		scanf("%s", dni);
		while (getchar() != '\n');
		dniValido = validarDNI(dni);
		if (!dniValido){
			printf("DNI INVALIDO\n");
		}
	}
	
	NuevoIdentificador(dni,nuevoDni);
	nuevoDni[9]='\0';
	printf("Tu antiguo DNI es: %s\n", dni);
	printf("Tu nuevo DNI es: %s", nuevoDni);
}

int validarDNI(char dni[TAM]){
	int valido = 1;
	if (dni[9] != '\0'){
		valido = 0;
	}
	for (int i = 0; i < 8 ; i++){
		if (dni[i] >'9' || dni[i] < '0'){
			valido = 0;
		} 
	}
	if (dni[8] > 'Z' || dni[8] < 'A'){
		valido = 0;
	}
	return valido;
}

void NuevoIdentificador(char *p_Cadena, char *p_nuevaCadena){
	p_Cadena+=7;
	for (int i = 0; i < 8; i++){
		*p_nuevaCadena = *p_Cadena;
		p_Cadena--;
		p_nuevaCadena++;
	}
	p_Cadena+=9;
	*p_nuevaCadena = *p_Cadena;
}