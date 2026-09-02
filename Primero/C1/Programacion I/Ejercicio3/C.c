#include <stdio.h>

#define TAM 50

int comprobarEmail(char email[], int tamaño);

int main(){
	char email[TAM]; //Cadena del email
	char caracter;
	int tamaño;
	int valido = 0, correcto = 0;
	
	while (!valido){
		tamaño = 0;
		printf("Introduce tu email de la U-TAD: ");
		while ((caracter = getchar())!='\n'){
			email[tamaño] = caracter;
			tamaño++;
		}
		if (tamaño > TAM){
			printf("Email demasiado largo");
			for (int i = 0; i < TAM;i++){ //Vacio la cadena para que se pueda volver a escribir en ella
				email[i] = ' ';
			}
			valido = 0;
		}
		else{
			email[tamaño]= '\0';
			correcto = comprobarEmail(email,tamaño);
			valido = 1;
		}
	}
	if (correcto){
		printf("Correo Valido");
	}
	else{
		printf("Correo Erroneo");
	}
}

int comprobarEmail(char email[], int tamaño){
	int pos_arroba,i;
	char sufijo[] = "@live.u-tad.com";
	int hayPunto = 0;
	for (i = 0; i < tamaño; i++){
		if (email[i] == '@'){
			pos_arroba = i;
		}
	}
	if (pos_arroba < 6){
		return 0;
	}
	else{
		i = 0;
		while (i < pos_arroba && !hayPunto){
			if (email[i] == '.'){
				if (i < 3){
					return 0;
				}
				hayPunto = 1;
			}
			i++;
		}
		if (!hayPunto){
			return 0;
		}
		for (i = pos_arroba; i < tamaño; i++){
			if (sufijo[i-pos_arroba] != email[i]){
				return 0;
			}
		}
		return 1;
	}
	
}