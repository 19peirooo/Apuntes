#include "ListaEnlazada.h"
#include "../assertdomjudge.h"

Nodo* ListaEnlazada:: getNodo(int posicion) {
    assertdomjudge(posicion >= 0 && posicion < this->n);
    Nodo* nodo = this->lista;
    for (int i = 0; i < posicion; i++) {
        nodo = nodo->siguienteNodo;
    }
    return nodo;
}

ListaEnlazada::ListaEnlazada() {
    this->n = 0;
    this->lista = nullptr;
    this->posicionUltimoNodoAccedido = 0;
    this->punteroUltimoNodoAccedido = nullptr;
}

Tupla ListaEnlazada::getValor(int posicion) {
    assertdomjudge(posicion >= 0 && posicion < this->n);
    return this->getNodo(posicion)->elemento;
}

void ListaEnlazada::setValor(int posicion, Tupla nuevoValor) {
    assertdomjudge(posicion >= 0 && posicion < this->n);
    this->getNodo(posicion)->elemento = nuevoValor;
}

int ListaEnlazada::getN() {
    return this->n;
}

void ListaEnlazada::insertar (int posicion, Tupla nuevoValor) {
    assertdomjudge(posicion >= 0 && posicion <= this->n);
    Nodo* nodo = new Nodo{nuevoValor,nullptr,nullptr};
    if (n == 0) {
        this->lista = nodo;
    }
    else if (posicion == 0) { //T(n) = 1
        nodo->siguienteNodo = this->lista;
        this->lista->anteriorNodo = nodo;
        this->lista = nodo;
    } else { //T(n) = n - 1 + 1 = n
        Nodo* nodoAnterior = this->getNodo(posicion-1);
        nodo->siguienteNodo = nodoAnterior->siguienteNodo;
        nodo->anteriorNodo = nodoAnterior;
        nodoAnterior->siguienteNodo = nodo;
        if (nodo->siguienteNodo != nullptr) {
            nodo->siguienteNodo->anteriorNodo = nodo;
        }
    }
    this->n++;
}

void ListaEnlazada::eliminar(int posicion) {
    assertdomjudge(posicion >= 0 && posicion < this->n);

    Nodo* nodoActual = this->getNodo(posicion);

    if (this->n == 1) {
        this->lista = nullptr;
    } else {
        if (nodoActual->anteriorNodo != nullptr) {
            nodoActual->anteriorNodo->siguienteNodo = nodoActual->siguienteNodo;
        }
        if (nodoActual->siguienteNodo != nullptr) {
            nodoActual->siguienteNodo->anteriorNodo = nodoActual->anteriorNodo;
        }
        if (posicion == 0) { 
            this->lista = nodoActual->siguienteNodo;  
        }
    }
    delete nodoActual;
    this->n--;  
}


int ListaEnlazada::buscar(Tupla elementoABuscar) {
    int posicion = -1;
    bool encontrado = false;
    int i = 0;
    Nodo* nodoABuscar = this->lista;
    while (!encontrado && i < this->n) {
        if (nodoABuscar->elemento.clave == elementoABuscar.clave) {
            posicion = i;
            encontrado= true;
        } else {
            nodoABuscar = nodoABuscar->siguienteNodo;
            i++;
        }
        
    }
    return posicion;
}

void ListaEnlazada::concatenar(ListaEnlazada *listaAConcatenar) {
    assertdomjudge(listaAConcatenar != nullptr);
    for (int i = 0; i < listaAConcatenar->n; i++){
        Tupla contactoAIntroducir = listaAConcatenar->getValor(i);
        this->insertar(this->n,contactoAIntroducir);
    }
}

ListaEnlazada::~ListaEnlazada() {
    while (this->lista != nullptr) {
        Nodo* nodoEliminado = this->lista;
        this->lista = lista->siguienteNodo;
        delete nodoEliminado;
    }
}