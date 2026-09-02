#include "Licencias.h"
#include "Licencia.h"
#include <iostream>

using namespace std;

Licencias::Licencias(int capacidad) {
	this->capacidad = capacidad;
	this->n = 0;
	tabla = new ListaEnlazada[capacidad]; //Creo un array de lista enlazadas
}

int Licencias::obtenerPosicion (long dni) {
	return dni % this->capacidad; //Funcion hash
}

void Licencias::insertarLicencia (long codigo, string herramienta) {
	int posicion = this->obtenerPosicion(codigo); //Obtengo la posicion
	Licencia l = Licencia();
	l.codigo = codigo;
	l.herramienta = herramienta;
	assertdomjudge(this->tabla[posicion].buscar(l) == -1); //Compruebo que no exista ya la nueva licencia
	this->tabla[posicion].insertar(0,l); //La inserto al principio de la lista enlazada
}

void Licencias::eliminarLicencia (long codigo) {
	int posicion = this->obtenerPosicion(codigo); //Obtengo posicion
	Licencia l = Licencia();
	l.codigo = codigo;
	int posElemento = this->tabla[posicion].buscar(l); //Encuentro su posicion en la respectiva lista
	assertdomjudge(posElemento != -1); //Compruebo que exista dicho elemento
	this->tabla[posicion].eliminar(posElemento); //Lo elimino
}

void Licencias::imprimir() {
	cout << endl;
	for (int i=0; i<capacidad; i++) {
		cout << "P" << i << ": ";
		this->tabla[i].imprimir();
	}
}
