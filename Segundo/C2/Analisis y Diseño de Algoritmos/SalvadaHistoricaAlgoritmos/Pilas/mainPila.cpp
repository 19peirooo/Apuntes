#include "Pila.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    Pila* pila = new Pila();
    cout << pila->estaVacia() << endl;
    pila->apilar(1);
    pila->apilar(2);
    pila->apilar(3);
    pila->imprimirPila();
    pila->desapilar();
    pila->imprimirPila();
    cout << pila->estaVacia() << endl;
    return 0;
}
