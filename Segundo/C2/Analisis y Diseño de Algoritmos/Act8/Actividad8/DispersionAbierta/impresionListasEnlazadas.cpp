#include "impresionListasEnlazadas.h"
#include "assertdomjudge.h"
#include <iostream>
using namespace std;

void imprimirListaEnlazada(ListaEnlazada *lista) {
	assertdomjudge(lista != NULL);

	// Imprimimos tama�o
	cout << "n=" << lista->getN() << "|ListaEnlazada=";

	// Si la lista est� vac�a, imprimimos algo especial
	if (lista->getN() == 0) cout << "vacia";

	// Si no est� vac�a, imprimimos los elementos separados por comas, siempre que no sea demasiado grande
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
