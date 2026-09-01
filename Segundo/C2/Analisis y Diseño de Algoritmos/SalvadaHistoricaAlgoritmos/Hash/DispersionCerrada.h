#include <iostream>
#include <string>
#include "../assertdomjudge.h"
using namespace std;

class Hash {
    private:
        int capacidad;
        int n;
        string *valores;
        long* claves;
        bool* vacias;
        bool* borradas;
        int obtenerPosicion(long clave);
    public:
        Hash(int capacidad);
        ~Hash();
        int buscar(long clave); //Posicion de una clave --> -1 si no la encuentra
        int buscarHueco(long clave);
        bool isLlena();
        bool existeValor(long clave);
        string getValor(long clave);
        void introducir(long clave, string valor);
        void eliminar(long clave);
        void imprimirTabla();
};