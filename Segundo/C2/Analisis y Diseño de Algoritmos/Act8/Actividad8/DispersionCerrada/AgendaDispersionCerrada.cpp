#include "AgendaCerrada.h"
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
	Complejidad Temporal: T(n) = 4n + 1, O(n)
	Complejidad Espacial: M(n) = 4n + 1, O(n)
*/

Agenda::Agenda(int capacidad){
	this->capacidad = capacidad;
	this->nombres = new string[capacidad];
	this->telefonos = new long[capacidad];
	this->ocupada = new bool[capacidad];
	this->borradas = new bool[capacidad];
}

/* 	existeContacto
	Comprueba si existe un contacto
	Entrada: Telefono del contacto
	Retorno: True si existe, false si no existe
	Precondicion: Ninguna
	Complejidad Temporal: T(n) = n+1, O(n)
	Complejidad Espacial: M(n) = 1, O(1)
*/
bool Agenda::existeContacto (long telefono) {
	return this->buscarContacto(telefono) != -1;
}

/*  getContacto
	Devuelve el nombre del contacto
	Entrada: Telefono del contacto
	Retorno: Nombre del contacto
	Precondicion: El contacto ha de existir
	Complejidad Temporal: T(n) = 2n+1, O(n)
	Complejidad Espacial: M(n) = 1, O(1)
*/
string Agenda::getContacto (long telefono) {
	assertdomjudge(this->existeContacto(telefono));
	return this->nombres[this->buscarContacto(telefono)];
}

/* 	buscarContacto
	Comprueba si existe un contacto
	Entrada: Telefono del contacto
	Retorno: True si existe, false si no existe
	Precondicion: Ninguna
	Complejidad Temporal: T(n) = n + 1, O(n)
	Complejidad Espacial: M(n) = 1, O(1)
*/

int Agenda::buscarContacto(long telefono) {
	int posicion = this->obtenerPosicion(telefono);
	int inicio = posicion;
	do {
		if (!this->ocupada[posicion] && !this->borradas[posicion]) {
			return -1;
		}

		if (this->ocupada[posicion] && this->telefonos[posicion] == telefono) {
			return posicion;
		}

		posicion = (posicion + 1) % this->capacidad;

	} while (posicion != inicio);
	return -1;
}

/*  buscarHueco
	Busca un hueco para introducir un contacto
	Entrada: Telefono del contacto
	Retorno: Posicion del contacto
	Precondicion: Ninguno
	Complejidad Temporal: T(n) = n+1, O(n)
	Complejidad Espacial: M(n) = 1, O(1)
*/

int Agenda::buscarHueco(long telefono) {
	int posicion = this->obtenerPosicion(telefono);
	while (this->ocupada[posicion] && !this->borradas[posicion]) {
		posicion = (posicion+1) % this->capacidad;
	}
	return posicion;
}

/*  isLlena
	Comprueba si la lista es llena
	Entrada: Ninguna
	Retorno: True si esta llena, False no esta llena
	Precondicion: Ninguna
	Complejidad Temporal: T(n) = n+1, O(n)
	Complejidad Espacial: M(n) = 1, O(1)
*/

bool Agenda::isLlena() {
	bool llena = true;

	for (int i = 0; i < this->capacidad; i++) {
		if (!(this->ocupada[i]) || this->borradas[i]) {
			llena = false;
		}
	}

	return llena;
}

/*	introducirContacto
	Introduce un contacto en la agenda
	Entrada: Telefono y nombre del nuevo contacto
	Retorno: Ninguno
	Precondicion: El contacto no puede existir ya en la agenda y la agenda no puede estar llena
	Complejidad Temporal: T(n) = 3n + 1, O(n)
	Complejidad Espacial: M(n) = 1, O(1)
*/

void Agenda::introducirContacto (long telefono, string contacto) {
	assertdomjudge(!this->isLlena()); //T(n) = n
	assertdomjudge(!this->existeContacto(telefono)); //T(n) = n

	int posicion = this->buscarHueco(telefono); //T(n) = n;
	this->nombres[posicion] = contacto;
	this->telefonos[posicion] = telefono;
	this->ocupada[posicion] = true;
	this->borradas[posicion] = false;
}

/*	eliminarContacto
	Elimina un contacto de la agenda
	Entrada: El telefono del contacto
	Retorno: Ninguna
	Precondicion: El contacto ha de existir
	Complejidad Temporal: T(n) = 2n + 1 , O(n)
	Complejidad Espacial: M(n) = 1, O(1)
*/

void Agenda::eliminarContacto (long telefono) {
	assertdomjudge(this->existeContacto(telefono));
	int posicion = this->buscarContacto(telefono);
	this->ocupada[posicion] = false;
	this->borradas[posicion] = true;
	
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
	delete[] this->borradas;
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
		cout << "Posicion " << i << " | Vacia: " << !ocupada[i] <<" | Borrada: " << borradas[i] << " | Telefono: " << telefonos[i] << " | Nombre: " << nombres[i] << endl;
	}
}