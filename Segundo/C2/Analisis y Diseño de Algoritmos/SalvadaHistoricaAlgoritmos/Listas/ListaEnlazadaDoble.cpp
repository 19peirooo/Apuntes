#include "../assertdomjudge.h"
#include "ListaEnlazadaDoble.h"

Nodo* ListaEnlazada::getNodo(int pos) {
    assertdomjudge(pos >= 0 && pos < this->n);
    Nodo* nodoABuscar;

    if (pos > n/2) {
        nodoABuscar = this->final;
        for (int i = this->n-1; i > pos; i--) {
            nodoABuscar = nodoABuscar->nodoAnterior;
        }
    } else {
        nodoABuscar = this->principio;
        for (int i = 0; i < pos; i++) {
            nodoABuscar = nodoABuscar->siguienteNodo;
        }
    }

    return nodoABuscar;
}

ListaEnlazada::ListaEnlazada() {
    this->n = 0;
    this->principio = nullptr;
    this->final = nullptr;
}

ListaEnlazada::~ListaEnlazada() {
   
    while (this->principio != nullptr) {
        this->eliminar(0);
    }
}

int ListaEnlazada::getValor(int pos) {
    assertdomjudge(pos >= 0 && pos < this->n);
    return this->getNodo(pos)->elemento;
}

void ListaEnlazada::setValor(int pos, int val) {
    assertdomjudge(pos >= 0 && pos < this->n);
    this->getNodo(pos)->elemento = val;
}

int ListaEnlazada::getN() {
    return this->n;
}

void ListaEnlazada::insertar(int pos, int val) {
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
    if (pos == this->n) {
        this->final = nodoNuevo;
    }
    this->n++;
}

void ListaEnlazada::eliminar(int pos) {
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

void ListaEnlazada::concatenar(ListaEnlazada* lista) {
    assertdomjudge(lista != nullptr);
    Nodo* ultimoNodo;
    if (this->n == 0) {
        this->principio = lista->principio;
        this->final = lista->final;
    } else {
        ultimoNodo = this->final;
        ultimoNodo->siguienteNodo = lista->principio;
        lista->principio->nodoAnterior = ultimoNodo;
    }
    for (int i = 0; i < lista->getN(); i++) {
        this->insertar(this->n,lista->getValor(i));
    }
}

int ListaEnlazada::buscar(int val) {
    for (int i = 0; i < this->n; i++) {
        if (this->getValor(i) == val) {
            return i;
        }
    }
    return -1;
}