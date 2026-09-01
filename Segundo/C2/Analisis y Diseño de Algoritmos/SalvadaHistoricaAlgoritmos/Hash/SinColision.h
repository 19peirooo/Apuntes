#include <iostream>
#include <string>
#include "../assertdomjudge.h"
using namespace std;

class Hash {
    private:
        int capacidad;
        string *valores;
        long* claves;
        bool* ocupada;
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