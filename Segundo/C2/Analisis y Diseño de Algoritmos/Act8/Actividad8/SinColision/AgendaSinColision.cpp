#include "Agenda.h"
#include "assertdomjudge.h"
#include "iostream"

using namespace std;

/* 	obtenerPosicion
	Devuelve la posicion de la lista enlazada en la que se encuentra un elemento en la agenda
	Entrada: telefono
	Retorno: Posicion de la lista enlazada en la que se encuentra
	Precondicion: Ninguna
	Complejidad Temporal: T(n) = 1, O(1)
	Complejidad Espacial: M(n) = 1, O(1) 
*/

int Agenda::obtenerPosicion (long telefono) {
	return telefono % this->capacidad;
}

/*	Constructor
	Construye la agenda
	Entrada: Capacidad de la agenda
	Retorno: Ninguno
	Precondicion: Ninguna
	Complejidad Temporal: T(n) = 3n + 1, O(n)
	Complejidad Espacial: M(n) = 3n + 1, O(n)
*/

Agenda::Agenda(int capacidad){
	this->capacidad = capacidad;
	this->nombres = new string[capacidad]; //T(n) = n, M(n) = n
	this->telefonos = new long[capacidad]; //T(n) = n, M(n) = n
	this->ocupada = new bool[capacidad]; //T(n) = n, M(n) = n
}

/* 	existeContacto
	Comprueba si existe un contacto
	Entrada: Telefono del contacto
	Retorno: True si existe, false si no existe
	Precondicion: Ninguna
	Complejidad Temporal: T(n) = 1, O(1)
	Complejidad Espacial: M(n) = 1, O(1)
*/

bool Agenda::existeContacto (long telefono) {
	return this->ocupada[this->obtenerPosicion(telefono)] && this->telefonos[this->obtenerPosicion(telefono)] == telefono;
}

/*  getContacto
	Devuelve el nombre del contacto
	Entrada: Telefono del contacto
	Retorno: Nombre del contacto
	Precondicion: El contacto ha de existir
	Complejidad Temporal: T(n) = 1, O(1)
	Complejidad Espacial: M(n) = 1, O(1)
*/

string Agenda::getContacto (long telefono) {
	assertdomjudge(this->existeContacto(telefono));
	return this->nombres[this->obtenerPosicion(telefono)];
}

/*	introducirContacto
	Introduce un contacto en la agenda
	Entrada: Telefono y nombre del nuevo contacto
	Retorno: Ninguno
	Precondicion: El contacto no puede existir ya en la agenda
	Complejidad Temporal: T(n) = 1, O(1)
	Complejidad Espacial: M(n) = 1, O(1)
*/

void Agenda::introducirContacto (long telefono, string contacto) {
	assertdomjudge(!(this->ocupada[this->obtenerPosicion(telefono)]));
	this->telefonos[this->obtenerPosicion(telefono)] = telefono;
	this->nombres[this->obtenerPosicion(telefono)] = contacto;
	this->ocupada[this->obtenerPosicion(telefono)] = true;
}

/*	eliminarContacto
	Elimina un contacto de la agenda
	Entrada: Telefono del contacto
	Precondicion: El contacto ha de existir
	Complejidad Temporal: T(n) = 1 , O(1)
	Complejidad Espacial: M(n) = 1, O(1)
*/

void Agenda::eliminarContacto (long telefono) {
	assertdomjudge(this->existeContacto(telefono));
	this->ocupada[this->obtenerPosicion(telefono)] = false;
}

/*	Destructor
	Destructor de la clase Agenda
	Entrada: Ninguna
	Retorno: Ninguno
	Precondicion: Ninguna
	Complejidad Temporal: T(n) = 1, O(1)
	Complejidad Espacial: M(n) = 1, O(1)
*/

Agenda::~Agenda() {
	delete[] this->nombres;
	delete[] this->ocupada;
	delete[] this->telefonos;	
}

/* 	imprimir
	Imprime la lista de lista
	Entrada: Ninguna
	Retorno: Ninguno
	Precondicion: Ninguna
	Complejidad Temporal: T(n) = n+1, O(n)
	Complejidad Espacial: M(n) = 1, O(1)
*/

void Agenda::imprimir() {
	for (int i=0; i<this->capacidad; i++) {
		cout << "Posicion " << i << " | Ocupada: " << ocupada[i] << " | Telefono: " << telefonos[i] << " | Nombre: " << nombres[i] << endl;
	}
}