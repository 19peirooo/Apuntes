#include <iostream>
#include "Licencias.h"

using namespace std;

int main() {

	int capacidad;
	char opcion;

	


	cout << "Introduce la capacidad de la tabla: ";
	cin >> capacidad;

	Licencias licencias(capacidad);


	do {
		long codigo; 
		string herramienta; 
		
		cin >> opcion;

		switch (opcion) {
		case 'I':
			licencias.imprimir();
			break;
		case 'A':

			cout << "Codigo de licencia: ";
			cin >> codigo;
			cout << "Nombre de la herramienta: ";
			cin >> herramienta;
			licencias.insertarLicencia(codigo, herramienta);
			break;
		case 'E':
			cout << "Codigo de licencia: ";
			cin >> codigo;
			licencias.eliminarLicencia(codigo);
			break;
		case 'S':
		    break;
		default:
			cout << "Opcion incorrecta\n";
			break;

		} // Fin switch

	} while (opcion != 'S'); 

	return 0;
}
