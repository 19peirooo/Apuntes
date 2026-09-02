#include "ListaEnlazada.h"
#include<stdlib.h>
#include <iostream>
using namespace std;

Nodo * ListaEnlazada::getNodo (int posicion) {
	assertdomjudge(lista != nullptr && posicion >= 0 && posicion < this->n);
	Nodo* nodo = this->lista;
	for (int i = 0; i < posicion; i++) { //Me desplazo de nodo en nodo hasta llegar al nodo a buscar
		nodo = nodo->siguienteNodo;
	}
	return nodo;
}

ListaEnlazada::ListaEnlazada() {
	this->lista = nullptr;
	this->n = 0;
}

Licencia ListaEnlazada::getValor(int posicion) {
	return this->getNodo(posicion)->elemento; //Accedo al elemento de nodo en dicha posicion
}

void ListaEnlazada::setValor(int posicion, Licencia nuevoValor) {
	this->getNodo(posicion)->elemento = nuevoValor; //Cambio el elemento del nodo en dicha posicion
}

int ListaEnlazada::getN() {
	return this->n; //Devuelvo en numero de elementos en la lista enlazada
}

void ListaEnlazada::insertar (int posicion, Licencia nuevoValor) {
	Nodo* nodo = new Nodo();
	nodo->elemento = nuevoValor;
	nodo->siguienteNodo = nullptr;
	
	if (posicion == 0) { //Si en la posicion el primera, he de actualizar el valor de la variable lista
		if (this->n != 0) { //Si no es el primer elemento que se introduce a la lista por primera vez, apunto a que ahora es el segundo nodo
			nodo->siguienteNodo = this->lista;
		}
		this->lista = nodo;
	} else {
		Nodo* anterior = this->getNodo(posicion-1); //Accedo al nodo anterior para que ahora apunte a al nuevoNodo
		nodo->siguienteNodo = anterior->siguienteNodo; //El nuevo nodo a de apuntar a el nodo que esta despues de el
		anterior->siguienteNodo = nodo;
	}
	this->n++;
}


void ListaEnlazada::eliminar (int posicion) {
	Nodo* nodo = this->getNodo(posicion);
	if (n == 1) { //Si solo tengo un elemento en la lista. Lo elimino
		this->lista = nullptr;
	} else if (posicion == 0) {
		this->lista = this->lista->siguienteNodo; //Si es el primer nodo --> He de actualizar el valor del atributo lista para que sea el segundo nodo
	} else {
		Nodo* anterior = this->getNodo(posicion-1);
		anterior->siguienteNodo = nodo->siguienteNodo; //Actualizo el nodo anterior para que apunte al siguente nodo
	}
	delete nodo;
	this->n--;
}

int ListaEnlazada::buscar(Licencia elementoABuscar) {
	Nodo* nodoABuscar = this->lista;
	for (int i = 0; i < this->n; i++) {
		if (nodoABuscar->elemento.codigo == elementoABuscar.codigo) { //Busco el nodo hasta encontrarlo, comparo por codigos y devuelvo su posicion
			return i;
		}
		nodoABuscar= nodoABuscar->siguienteNodo;
	}
	return -1; //Devuelvo -1 si no lo encuentro
}

void ListaEnlazada::imprimir(){

	cout << "n=" << this->n << " | contenido=";
	Nodo* nodoActual = this->lista;
	for(int i = 0; i < this->n; i++){
		cout << "(" << nodoActual->elemento.codigo << ", " << nodoActual->elemento.herramienta << ") ";
		nodoActual = nodoActual->siguienteNodo;
	} 
	cout << endl;
}

//Voy eliminando todos los nodos de la lista
ListaEnlazada::~ListaEnlazada() {
	while (this->n > 0) {
		this->eliminar(0);
	}
}


