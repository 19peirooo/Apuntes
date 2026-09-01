#include <iostream>
#include <string>
#include "../assertdomjudge.h"
#include "ListaEnlazada.h"
#include "impresionListasEnlazadas.h"
using namespace std;

class Hash {
    private:
        int capacidad;
        int n;
        ListaEnlazada* tabla;
        int obtenerPosicion(long clave);
    public:
        Hash(int capacidad);
        ~Hash();
        bool existeValor(long clave);
        string getValor(long clave);
        void introducir(long clave, string valor);
        void eliminar(long clave);
        void imprimirTabla();
};