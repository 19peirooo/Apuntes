#include "Pila.h"
#include "../assertdomjudge.h"

Pila::Pila() {
    this->cima = nullptr;
}

Pila::~Pila() {
    do {
        this->desapilar();
    } while (cima != nullptr);
}

void Pila::apilar(int num) {
    Nodo* nodo = new Nodo{num,nullptr};
    if (!this->estaVacia()) {
        nodo->siguiente = this->cima;
    }
    this->cima = nodo;
}

int Pila::desapilar() {
    assertdomjudge(!this->estaVacia());
    Nodo* nodoDesapilado = this->cima;
    int valor = nodoDesapilado->valor;
    this->cima = this->cima->siguiente;
    delete nodoDesapilado;
    return valor;
}

bool Pila::estaVacia() {
    return this->cima == nullptr;
}

void Pila::imprimirPila() {
    assertdomjudge(!this->estaVacia());
    Nodo* nodo = this->cima;
    while (nodo != nullptr) {
        std::cout << nodo->valor << " ";
        nodo = nodo->siguiente;
    }
    std::cout << std::endl;
}