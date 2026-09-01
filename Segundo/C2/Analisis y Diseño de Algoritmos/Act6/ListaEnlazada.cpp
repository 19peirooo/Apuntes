#include "ListaEnlazada.h"
#include "assertdomjudge.h"

/*  getNodo
    Devuelve el nodo en una posicion
    Entrada: Posicion en la lista
    Retorno: nodo en esa posicion
    Precondicion: Posicion en la lista
    Complejidad Temporal: T(n) = n + 1 , O(n)
    Complejidad Espacial: M(n) = 1 , O(1)
*/

Nodo* ListaEnlazada:: getNodo(int posicion) {
    assertdomjudge(posicion >= 0 && posicion < this->n);
    Nodo* nodo = this->lista;
    for (int i = 0; i < posicion; i++) {
        nodo = nodo->siguienteNodo;
    }
    return nodo;
}

/*  Constructor
    Entrada: Ninguna
    Retorno: Ninguno
    Precondicion: Ninguna
    Complejidad Temporal: T(n) = 1 , O(1)
    Complejidad Espacial: M(n) = 1 , O(1)
*/

ListaEnlazada::ListaEnlazada(){
    this->n = 0;
    this->lista = nullptr;
}

/*  getValor
    Devuelve el valor en una posicion concreta
    Entrada: Posicion del valor
    Retorno: Valor en esa posicion
    Precondicion: Posicion en la lista
    Complejidad Temporal: T(n) = n + 1 , O(n)
    Complejidad Espacial: M(n) = 1 , O(1)
*/

int ListaEnlazada::getValor(int posicion){
    assertdomjudge(posicion >= 0 && posicion < this->n);
    Nodo* nodo = this->getNodo(posicion);
    return nodo->elemento;
}

/*  setValor
    Cambia el valor de una posicion especifica
    Entrada: Posicion y nuevo valor
    Retorno: Ninguno
    Precondicion: Posicion en la lista
    Complejidad Temporal: T(n) = n + 1 , O(n)
    Complejidad Espacial: M(n) = 1 , O(1)
*/

void ListaEnlazada::setValor(int posicion, int nuevoValor){
    assertdomjudge(posicion >= 0 && posicion < this->n);
    Nodo* nodo = this->getNodo(posicion);
    nodo->elemento = nuevoValor;
}

/*  getN
    Devuelve la cantidad de elementos en la lista
    Entrada: Ninguna
    Retorno: Cantidad de elementos en la lista
    Precondicion: Ninguna
    Complejidad Temporal: T(n) = 1 , O(1)
    Complejidad Espacial: M(n) = 1 , O(1)
*/

int ListaEnlazada::getN() {
    return this->n;
}

/*  insertar
    Inserta un valor en una posicion en la lista
    Entrada: Posicion y nuevo valor
    Retorno: Ninguno
    Precondicion: Posicion en la lista
    Complejidad Temporal: T(n) = n + 1 , O(n)
    Complejidad Espacial: M(n) = 1 , O(1)
*/

void ListaEnlazada::insertar (int posicion, int nuevoValor) {
    assertdomjudge(posicion >= 0 && posicion <= this->n);
    Nodo* nodo = new Nodo{nuevoValor,nullptr};
    if (posicion == 0) { //T(n) = 1
        nodo->siguienteNodo = this->lista;
        this->lista = nodo;
    } else { //T(n) = n - 1 + 1 = n
        Nodo* nodoAnterior = this->getNodo(posicion-1);
        nodo->siguienteNodo = nodoAnterior->siguienteNodo;
        nodoAnterior->siguienteNodo = nodo;
    }
    this->n++;
    
}

/*  eliminar
    elimina un valor de la lista y la ajusta para que todos los nodos vuelvan a esta conectados
    Entrada: Posicion del nodo a eliminar
    Retorno: Ninguno
    Precondicion: Posicion en la lista
    Complejidad Temporal: T(n) = 2n + 1 , O(n)
    Complejidad Espacial: M(n) = 1 , O(1)
*/

void ListaEnlazada::eliminar (int posicion) {
    assertdomjudge(posicion >= 0 && posicion < this->n);
    Nodo* nodoEliminado = this->getNodo(posicion); // /T(n) = n + 1
    if (posicion != 0) {
        Nodo* anterior = this->getNodo(posicion - 1); //T(n) n - 1 + 1 
        anterior->siguienteNodo = nodoEliminado->siguienteNodo;
    } else {
        this->lista = nodoEliminado->siguienteNodo;
    }
    delete nodoEliminado;
    this->n--;
}

/*  concatenar
    Concatena 2 listas
    Entrada: Lista a concatenar
    Retorno: Ninguno
    Precondicion: Lista a concatenar no puede ser vacia
    Complejidad Temporal: T(n) = n + 1, O(n)
    Complejidad Espacial: M(n) = 1 , O(1)
*/

void ListaEnlazada::concatenar(ListaEnlazada *listaAConcatenar){
    assertdomjudge(listaAConcatenar != nullptr);
    if (this->lista == nullptr){
        this->lista = listaAConcatenar->lista;
    } else {
        Nodo* ultimoNodo = this->lista;
        while (ultimoNodo->siguienteNodo != nullptr) { //T(n) = n + 1
            ultimoNodo = ultimoNodo->siguienteNodo;
        }
        ultimoNodo->siguienteNodo = listaAConcatenar->lista;
    }
    this->n += listaAConcatenar->n;
}

/*  buscar
    busca un elemento en la lista
    Entrada: elemento a buscar
    Retorno: posicion del elemento. -1 si no se encuentra
    Precondicion: Lista no vacia
    Complejidad Temporal: T(n) = n + 1 , O(1)
    Complejidad Espacial: M(n) = 1 , O(1)
*/

int ListaEnlazada::buscar(int elementoABuscar) {
    assertdomjudge(this->lista != nullptr)  
    int posicion = -1;
    bool encontrado = false;
    int i = 0;
    Nodo* nodoABuscar = this->lista;
    while (!encontrado && i < this->n) {
        if (nodoABuscar->elemento == elementoABuscar) {
            posicion = i;
            encontrado= true;
        } else {
            nodoABuscar = nodoABuscar->siguienteNodo;
            i++;
        }
        
    }
    return posicion;
}

/*  destructor
    Destructor --> Libera la memoria gastada
    Entrada: Ninguna
    Retorno: Ninguno
    Precondicion: Ninguna
    Complejidad Temporal: T(n) = n + 1, O(n)
    Complejidad Espacial: M(n) = 1 , O(1)
*/

ListaEnlazada::~ListaEnlazada() {
    while (this->lista != nullptr) {
        Nodo* nodoEliminado = this->lista;
        this->lista = lista->siguienteNodo;
        delete this->lista;
    }
}