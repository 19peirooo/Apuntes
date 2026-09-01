#include "DispersionAbierta.h"

int Hash::obtenerPosicion(long clave) {
    return clave % this->capacidad;
}

Hash::Hash(int capacidad) {
    this->capacidad = capacidad;
    this->n = 0;
    this->tabla = new ListaEnlazada[capacidad];
}

Hash::~Hash() {
    for (int i = 0; i < capacidad; i++) {
        tabla[i].~ListaEnlazada();
    }
    delete[] tabla;
    
}

bool Hash::existeValor(long clave) {
    int pos = this->obtenerPosicion(clave);
    Tupla tupla;
    tupla.clave = clave;
    return this->tabla[pos].buscar(tupla) != -1;
}

string Hash::getValor(long clave) {
    assertdomjudge(this->existeValor(clave));
    int pos = this->obtenerPosicion(clave);
    Tupla tupla;
    tupla.clave = clave;
    return this->tabla[pos].getValor(this->tabla[pos].buscar(tupla)).valor;

}

void Hash::introducir(long clave, string valor) {
    assertdomjudge(!this->existeValor(clave));
    int pos = this->obtenerPosicion(clave);
    Tupla tupla;
    tupla.clave = clave;
    tupla.valor = valor;
    this->tabla[pos].insertar(0,tupla);
    this->n++;
}

void Hash::eliminar(long clave) {
    assertdomjudge(this->existeValor(clave));
    int pos = this->obtenerPosicion(clave);
    Tupla tupla;
    tupla.clave = clave;
    int posEnLista = this->tabla[pos].buscar(tupla);
    this->tabla[pos].eliminar(posEnLista);
    this->n--;
}

void Hash::imprimirTabla() {
    for (int i=0; i<capacidad; i++) { //T(n) = n
		cout << "Posicion " << i << ": ";
		imprimirListaEnlazada(&this->tabla[i]); //T(n) = m
	}
}