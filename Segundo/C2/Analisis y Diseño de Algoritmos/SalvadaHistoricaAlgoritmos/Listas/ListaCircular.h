#include "NodoDoble.h"

class ListaCircular {
    private:
        int n;
        Nodo* principio;
        Nodo* getNodo(int pos);
    public:
        ListaCircular();
        ~ListaCircular();
        int getValor(int pos);
        void setValor(int pos, int val);
        int getN();
        void insertar(int pos, int val);
        void eliminar(int pos);
        int buscar(int val);
};