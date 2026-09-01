#include "SinColision.h"

int Hash::obtenerPosicion(long clave) {
    return clave % this->capacidad;
}

Hash::Hash(int capacidad) {
    this->capacidad = capacidad;
    this->claves = new long[capacidad];
    this->valores = new string[capacidad];
    this->ocupada = new bool[capacidad];
    for (int i = 0; i < capacidad; i++) {
        this->ocupada[i] = false;
    }
}

Hash::~Hash() {
    delete[] this->claves;
    delete[] this->valores;
    delete[] this->ocupada;
}

bool Hash::existeValor(long clave) {
    int pos = this->obtenerPosicion(clave);
    return this->ocupada[pos] && this->claves[pos] == clave;
}

string Hash::getValor(long clave) {
    assertdomjudge(this->existeValor(clave));
    return this->valores[this->obtenerPosicion(clave)];

}

void Hash::introducir(long clave, string valor) {
    int pos = this->obtenerPosicion(clave);
    assertdomjudge(!(this->ocupada[pos]));
    this->claves[pos] = clave;
    this->valores[pos] = valor;
    this->ocupada[pos] = true;
}

void Hash::eliminar(long clave) {
    int pos = this->obtenerPosicion(clave);
    assertdomjudge(this->existeValor(clave));
    this->ocupada[pos] = false;
}

void Hash::imprimirTabla() {
    for (int i=0; i<this->capacidad; i++) {
		cout << "Posicion " << i << " | Ocupada: " << this->ocupada[i] << " | Clave: " << this->claves[i] << " | Valor: " << this->valores[i] << endl;
	}    
}