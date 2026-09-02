#include <stdio.h>

#define TAM 8

int esMayuscula(char car);
int validarDNI(int n);
int verificarLetraNIF(int dni, char letra);
char calcularLetraNIF(int n);

void main(){
	int dni,dniValido=0,err,letraValida=0;
	char letra;
	while (!dniValido){
		printf("Introduce los numeros de tu DNI(sin letra): ");
		err = scanf("%d", &dni);
		while(getchar()!='\n');
		// Si se introduce un numero, que valide el dni
		// Sino, error
		if (err == 1){
			dniValido = validarDNI(dni);
			if (!dniValido){
				printf("Numero introducido de formato incorrecto\n");
			}
		}
		else{
			printf("Valor introducido no es numerico, intenta otra vez\n");
			dniValido = 0;
		}
	}
	printf("Introduce la letra de tu DNI(mayuscula): ");
	err = scanf("%c", &letra);
	if (err == 1){
		letraValida = esMayuscula(letra);
	}
	if (letraValida){
		letraValida = verificarLetraNIF(dni,letra);
		if (letraValida){
			printf("Letra %c no corresponde con %d, DNI es Incorrecto", letra, dni);
		}
		else{
			printf("Letra %c corresponde con %d, DNI es Correcto", letra, dni);
		}
	}
	else{
		printf("Letra Minuscula");
	}
	
}

int validarDNI(int n){
	// Si el numero es de 8 digitos
	if (n > 10000000 && n < 99999999){
		return 1;
	}
	else{
		return 0;
	}	
}

int esMayuscula(char car){
	if (car >= 'A' && car <= 'Z'){
		return 1;
	}
	else{
		return 0;
	}
}

char calcularLetraNIF(int n){
	int resultado = (n % 26)+65;
	char letra = (char)resultado;
	return letra;
}

int verificarLetraNIF(int dni, char letra){
	char res = calcularLetraNIF(dni);
	if (letra == res){
		return 1;
	}
	else{
		return 0;
	}
}