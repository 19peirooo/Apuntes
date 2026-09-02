#include <stdio.h>
#include <stdlib.h>

#define MAX_USERS 100

typedef struct usuario_t{
	char nombre[10];
	char apellido[15];
	char dni[9];
	int edad;
	float peso;
	char telefono[9];
}usuario_t;

typedef struct listaUsuarios_t{
	usuario_t users[MAX_USERS];
	int size;
	int numUsersIntroducidos;
}listaUsuarios_t;

void imprimeUsuario(usuario_t user);
usuario_t nuevoUsuario();

int main(int argc, char **argv){
	int opcion=0, temp = 0;
	int menuCerrado=0;
	int edadMasPequeña=1000;
	listaUsuarios_t usuarios={
		.size = MAX_USERS,
		.numUsersIntroducidos=0
	};
	
	while (!menuCerrado){
		printf("\n1. Añadir e Imprimir Usuario\n2.Mostrar Usuarios mas Jovenes\n3.Salir");
		printf("Opcion: ");
		scanf("%d",&opcion);
		
		switch (opcion){
			case 1:{
				if (usuarios.numUsersIntroducidos < usuarios.size){
					usuarios.users[usuarios.numUsersIntroducidos] = nuevoUsuario();
					imprimeUsuario(usuarios.users[usuarios.numUsersIntroducidos]);
					usuarios.numUsersIntroducidos++;
				} else {
					printf("Error: Numero maximo de usuarios alcanzado");
				}
			}
				break;
			case 2:{
				listaUsuarios_t smallestUsers={
					.size = 5,
					.numUsersIntroducidos=0
				};
				for (int i = 0; i < usuarios.numUsersIntroducidos; i++){
					if (usuarios.users[i].edad < edadMasPequeña && usuarios.users[i].edad > temp){
						edadMasPequeña = usuarios.users[i].edad;
					}
				}
				for (int i = 0; i < usuarios.numUsersIntroducidos; i++){
					if (usuarios.users[i].edad == edadMasPequeña && smallestUsers.numUsersIntroducidos < smallestUsers.size){
						smallestUsers.users[smallestUsers.numUsersIntroducidos] = usuarios.users[i];
						smallestUsers.numUsersIntroducidos++;
					}
				}
				temp = edadMasPequeña;
			}
				break;
			case 3:
				menuCerrado = 1;
				break;
			default:{
				printf("Opcion Incorrecta");
			}
				break;
		}
	}
	return 0;
}

usuario_t nuevoUsuario(){
	usuario_t u1;
	printf("Introduce el nombre: ");
	scanf("%s", u1.nombre);
	printf("Introduce el apellido: ");
	scanf("%s", u1.apellido);
	printf("Introduce el DNI: ");
	scanf("%s", u1.dni);
	printf("Introduce el edad: ");
	scanf("%d", &u1.edad);
	printf("Introduce el peso: ");
	scanf("%f", &u1.peso);
	printf("Introduce el telefono: ");
	scanf("%s", u1.telefono);
	return u1;
}

void imprimeUsuario(usuario_t user){
	printf("Nombre: %s\n", user.nombre);
	printf("Apellido: %s\n", user.apellido);
	printf("DNI: %s\n", user.dni);
	printf("Edad: %d\n", user.edad);
	printf("Peso: %f\n", user.peso);
	printf("Telefono: %s\n", user.telefono);
}