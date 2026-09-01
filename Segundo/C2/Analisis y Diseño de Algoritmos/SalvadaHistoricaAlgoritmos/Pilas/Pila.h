#include "Nodo.h"

class Pila {

    private:
        Nodo* cima;
    public:
        Pila();
        ~Pila();
        void apilar(int num);
        int desapilar();
        bool estaVacia();
        void imprimirPila();
};

