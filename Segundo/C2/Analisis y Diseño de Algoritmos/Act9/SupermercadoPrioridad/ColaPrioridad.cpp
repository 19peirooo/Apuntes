#include "ListaContigua.h"
#include "ColaPrioridad.h"
#include "assertdomjudge.h"

/*encolar
  Encola un elemento en funcion de su posicion
  Entrada: Elemento a encolar
  Retorno: Ninguno
  Complejidad Temporal: T(n) = O(n)
  Complejiad Espacia: M(n) = O(1)

*/

void ColaPrioridad::encolar(int nuevoElemento) {
    this->vector.insertarAlFinal(nuevoElemento); //O(n)

    int pos = this->vector.getN() - 1; //O(1)
    int posPadre = 0;

    while (pos > 0) {
        posPadre = (pos - 1) / 2;

        int valorHijo = this->vector.getValor(pos); //O(1)
        int valorPadre = this->vector.getValor(posPadre); //O(1)

        if (valorPadre > valorHijo)  {
            this->vector.setValor(posPadre, valorHijo); //O(1)
            this->vector.setValor(pos,valorPadre); //O(1)
            pos = posPadre;
        } else {
            return;
        }
       
    }

}

/*desencolar
  Elimina el elemento con el menor elemento
  Entrada: Ninguna
  Salida: Elemento Eliminado
  Precondicion: La lista no puede esta vacia
  Complejidad Temporal:
  Complejidad Espacial:
*/

int ColaPrioridad::desencolar() {
    assertdomjudge(!this->estaVacia());

    int valorAEliminar = this->vector.getValor(0);

    int temp = this->vector.getValor(this->vector.getN()-1);
    this->vector.setValor(this->vector.getN()-1,valorAEliminar);
    this->vector.setValor(0,temp);

    this->vector.eliminarAlFinal();

    if (!this->estaVacia()) {
        this->reestructurar();
    }
    
    return valorAEliminar;

}

/*estaVacia
  Comprueba si la cola esta vacia
  Entrada: Ninguna
  Retorno: True si esta vacia, False si no lo esta
  Precondicion: Ninguna
  Complejidad Temporal: O(1)
  Complejidad Espacial: O(1)
*/

bool ColaPrioridad::estaVacia() {
    return this->vector.getN() == 0;
}

/*reestructurar
  Vuelve a ordenar la cola despues de eliminar un elemento
  Entrada: Ninguna
  Retorno: Ninguno
  Precondicion: Ninguna
  Complejidad Temporal: T(n) = O(log(n))
  Complejidad Espacial: M(n) = O(1)
*/

void ColaPrioridad::reestructurar() {
    int pos = 0;

    while(true) {
        int posHijoIzq = 2 * pos + 1;
        int posHijoDer = 2 * pos + 2;
        int posMenor = pos;

        if (posHijoIzq < this->vector.getN() && this->vector.getValor(posHijoIzq) < this->vector.getValor(posMenor)) { //O(1)
            posMenor = posHijoIzq;
        }

        if (posHijoDer < this->vector.getN() && this->vector.getValor(posHijoDer) < this->vector.getValor(posMenor)) { //O(1)
            posMenor = posHijoDer;
        }

        if (posMenor != pos) {
            int temp = this->vector.getValor(pos);
            this->vector.setValor(pos,this->vector.getValor(posMenor));
            this->vector.setValor(posMenor,temp);
            pos = posMenor;
        } else {
            return;
        }

    }
}