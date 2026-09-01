#include "ColaPrioridad.h"

int main() {
    ColaPrioridad* cola = new ColaPrioridad();
    cola->encolar(3);
    cola->encolar(2);
    cola->encolar(1);
    cola->encolar(5);
    cola->encolar(6);
    cola->encolar(4);
    cola->imprimirCola();
    cola->desencolar();
    cola->imprimirCola();
}
