#include "../assertdomjudge.h"
#include "ListaCircular.h"

Nodo* ListaCircular::getNodo(int pos) {
    assertdomjudge(pos >= 0 && pos < this->n);
    Nodo* nodoABuscar = this->principio;

    if (pos > n/2) {
        nodoABuscar = nodoABuscar->nodoAnterior; 
        for (int i = this->n-1; i > pos; i--) {
            nodoABuscar = nodoABuscar->nodoAnterior;
        }
    } else {
        for (int i = 0; i < pos; i++) {
            nodoABuscar = nodoABuscar->siguienteNodo;
        }
    }

    return nodoABuscar;
}

ListaCircular::ListaCircular() {
    this->n = 0;
    this->principio = nullptr;
}

ListaCircular::~ListaCircular() {
   
    while (this->principio != nullptr) {
        this->eliminar(0);
    }
}

int ListaCircular::getValor(int pos) {
    assertdomjudge(pos >= 0 && pos < this->n);
    return this->getNodo(pos)->elemento;
}

void ListaCircular::setValor(int pos, int val) {
    assertdomjudge(pos >= 0 && pos < this->n);
    this->getNodo(pos)->elemento = val;
}

int ListaCircular::getN() {
    return this->n;
}

void ListaCircular::insertar(int pos, int val) {
    assertdomjudge(pos >= 0 && pos <= this->n);
    Nodo* nodoNuevo = new Nodo;
    nodoNuevo->elemento = val;
    nodoNuevo->siguienteNodo = nullptr;
    nodoNuevo->nodoAnterior = nullptr;
    if (pos == 0) {
        if (this->n != 0) {
            nodoNuevo->siguienteNodo = this->principio;
            this->principio->nodoAnterior = nodoNuevo;
        } 
        this->principio = nodoNuevo;
    } else {
        Nodo* nodoAnterior = this->getNodo(pos-1);
        nodoNuevo->siguienteNodo = nodoAnterior->siguienteNodo;
        if (nodoAnterior->siguienteNodo != nullptr) {
            nodoAnterior->siguienteNodo->nodoAnterior = nodoNuevo;
        } 
        nodoAnterior->siguienteNodo = nodoNuevo;
    }
    this->n++;
}

void ListaCircular::eliminar(int pos) {
    assertdomjudge(pos >= 0 && pos < this->n);
    Nodo* nodoAEliminar;
    if (pos == 0) {
        nodoAEliminar = this->principio;
        this->principio = this->principio->siguienteNodo;
        if (this->principio != nullptr) {
            this->principio->nodoAnterior = nullptr;
        } else {
            this->final = nullptr;  // La lista queda vacía
        }
    } else if (pos == this->n-1){
        nodoAEliminar = this->final;
        this->final->nodoAnterior->siguienteNodo = nullptr;
        this->final = this->final->nodoAnterior;
    } else {
        Nodo* nodoAnterior = this->getNodo(pos-1);
        nodoAEliminar = this->getNodo(pos);
        nodoAnterior->siguienteNodo = nodoAEliminar->siguienteNodo;
        nodoAEliminar->siguienteNodo->nodoAnterior = nodoAnterior;
    }
    delete nodoAEliminar;
    this->n--;
}

int ListaCircular::buscar(int val) {
    for (int i = 0; i < this->n; i++) {
        if (this->getValor(i) == val) {
            return i;
        }
    }
    return -1;
}