#include "Cola.h"
#include "assertdomjudge.h"

/*  Constructor
    Constructor de la cola
    Entrada: Ninguna
    Retorno: Ninguna
    Precondicion: Ninguna
    Complejidad Temporal: T(n) = 1, O(1)
    Complejidad Espacial: M(n) = 1, O(1)
*/

Cola::Cola() {
    this->principio = nullptr;
    this->final = nullptr;
}

/*  encolar
    Inserta un valor al final de la cola
    Entrada: Numero a encolar
    Retorno: Ninguna
    Precondicion: Ninguna
    Complejidad Temporal: T(n) = 1, O(1)
    Complejidad Espacial: M(n) = 1, O(1)
*/

void Cola::encolar(int num) {
    Nodo* nuevoNodo = new Nodo(num,nullptr);
    if (this->estaVacia()) {
        this->principio = nuevoNodo;
    } else {
        this->final->siguiente = nuevoNodo;
    }
    this->final = nuevoNodo;
}

/*  desencolar
    Desencola un valor del prinicipio de la listas
    Entrada: Posicion donde se insertar el valor
    Retorno: valor del nodo desencolado
    Precondicion: La lista no esta vacia
    Complejidad Temporal: T(n) = 1, O(1)
    Complejidad Espacial: M(n) = 1, O(1)
*/

int Cola::desencolar() {
    int num = this->principio->valor;
    assertdomjudge(!(this->estaVacia()));
    Nodo* nodoEliminado = this->principio;
    this->principio = this->principio->siguiente;
    delete nodoEliminado;
    return num;
}

/*  estaVacia
    Comprueba si la lista esta vacia o no
    Entrada: Ninguna
    Retorno: true o false en funcion de si esta vacia o no
    Precondicion: Ninguna
    Complejidad Temporal: T(n) = 1, O(1)
    Complejidad Espacial: M(n) = 1, O(1)
*/

bool Cola::estaVacia() {
    return this->principio == nullptr;
} 

/*  Destructor
    Vacia la cola y elimina los nodos
    Entrada: Ninguna
    Retorno: Ninguna
    Precondicion: Ninguna
    Complejidad Temporal: T(n) = n + 1, O(n)
    Complejidad Espacial: M(n) = 1, O(1)
*/

Cola::~Cola(){
    while (this->principio != nullptr) {
        Nodo* nodoEliminado = this->principio;
        this->principio = this->principio->siguiente;
        delete nodoEliminado;
    }
}