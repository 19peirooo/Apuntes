#include <stdio.h>

#define NUM_EMPLEADOS 5
#define MAX_CORREO 50
#define MAX_USER 30

void GenerarUsuario(char correo[MAX_CORREO], char user[MAX_USER], int pos_arroba);
int comprobarMail(char correo[MAX_CORREO], int tam, int *pos_arroba);
int tamUsuario(char *usuario);

void main(){
	char mail[MAX_CORREO]={'\0'};
	char usuario[MAX_USER]={'\0'};
	char c;
	int tamMail = 0,tamañoUsuario, mailValido = 0, pos_arroba;
	while (!mailValido){
		tamMail = 0;
		for (int i = 0; i < MAX_CORREO; i++){
			mail[i] = '\0'; 
		}
		printf("Introduce tu email: ");
		while ((c = getchar()) != '\n' && tamMail < MAX_CORREO){
			mail[tamMail] = c;
			tamMail++;
		}
		mailValido = comprobarMail(mail,tamMail,&pos_arroba);
		if (!mailValido){
			printf("Mail Invalido\n");
		}
	}
	GenerarUsuario(mail,usuario,pos_arroba);
	tamañoUsuario = tamUsuario(usuario);
	printf("Correo: %s , Usuario: %s , Tamanyo: %d", mail, usuario, tamañoUsuario);
}

int comprobarMail(char correo[MAX_CORREO], int tam, int *pos_arroba){
	int valido = 0;
	char dominio[] = "@cactussystem.com";
	
	for (int i = 0; i < tam && !valido; i++){
		if (correo[i] == '@'){
			*pos_arroba = i;
			for (int j = i; j > 0 && !valido; j--){
				if (correo[j] == '.'){
					valido = 1;
				}
			}
			for (int j = i; j < tam && valido; j++){
				if (dominio[j-i] != correo[j]){
					valido = 0;
				}
			}
		}
	}
	return valido;
}

void GenerarUsuario(char correo[MAX_CORREO], char user[MAX_USER], int pos_arroba){
	for (int i = 0; i < pos_arroba; i++){
		user[i] = correo[i];
	}
}

int tamUsuario(char *usuario){
	int tam = 0;
	for(int i = 0; i < MAX_USER; i++){
		if (*usuario != '\0'){
			usuario++;
			tam++;
		}
	}
	return tam;
}