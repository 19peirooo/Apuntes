#include "DispersionCerrada.h"

int Hash::obtenerPosicion(long clave) {
    return clave % this->capacidad;
}

Hash::Hash(int capacidad) {
    this->capacidad = capacidad;
    this->claves = new long[capacidad];
    this->valores = new string[capacidad];
    this->vacias = new bool[capacidad];
    this->borradas = new bool[capacidad];
    this->n = 0;
    for (int i = 0; i < capacidad; i++) {
        this->borradas[i] = false;
        this->vacias[i] = true;
    }
}

Hash::~Hash() {
    delete[] this->claves;
    delete[] this->valores;
    delete[] this->vacias;
    delete[] this->borradas;
}

int Hash::buscar(long clave) {
    int pos = this->obtenerPosicion(clave);
    int inicio = pos;

    do {

        if (this->vacias[pos] && !this->borradas[pos]) {
            return -1;
        }

        if (!this->vacias[pos] && this->claves[pos] == clave) {
            return pos;
        } 

        pos = (pos+1) % this->capacidad;

    } while (pos != inicio);
    return -1;
}

int Hash::buscarHueco(long clave) {
    int pos = this->obtenerPosicion(clave);
    while (!this->vacias[pos] && !this->borradas[pos]) {
        pos = (pos+1) % this->capacidad;
    }
    return pos;
}

bool Hash::isLlena() {
    bool llena = true;

    for (int i = 0; i < this->capacidad; i++) {
        if (this->vacias[i] || this->borradas[i]) {
            llena = false;
        }
    }
    return llena;
}

bool Hash::existeValor(long clave) {
    return this->buscar(clave) != -1;
}

string Hash::getValor(long clave) {
    assertdomjudge(this->existeValor(clave));
    return this->valores[this->buscar(clave)];
}

void Hash::introducir(long clave, string valor) {
    assertdomjudge(!this->isLlena());
    assertdomjudge(!this->existeValor(clave));

    int pos = this->buscarHueco(clave);
    this->claves[pos] = clave;
    this->valores[pos] = valor;
    this->borradas[pos] = false;
    this->vacias[pos] = false;
    this->n++;
}

void Hash::eliminar(long clave) {
    assertdomjudge(this->existeValor(clave));
    int pos = this->buscar(clave);
    this->borradas[pos] = true;
    this->vacias[pos] = true;
    this->n--;
}

void Hash::imprimirTabla() {
    for (int i=0; i<this->capacidad; i++) {
		cout << "Posicion " << i << " | Vacia: " << this->vacias[i] << " | Borrada: " << this->borradas[i] <<" | Clave: " << this->claves[i] << " | Valor: " << this->valores[i] << endl;
	}    
}