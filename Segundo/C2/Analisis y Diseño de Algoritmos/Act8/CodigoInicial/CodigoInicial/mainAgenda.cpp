#include <iostream>
#include<string>
#include "Agenda.h"


using namespace std;

int main() {

	int capacidad; // Capacidad de la tabla hash
	char opcion; // Opcion de menu introducida por teclado

	long telefono; // Clave para algunas opciones
	string nombre; // Nombre del contacto para la opcion de meter


	cout << "Introduce la capacidad de la tabla: ";
	cin >> capacidad;

	Agenda agenda(capacidad);


	do {
		cin >> opcion;

		switch (opcion) {
		case 'I':
			agenda.imprimir();
			break;
		case 'C':
			// Comprobar si está un contacto
			cout << "Numero de telefono del contacto ";
			cin >> telefono;
			if (agenda.existeContacto(telefono)) 
				cout << "El contacto SI esta\n";
			else 
				cout << "El contacto NO esta\n";
			break;
		case 'V':
			// Ver contacto (obtener su nombre)
			cout << "Numero de telefono del contacto: ";
			cin >> telefono;
			cout << "Nombre: " << agenda.getContacto(telefono) << endl;
			break;
		case 'A':
			// Añadir un contacto
			cout << "Numero de telefono del contacto: ";
			cin >> telefono;
			cout << "Nombre del contacto: ";
			cin >> nombre;
			agenda.introducirContacto(telefono, nombre);
			break;
		case 'E':
			// Eliminar un contacto
			cout << "Numero de telefono del contacto: ";
			cin >> telefono;
			agenda.eliminarContacto(telefono);
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
