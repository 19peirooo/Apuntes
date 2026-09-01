#include "../assertdomjudge.h"
using namespace std;
#include "Nodo.h"

class ListaCircular {
    private:
        Nodo* lista; //Nodo inicio lista
        int n; //Num Elementos
        Nodo* getNodo(int pos);
    public:
        ListaCircular();
        ~ListaCircular();
        int getN();
        int getValor(int pos);
        void setValor(int pos, int nuevoValor);
        void introducir(int pos, int valor);
        int eliminar(int pos);
};