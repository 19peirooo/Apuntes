#include "ListaCircular.h"
#include "assertdomjudge.h"

/*  getNodo
    Devuelve el nodo en una posicion dada
    Entrada: Posicion de dicho nodo
    Retorno: Nodo en dicha posicion
    Precondicion: Posicion dentro de la lista --> posicion < n
    Complejidad Temporal: T(n) = n + 1, O(n)
    Complejidad Espacial: M(n) = 1, O(1)
*/

Nodo* ListaCircular :: getNodo(int posicion) {
    assertdomjudge(lista != nullptr && posicion >= 0 && posicion < this->n);
    Nodo* nodo = this->lista;

    for (int i = 0; i < posicion; i++) { //T(n) = n + 1
        nodo = nodo->siguienteNodo;
    }
    return nodo;

}

/*  Constructor
    Constructor de la lista circular
    Entrada: Ninguno
    Retorno: Ninguno
    Precondicion: Ninguno
    Complejidad Temporal: T(n) = 1 , O(1)
    Complejidad Espacial: M(n) = n+1, O(1)
*/

ListaCircular::ListaCircular(){
    this->lista = nullptr;
    this->n = 0;
}

/*  getValor
    Devuelve el valor en una posicion dada
    Entrada: Posicion donde se encuentra el valor
    Retorno: Valor del nodo en dicha posicion
    Precondicion: Posicion dentro de la lista --> posicion < n
    Complejidad Temporal: T(n) = n + 1, O(n)
    Complejidad Espacial: M(n) = 1, O(1)
*/

string ListaCircular::getValor(int posicion){
    assertdomjudge(posicion >= 0 && posicion < this->n);
    return this->getNodo(posicion)->elemento;

}

/*  setValor
    Cambia el valor en una posicion dada
    Entrada: Posicion donde se encuentra el valor
    Retorno: Ninguno
    Precondicion: Posicion dentro de la lista --> posicion < n
    Complejidad Temporal: T(n) = n + 1, O(n)
    Complejidad Espacial: M(n) = 1, O(1)
*/

void ListaCircular::setValor(int posicion, string nuevoValor) {
    assertdomjudge(posicion>=0 && posicion<this->n);
    this->getNodo(posicion)->elemento = nuevoValor;
}

/*  getValor
    Devuelve el valor en una posicion dada
    Entrada: Ninguna
    Retorno: Numero de elementos en la lista circular
    Precondicion: Ninguna
    Complejidad Temporal: T(n) = 1, O(1)
    Complejidad Espacial: M(n) = 1, O(1)
*/

int ListaCircular::getN() {
    return this->n;
}

/*  insertar
    Inserta un valor en una posicion de la lista
    Entrada: Posicion donde se insertar el valor
    Retorno: Ninguna
    Precondicion: Posicion dentro de la lista o es el nuevo ultimo elemento --> posicion <= n
    Complejidad Temporal: T(n) = n + 1, O(n)
    Complejidad Espacial: M(n) = 1, O(1)
*/

void ListaCircular::insertar (int posicion, string nuevoValor) {
    assertdomjudge(posicion >= 0 && posicion <= this->n);
    Nodo* nodo = new Nodo{nuevoValor,nullptr,nullptr};
    Nodo* nodoActual = nullptr;
    if (this->n==0) { ///T(n) = 1
        nodo->siguienteNodo = nodo;
        nodo->anteriorNodo = nodo;
        this->lista = nodo;
    } else if (posicion == 0) { 
        nodo->siguienteNodo = this->lista;
        nodo->anteriorNodo = this->lista->anteriorNodo;
        this->lista->anteriorNodo = nodo;
        this->lista->anteriorNodo->siguienteNodo = nodo;
    } else {
        nodoActual = this->getNodo(posicion-1);
        nodo->siguienteNodo = nodoActual->siguienteNodo;
        nodo->anteriorNodo = nodoActual;
        nodo->siguienteNodo->anteriorNodo = nodo;
        nodoActual->siguienteNodo = nodo;
    }

    this->n++;
}

/*  eliminar
    Elimina un valor en una posicion de la lista
    Entrada: Posicion donde se elimina el valor
    Retorno: Ninguna
    Precondicion: Posicion dentro de la lista --> posicion < n
    Complejidad Temporal: T(n) = n + 1, O(n)
    Complejidad Espacial: M(n) = 1, O(1)
*/

void ListaCircular::eliminar(int posicion) {
    assertdomjudge(lista != nullptr && posicion >= 0 && posicion < this->n);
    if (this->n == 1) { //T(n) = 1
        delete this->lista;
        this->lista = nullptr;
    } else { //T(n) = n + 1
        Nodo* nodoActual = nullptr;
        if (posicion == 0) {
            nodoActual = this->lista;
            this->lista->anteriorNodo->siguienteNodo = nodoActual->siguienteNodo;
            this->lista->siguienteNodo->anteriorNodo = nodoActual->anteriorNodo;
            this->lista = this->lista->siguienteNodo;
        } else {
            nodoActual = this->getNodo(posicion);
            nodoActual->anteriorNodo->siguienteNodo = nodoActual->siguienteNodo;
            this->lista->siguienteNodo->anteriorNodo = nodoActual->anteriorNodo;
        }
        delete nodoActual;
    }

    this->n--; 
}

/*  girar
    Girar los elementos de la lista hacia la izquierda o hacia la derecha
    Entrada: Veces que se va a girar. Si -vo hacia la izquierda si +vo hacia la derecha
    Retorno: Ninguna
    Precondicion: Ninguna
    Complejidad Temporal: T(n) = n + 1, O(n)
    Complejidad Espacial: M(n) = 1, O(1)
*/

void ListaCircular::girar (int p) {
    if (p>0) {
        for (int i = 0; i < p; i++) {
            this->lista = this->lista->siguienteNodo;
        }
    } else {
        for (int i = 0; i < -p; i++) {
            this->lista = this->lista->anteriorNodo;
        }
    }
}

/*  Destructor
    Elimina todos los nodos
    Entrada: Ninguna
    Retorno: Ninguno
    Precondicion: Ninguna
    Complejidad Temporal: T(n) = n + 1, O(n)
    Complejidad Espacial: M(n) = 1, O(1)
*/

ListaCircular::~ListaCircular() {
    while (this->n > 0) {
        this->eliminar(0);
    }
}