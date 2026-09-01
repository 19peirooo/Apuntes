#include "DispersionAbierta.h"


using namespace std;

int main() {

	int capacidad; // Capacidad de la tabla hash
	char opcion; // Opcion de menu introducida por teclado

	long clave; // Clave para algunas opciones
	string valor; // Nombre del contacto para la opcion de meter


	cout << "Introduce la capacidad de la tabla: ";
	cin >> capacidad;

	Hash hash(capacidad);

	do {
        cout << "I: Imprimir tabla" << endl;
        cout << "C: Comprobar si existe tupla"<< endl;
        cout << "V: Ver tupla"<< endl;
        cout << "A: Introducir tupla" << endl;
        cout << "E: Eliminar tupla" << endl;
        cout << "S: Salir" << endl;
		cin >> opcion;

		switch (opcion) {
		case 'I':
			hash.imprimirTabla();
			break;
		case 'C':
			// Comprobar si est� un contacto
			cout << "Clave:  ";
			cin >> clave;
			if (hash.existeValor(clave)) 
				cout << "Existe tupla\n";
			else 
				cout << "NO existe tupla\n";
			break;
		case 'V':
			// Ver contacto (obtener su nombre)
			cout << "Clave:  ";
			cin >> clave;
			cout << "Valor: " << hash.getValor(clave) << endl;
			break;
		case 'A':
			// A�adir un contacto
			cout << "Clave: ";
			cin >> clave;
			cout << "Valor: ";
			cin >> valor;
			hash.introducir(clave, valor);
			break;
		case 'E':
			// Eliminar un contacto
			cout << "Clave: ";
			cin >> clave;
			hash.eliminar(clave);
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
