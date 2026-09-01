#include "Supermercado.h"
#include "ColaPrioridad.h"
#include "assertdomjudge.h"

/*Constructor
  Construye un supermercado
  Entrada: Numero de cajas
  Retorno: Ninguno
  Precondicion: Ninguna
  Complejidad Temporal: T(n) = n+1, O(n)
  Complejidad Espacial: M(n) = n +1, O(n)
*/

Supermercado::Supermercado(int n) {
    this->n_cajas = n;
    this->cajas = new ColaPrioridad[n];
}

/*nuevoUsuario
  Añade un usuario a una cola
  Entrada: Caja a encolar al usuario y su id
  Retorno: Ninguno
  Precondicion: Ninguna
  Complejidad Temporal: T(n) = n + 1, O(n)
  Complejidad Espacial: M(n) = 1
*/

void Supermercado::nuevoUsuario(int n,int id) {
    this->cajas[n].encolar(id);
}

/*cerrarCaja
  Vacia una caja y reparte a sus usuarios en otra cajas no vacias
  Entrada: Caja a cerrar
  Salida: Ninguna
  Preocondicion: Ninguna
  Complejidad Temporal: T(n) = O(n) + O(log(n)) = O(n)
  Complejidad Espacial: M(n) = O(1)
*/

void Supermercado::cerrarCaja(int n) {
    while (!this->cajaVacia(n)) {
        for (int i = 0; i < this->n_cajas; i++) {
            if (!this->cajaVacia(i)) {
                this->cajas[i].encolar(this->cajas[n].desencolar());
            }
        }
    }
}

/*atenderUsuario
   Desencola a un usuario de la lista
   Entrada: Caja donde se atiende al usuario
   Retorno: ID del usuario desencolado
   Precondicion: Ninguna
   Complejidad Temporal: T(n) = O(log(n))
   Complejidad Espacial: M(n) = O(1)
*/

int Supermercado::atenderUsuario(int n) {
    return this->cajas[n].desencolar();
}

/*cajaVacia
  Comprueba si una caja esta vacia
  Entrada: Caja a comprobar
  Retorno: True si esta vacia, False si no lo esta
  Precondicion: Ninguna
  Complejidad Temporal: O(1)
  Complejidad Espacial: O(1)
*/

bool Supermercado::cajaVacia(int n) {
    return this->cajas[n].estaVacia();
}