#include "../assertdomjudge.h"
#include "Cola.h"

Cola::Cola() {
    this->principio = nullptr;
    this->final = nullptr;
}

Cola::~Cola() {
    do {
        this->desencolar();
    } while (this->final != nullptr);
}

void Cola::encolar(int num) {
    Nodo* nodoAEncolar = new Nodo{num,nullptr};
    if (this->estaVacia()) {
        this->principio = nodoAEncolar;
    } else {
        this->final->siguiente = nodoAEncolar;
    }
    this->final = nodoAEncolar;
}

int Cola::desencolar() {
    assertdomjudge(!this->estaVacia());
    Nodo* nodoADesencolar = this->principio;
    int valor = nodoADesencolar->valor;
    this->principio = this->principio->siguiente;
    if (this->principio == nullptr) {
        this->final = nullptr;
    }
    delete nodoADesencolar;
    return valor;
}

bool Cola::estaVacia() {
    return this->principio == nullptr;
}

void Cola::imprimirCola() {
    if (this->estaVacia()) {
        std::cout << "Cola Vacia" << std::endl;
    } else {
        Nodo* nodo = this->principio;
        while (nodo != nullptr) {
            std::cout << nodo->valor << " ";
            nodo = nodo->siguiente;
        }
        std::cout << std::endl;
    }
}