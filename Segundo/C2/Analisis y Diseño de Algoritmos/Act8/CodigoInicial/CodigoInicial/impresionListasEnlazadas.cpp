#include "impresionListasEnlazadas.h"
#include "assertdomjudge.h"
#include <iostream>
using namespace std;

void imprimirListaEnlazada(ListaEnlazada *lista) {
	assertdomjudge(lista != NULL);

	// Imprimimos tamaño
	cout << "n=" << lista->getN() << "|ListaEnlazada=";

	// Si la lista está vacía, imprimimos algo especial
	if (lista->getN() == 0) cout << "vacia";

	// Si no está vacía, imprimimos los elementos separados por comas, siempre que no sea demasiado grande
	// Si es demasiado grande, imprimimos un mensaje especial
	else {
		if (lista->getN() > 20) cout << "demasiadosElementosParaMostrar";
		else {
			for (int i = 0; i < lista->getN(); i++) {
				Contacto elemento = lista->getValor(i); // Elemento a imprimir
				cout << "(" << elemento.telefono << "," << elemento.nombre << ")";
				if (i < lista->getN() - 1) cout << ","; // Imprimimos "," si no estamos al final
			}
		}
	}
	cout << endl;
}
