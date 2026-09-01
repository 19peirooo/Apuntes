
#include "Cola.h"
#include <iostream>

int main() {
    Cola* cola = new Cola();
    std::cout << cola->estaVacia() << std::endl;
    cola->encolar(1);
    cola->encolar(2);
    cola->encolar(3);
    cola->imprimirCola();
    cola->desencolar();
    cola->imprimirCola();
    std::cout << cola->estaVacia() << std::endl;
}