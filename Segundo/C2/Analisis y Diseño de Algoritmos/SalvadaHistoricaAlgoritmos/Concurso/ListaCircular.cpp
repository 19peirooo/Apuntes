#include "ListaCircular.h"

ListaCircular::ListaCircular() {
    this->lista = nullptr;
    this->n = 0;
}

ListaCircular::~ListaCircular() {
    while (this->n > 0) {
        this->eliminar(0);
    }
}

Nodo* ListaCircular::getNodo(int pos) {
    assertdomjudge(this->lista != nullptr && pos >= 0 && pos < this->n);
    Nodo* nodo = this->lista;
    if (pos > this->n/2) {
        for (int i = this->n-1; i > pos; i--) {
            nodo = nodo->anterior;
        }
    } else {
        for (int i = 0; i < pos; i++) {
            nodo = nodo->siguiente;
        }
    }
    return nodo;
}

int ListaCircular::getN() {
    return this->n;
}

int ListaCircular::getValor(int pos) {
    return this->getNodo(pos)->valor;
}
void ListaCircular::setValor(int pos, int nuevoValor) {
    this->getNodo(pos)->valor = nuevoValor;
}

void ListaCircular::introducir(int pos, int valor) {
    assertdomjudge(pos >= 0 && pos <= this->n);
    Nodo* anterior;
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->valor = valor;
    nuevoNodo->siguiente = nuevoNodo;
    nuevoNodo->anterior = nuevoNodo;

    if (pos == 0) {
        if (n != 0) {
            anterior = this->lista->anterior;
            nuevoNodo->siguiente = this->lista;
            nuevoNodo->anterior = this->lista->anterior;
            anterior->siguiente = nuevoNodo;
            this->lista->anterior = nuevoNodo;
        }
        this->lista = nuevoNodo;
    } else {
        anterior = this->getNodo(pos-1);
        nuevoNodo->siguiente = anterior->siguiente;
        anterior->siguiente->anterior = nuevoNodo;
        anterior->siguiente = nuevoNodo;
        nuevoNodo->anterior = anterior;
    }
    this->n++;
}
int ListaCircular::eliminar(int pos) {
    Nodo* nodoAEliminar = this->getNodo(pos);
    Nodo* anterior;
    Nodo* siguiente;
    int valorAEliminar = nodoAEliminar->valor;

    if (n == 1) {
        this->lista = nullptr;
    } else {
        anterior = nodoAEliminar->anterior;
        siguiente = nodoAEliminar->siguiente;
        anterior->siguiente = nodoAEliminar->siguiente;
        siguiente->anterior = nodoAEliminar->anterior;
        if (pos == 0) {
            this->lista = siguiente;
        }
    }

    delete nodoAEliminar;
    this->n--;
    return valorAEliminar;
}