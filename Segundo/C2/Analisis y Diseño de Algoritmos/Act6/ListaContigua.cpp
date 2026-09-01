#include "ListaContigua.h"
#include "assertdomjudge.h"


/*  Constructor
    Constructor de la lista contigua
    Entrada: Incremento de la lista
    Retorno: Ninguno
    Precondicion: Incremento ha de ser mayor que 0
    Complejidad Temporal: T(n) = 1 , O(1)
    Complejidad Espacial: M(n) = n+1, O(n)
*/

ListaContigua::ListaContigua(int incremento){
    assertdomjudge(incremento > 0);
    this->n = 0;
    this->capacidad = incremento;
    this->incremento = incremento;
    this->vector = new int[this->capacidad];
}

/*  getValor
    Dada una posicion, devuelve el valor en esa posicion
    Entrada: Posicion
    Retorno: Valor
    Precondicion: Posicion dentro de la lista
    Complejidad Temporal: T(n) = 1 , O(1)
    Complejidad Espacial: M(n) = 1, O(1)
*/

int ListaContigua::getValor(int posicion) {
    assertdomjudge(posicion >= 0 && posicion < this->getN());
    return this->vector[posicion];
}

/*  setValor
    Dada una posicion, cambia el valor en esa posicion
    Entrada: Posicion y valor nuevo
    Retorno: Ninguno
    Precondicion: Posicion dentro de la lista
    Complejidad Temporal: T(n) = 1 , O(1)
    Complejidad Espacial: M(n) = 1, O(1)
*/

void ListaContigua::setValor(int posicion, int nuevoValor){
    assertdomjudge(posicion >= 0 && posicion < this->getN());
    this->vector[posicion] = nuevoValor;
}

/*  getN
    Devuelve el numero de elementos en la lista
    Entrada: Ninguna
    Retorno: Numero de elementos en la lista
    Precondicion: Ninguna
    Complejidad Temporal: T(n) = 1 , O(1)
    Complejidad Espacial: M(n) = 1, O(1)
*/

int ListaContigua::getN(){
    return this->n;
}

/*  getCapacidad
    Devuelve la capacidad de la lista
    Entrada: Ninguna
    Retorno: Capacidad de la lista
    Precondicion: Ninguna
    Complejidad Temporal: T(n) = 1 , O(1)
    Complejidad Espacial: M(n) = 1, O(1)
*/

int ListaContigua::getCapacidad(){
    return this->capacidad;
}

/*  insertar
    Inserta un valor en la lista en una posicion dada y desplaza el resto de elementos
    Entrada: Posicion y valor nuevo 
    Retorno: Ninguno
    Precondicion: Posicion dentro de la lista
    Complejidad Temporal: T(n) = n + 1 , O(n)
    Complejidad Espacial: M(n) = n + 1, O(n)
*/

void ListaContigua::insertar(int posicion, int nuevoValor) {
    assertdomjudge(posicion >= 0 && posicion <= this->getN());
    if (this->getN() == this->getCapacidad()){
        this->capacidad += this->incremento;
        this->vector = (int*)realloc(this->vector, sizeof(int) * this->capacidad); //M(n) = M(n + k) = n
    }
    memmove(this->vector + posicion + 1, this->vector + posicion , (this->n - posicion) * sizeof(int)); //T(n) = n en el peor caso
    this->n++;
    this->setValor(posicion,nuevoValor); //T(n) = M(n) = 1
    
}

/*  eliminar
    Elimina un valor de la lista en una posicion dada y desplaza el resto de elementos
    Entrada: Posicion
    Retorno: Ninguno
    Precondicion: Posicion dentro de la lista
    Complejidad Temporal: T(n) = n + 1 , O(n)
    Complejidad Espacial: M(n) = n + 1, O(n)
*/

void ListaContigua::eliminar(int posicion) {
    assertdomjudge(posicion >= 0 && posicion < this->getN());
    memmove(this->vector + posicion , this->vector + posicion + 1, (this->n - posicion - 1) * sizeof(int)); //T(n) = n
    this->n--;
    if (this->n <= (this->capacidad-(2*this->incremento))) {
        this->capacidad -= this->incremento;
        this->vector = (int*)realloc(this->vector, sizeof(int) * this->capacidad); //T(n)
    }
}

/*  concatenar
    Concatena una lista a la actual. m = longitud lista a concatenar
    Entrada: lista a concatenar
    Retorno: Ninguno
    Precondicion: Lista a concatenar no este vacia
    Complejidad Temporal: T(n) = m + 1 , O(m)
    Complejidad Espacial: M(n) = n + m + 1, O(n+m)
*/

void ListaContigua::concatenar(ListaContigua *listaAConcatenar) {
    assertdomjudge(listaAConcatenar != nullptr);
    this->capacidad += listaAConcatenar->capacidad;
    this->vector = (int*)realloc(this->vector, sizeof(int) * this->capacidad); //M(n) = n + m
    int temp = this->n + listaAConcatenar->n;
    for (int i = this->n; i < temp; i++) { //T(n) = n + m - n + 1 = m + 1 
        this->vector[i] = listaAConcatenar->vector[i-this->n];
    }
    this->n = temp;
}

/*  buscar
    Busca un elemento en la lista
    Entrada: elemento a buscar
    Retorno: posicion del elemento. Si no encontrado -1
    Precondicion: Ninguna
    Complejidad Temporal: T(n) = n + 1 , O(n)
    Complejidad Espacial: M(n) =  1, O(1)
*/

int ListaContigua::buscar(int elementoABuscar) {
    assertdomjudge(this->vector != nullptr);
    int posicion = -1;
    bool encontrado = false;
    for (int i = 0; i < this->n && !encontrado; i++) {
        if (this->vector[i] == elementoABuscar) {
            posicion = i;
            encontrado = true;
        }
    }
    return posicion;
}

/*  destructor
    Destructor --> Libera la memoria gastada
    Entrada: Ninguna
    Retorno: Ninguno
    Precondicion: Ninguna
    Complejidad Temporal: T(n) = 1 , O(1)
    Complejidad Espacial: M(n) = 1 , O(1)
*/

ListaContigua::~ListaContigua(){
    delete[] this->vector;
}