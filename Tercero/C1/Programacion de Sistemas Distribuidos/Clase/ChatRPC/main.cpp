 #include <iostream>
#include "user.h"


int main(int argc, char** argv){
	string username;
	string msg;
	cout << "Introduce Nombre de Usuario: ";
	getline(cin,username);

	User user(username);
	int option = -1;

	while (option != 0) {
		cout << "1. Enviar Mensaje" << endl << "2. Ver Mensajes" << endl << "0. Salir" << endl;
		cout << "Opcion: ";
		cin >> option;
		while ((getchar()) != '\n');

		switch (option) {
			case 1:{
				string msg;
				getline(cin,msg);
				user.sendMsg(msg);
			}break;

			case 2:{
				user.seeChat();
			}break;

			case 0:{
				cout << "Saliendo del Programa" << endl;
			}break;

			default:{
				cout << "ERROR: Opcion Invalida";
			}break;
		}
	}	
	return 0;
}

