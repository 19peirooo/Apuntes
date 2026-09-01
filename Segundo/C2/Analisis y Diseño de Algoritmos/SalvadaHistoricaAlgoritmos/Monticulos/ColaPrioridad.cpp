#include "ColaPrioridad.h"

ColaPrioridad::ColaPrioridad(){
    this->vector = ListaContigua();
}

ColaPrioridad::~ColaPrioridad() {
    this->vector.~ListaContigua();
}

void ColaPrioridad::encolar(int nuevoElemento) {

    this->vector.insertarAlFinal(nuevoElemento);

    int pos = this->vector.getN()-1;
    int posPadre = (pos-1)/2;

    int valPadre = this->vector.getValor(posPadre);

    //Mientras tenga padre y el valor del padre sea mayor que el del hijo
    while (pos > 0 && valPadre > nuevoElemento) {
        posPadre = (pos-1)/2;
        int valHijo = this->vector.getValor(pos);
        valPadre = this->vector.getValor(posPadre);

        if (valPadre > nuevoElemento) {
            this->vector.setValor(posPadre,nuevoElemento);
            this->vector.setValor(pos,valPadre);
            pos = posPadre;
        }

    }

}

int ColaPrioridad::desencolar() {

    assertdomjudge(!this->estaVacia());

    int valorRaiz = this->vector.getValor(0);
    int valorFinal = this->vector.getValor(this->vector.getN()-1);

    this->vector.setValor(0,valorFinal);
    this->vector.setValor(this->vector.getN()-1,valorRaiz);

    this->vector.eliminarAlFinal();

    if (!this->estaVacia()) {
        this->reestructurar();
    }

    return valorRaiz;

}

bool ColaPrioridad::estaVacia() {
    return this->vector.getN() == 0;
}

void ColaPrioridad::reestructurar() {

    int pos = 0;
    int posMenor = pos;

    while (true) {
        int posIzq = (pos*2) + 1;
        int posDer = (pos*2) + 2;
        int posMenor = pos;

        if (posIzq < this->vector.getN() && this->vector.getValor(posIzq)< this->vector.getValor(posMenor)) {
            posMenor = posIzq;
        }

        if (posDer < this->vector.getN() && this->vector.getValor(posDer) < this->vector.getValor(posMenor)) {
            posMenor = posDer;
        }

        if (posMenor != pos) {
            int valPosMenor = this->vector.getValor(posMenor);
            this->vector.setValor(posMenor,this->vector.getValor(pos));
            this->vector.setValor(pos,valPosMenor);
            pos = posMenor;
        } else {
            break;
        }

    }

}

void ColaPrioridad::imprimirCola() {
    if (this->estaVacia()) {
        std::cout << "Cola Vacia" << std::endl;
    } else {
        for (int i = 0; i < this->vector.getN();i++) {
            std::cout << this->vector.getValor(i) << " ";
        }
        
        std::cout << std::endl;
    }
}