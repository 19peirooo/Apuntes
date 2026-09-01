#include "Nodo.h"

class Cola {
    private: 
        Nodo* principio;
        Nodo* final;
    
    public:
        Cola();
        ~Cola();
        void encolar(int num);
        int desencolar();
        bool estaVacia();
        void imprimirCola();
};