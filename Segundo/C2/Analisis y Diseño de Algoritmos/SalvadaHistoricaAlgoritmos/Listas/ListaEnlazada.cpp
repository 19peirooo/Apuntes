#include "../assertdomjudge.h"
#include "ListaEnlazada.h"

Nodo* ListaEnlazada::getNodo(int pos) {
    assertdomjudge(pos >= 0 && pos < this->n);
    Nodo* nodoABuscar = this->lista;
    for (int i = 0; i < pos; i++) {
        nodoABuscar = nodoABuscar->siguienteNodo;
    }
    return nodoABuscar;
}

ListaEnlazada::ListaEnlazada() {
    this->n = 0;
    this->lista = nullptr;
}

ListaEnlazada::~ListaEnlazada() {
   
    while (this->lista != nullptr) {
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
    if (pos == 0) {
        if (this->n != 0) {
            nodoNuevo->siguienteNodo = this->lista;
        }
        this->lista = nodoNuevo;
    } else {
        Nodo* nodoAnterior = this->getNodo(pos-1);
        nodoNuevo->siguienteNodo = nodoAnterior->siguienteNodo;
        nodoAnterior->siguienteNodo = nodoNuevo;
    }
    this->n++;
}

void ListaEnlazada::eliminar(int pos) {
    assertdomjudge(pos >= 0 && pos < this->n);
    Nodo* nodoAEliminar;
    if (pos == 0) {
        nodoAEliminar = this->lista;
        this->lista = this->lista->siguienteNodo;
    } else {
        Nodo* nodoAnterior = this->getNodo(pos-1);
        nodoAEliminar = this->getNodo(pos);
        nodoAnterior->siguienteNodo = nodoAEliminar->siguienteNodo;
    }
    delete nodoAEliminar;
    this->n--;
}

void ListaEnlazada::concatenar(ListaEnlazada* lista) {
    assertdomjudge(lista != nullptr);
    Nodo* ultimoNodo;
    if (this->n == 0) {
        this->lista = lista->lista;
    } else {
        ultimoNodo = this->getNodo(this->n - 1);
        ultimoNodo->siguienteNodo = lista->lista;
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