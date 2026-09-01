#include "AgendaAbierta.h"
#include "ListaEnlazada.h"
#include "assertdomjudge.h"
#include <iostream>
#include "impresionListasEnlazadas.h" // Para el m�todo imprimir de la tabla hash

using namespace std;

// n -> Tamaño de la lista enlazada
// m -> Tamaño de la sublista enlazada en una posicion

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
	Complejidad Temporal: T(n) = n + 1, O(n)
	Complejidad Espacial: M(n) = n + 1, O(n)
*/

Agenda::Agenda(int capacidad) {
	this->capacidad = capacidad;
	this->n = 0;
	this->tabla = new ListaEnlazada[capacidad];
}

/* 	Comprueba si existe un contacto
	Entrada: Telefono del contacto
	Retorno: True si existe, false si no existe
	Precondicion: Ninguna
	Complejidad Temporal: T(n) = m + 1, O(m)
	Complejidad Espacial: M(n) = 1, O(1)
*/

bool Agenda::existeContacto (long telefono) {
	int posicion = this->obtenerPosicion(telefono); //O(1)
	Contacto contactoABuscar;
	contactoABuscar.telefono = telefono;
	return this->tabla[posicion].buscar(contactoABuscar) != -1; //O(m)
}

/*  getContacto
	Devuelve el nombre del contacto
	Entrada: Telefono del contacto
	Retorno: Nombre del contacto
	Precondicion: El contacto ha de existir
	Complejidad Temporal: T(n) = n + 2m + 1, O(n+m)
	Complejidad Espacial: M(n) = 1, O(1)
*/

string Agenda::getContacto (long telefono) {
	assertdomjudge(this->existeContacto(telefono)); //T(n) = O(n), M(n) = 1
	int posicion = this->obtenerPosicion(telefono);
	Contacto contactoABuscar;
	contactoABuscar.telefono = telefono;
	return this->tabla[posicion].getValor(this->tabla[posicion].buscar(contactoABuscar)).nombre; //T(n) = O(n) + O(n) = 2m + 1
}

/*	introducirContacto
	Introduce un contacto en la agenda
	Entrada: Telefono y nombre del nuevo contacto
	Retorno: Ninguno
	Precondicion: El contacto no puede existir ya en la agenda
	Complejidad Temporal: T(n) = n + 1, O(n)
	Complejidad Espacial: M(n) = 1, O(1)
*/

void Agenda::introducirContacto (long telefono, string contacto) {
	assertdomjudge(!this->existeContacto(telefono)); //T(n) = n + 1
	Contacto nuevoContacto;
	nuevoContacto.telefono = telefono;
	nuevoContacto.nombre = contacto;
	int posicion = this->obtenerPosicion(telefono); //T(n) = 1
	this->tabla[posicion].insertar(0,nuevoContacto); //T(n) = 1
}

/*	eliminarContacto
	Elimina un contacto de la agenda
	Entrada: Contacto de la agenda
	Retorno: Ninguna
	Precondicion: El contacto ha de existir
	Complejidad Temporal: T(n) = n + 2m + 1 , O(n + m)
	Complejidad Espacial: M(n) = 1, O(1)
*/

void Agenda::eliminarContacto (long telefono) {
	assertdomjudge(this->existeContacto(telefono)); //T(n) = n
	Contacto contactoAEliminar;
	contactoAEliminar.telefono = telefono;
	int posicion = this->obtenerPosicion(telefono); //T(n) = 1
	this->tabla[posicion].eliminar(this->tabla[posicion].buscar(contactoAEliminar)); //T(n) = 2m + 1
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
	delete[] this->tabla;
}

/* 	imprimir
	Imprime la lista de lista
	Entrada: Ninguna
	Retorno: Ninguno
	Precondicion: Ninguna
	Complejidad Temporal: T(n) = nm + 1, O(nm)
	Complejidad Espacial: M(n) = 1, O(1)
*/

void Agenda::imprimir() {
	for (int i=0; i<capacidad; i++) { //T(n) = n
		cout << "Posicion " << i << ": ";
		imprimirListaEnlazada(&this->tabla[i]); //T(n) = m
	}
}

