#include <iostream>
#include "../assertdomjudge.h"
#include "ListaContigua.h"

ListaContigua::ListaContigua(int incremento){
    this->cap = 0;
    this->inc = incremento;
    this->n = 0;
    this->lista = nullptr;
}

ListaContigua::~ListaContigua(){
   delete[] lista;
}

int ListaContigua::getValor(int pos) {
    assertdomjudge(pos >= 0 && pos < this->n);
    return this->lista[pos];
}

void ListaContigua::setValor(int pos, int valor) {
    assertdomjudge(pos >= 0 && pos < this->n);
    this->lista[pos] = valor;
}

int ListaContigua::getN() {
    return this->n;
}

int ListaContigua::getCapacidad() {
    return this->cap;
}

void ListaContigua::insertar(int pos, int val) {
    assertdomjudge(pos >= 0 && pos <= this->n);
    
    if (this->n >= this->cap) {
        this->cap += inc;
        this->lista = (int*)realloc(this->lista,sizeof(int)*this->cap);
    }
    memmove(this->lista + pos + 1, this->lista + pos, (this->n - pos)*sizeof(int));
    this->n++;
    this->setValor(pos,val);
}

void ListaContigua::eliminar(int pos) {
    assertdomjudge(pos >= 0 && pos < this->n);
    if (this->n <= (this->cap - 2*this->inc)) {
        this->cap -= this->inc;
        this->lista = (int*)realloc(this->lista,sizeof(int)*this->cap);
    }
    memmove(this->lista + pos, this->lista + pos + 1, (this->n - pos - 1)*sizeof(int));
    this->n--;
}

void ListaContigua::concatenar(ListaContigua *listaAConcatenar) {
    assertdomjudge(listaAConcatenar->lista != nullptr);
    for (int i = 0; i < listaAConcatenar->getN(); i++) {
        this->insertar(this->n,listaAConcatenar->getValor(i));
    }
}

int ListaContigua::buscar(int val) {
    for (int i = 0; i < this->n; i++) {
        if (this->getValor(i) == val) {
            return i;
        }
    }
    return -1;
}