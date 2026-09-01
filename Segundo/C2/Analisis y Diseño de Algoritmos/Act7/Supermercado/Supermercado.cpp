#include "Supermercado.h"
#include "assertdomjudge.h"

//n = n_cajas

/*  Constructor
    Constructor del supermercado
    Entrada: Numero de cajas
    Retorno: Ninguna
    Precondicion: Ninguna
    Complejidad Temporal: T(n) = n+1, O(n)
    Complejidad Espacial: M(n) = n+1, O(n)
*/

Supermercado::Supermercado(int n) {
    this->n_cajas = n;
    this->cajas = new Cola[n];
}

/*  nuevoUsuario
    Añade un usuario a una de las colas
    Entrada: Id del usuario y la cola a la que se une
    Retorno: Ninguna
    Precondicion: Caja ha de existir --> n entre 0 y n_cajas
    Complejidad Temporal: T(n) = 1, O(1)
    Complejidad Espacial: M(n) = 1, O(1)
*/

void Supermercado::nuevoUsuario(int n,int id) {
    assertdomjudge(n >= 0 && n < this->n_cajas);
    this->cajas[n].encolar(id);
} 

/*  cerrarCaja
    Vacia una caja dada y reparte sus usuarios entre el resto
    Entrada: Caja a vaciar
    Retorno: Ninguna
    Precondicion: Ninguna
    Complejidad Temporal: T(n) = (n-1)m + 1, O(nm)
    Complejidad Espacial: M(n) = 1, O(1)
*/

void Supermercado::cerrarCaja(int n) {
    while(!(this->cajaVacia(n))) {
        for (int i = 0; i < n_cajas && i != n; i++) {
            if (!(this->cajaVacia(n))) {
                int idCliente = this->cajas[n].desencolar();
                this->cajas[i].encolar(idCliente);
            }
        }
    }
}

/*  atenderUsuario
    Desencola un usuario de una las colas
    Entrada: Id del usuario y la cola a la que se une
    Retorno: Ninguna
    Precondicion: Ninguna
    Complejidad Temporal: T(n) = 1, O(1)
    Complejidad Espacial: M(n) = 1, O(1)
*/

int Supermercado::atenderUsuario(int n) {
    return this->cajas[n].desencolar();
}

/*  cajaVacia
    Comprueba si una caja esta vacia
    Entrada: Caja a comprobar
    Retorno: true o false en funcion de si una caja esta vacia
    Precondicion: Ninguna
    Complejidad Temporal: T(n) = 1, O(1)
    Complejidad Espacial: M(n) = 1, O(1)
*/

bool Supermercado::cajaVacia(int n) {
    return this->cajas[n].estaVacia();
}

/*  Destructor
    Vacia todas la colas
    Entrada: Id del usuario y la cola a la que se une
    Retorno: Ninguna
    Precondicion: Ninguna
    Complejidad Temporal: T(n) = 1, O(1)
    Complejidad Espacial: M(n) = 1, O(1)
*/

Supermercado::~Supermercado() {
    for (int i = 0; i < n_cajas; i++) {
        this->cajas[i].~Cola();
    }
    delete[] this->cajas;
}