#include "NodoDoble.h"

class ListaEnlazada {
    private:
        int n;
        Nodo* principio;
        Nodo* final;
        Nodo* getNodo(int pos);
    public:
        ListaEnlazada();
        ~ListaEnlazada();
        int getValor(int pos);
        void setValor(int pos, int val);
        int getN();
        void insertar(int pos, int val);
        void eliminar(int pos);
        void concatenar(ListaEnlazada* lista);
        int buscar(int val);
};