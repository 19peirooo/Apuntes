#include "ABB.h"
#include "assertdomjudge.h"
#include "iostream"

//n -> numero de nodos
//Peor Caso --> Arbol Desbalanceado Completamente. Todo izq o todo der
//Mejor Caso --> Arbol Balanceado

using namespace std;

/*Constructor
  Constructor del arbol ABB
  Entrada: Ninguna
  Retorno: Ninguno
  Precondicion: Ninguno
  Complejidad Temporal: T(n) = 1, O(n)
  Complejidad Espacial: M(n) = 1, O(n)
*/

ABB::ABB() {
  this->raiz = nullptr;
  this->n = 0;
}

/*imprimir
  Imprime el arbol
  Entrada: Ninguna
  Retorno: Ninguno
  Precondicion: Ninguna
  Complejidad Temporal: T(n) = n + 1, O(n)
  Complejidad Espacial: M(n) = n + 1, O(n)
*/

void ABB::imprimir()
{
  if(raiz==NULL)
    cout<<"VACIO"<<endl;
  else   
      imprimirRecorrido(raiz);    
}

/*imprimirRecorrido
  Si un nodo esta a la izquierda de la raiz, le añade una I. Si esta a la derecha le añade una D
  Entrada: Raiz del subarbol a imprimir
  Retorno: Ninguno
  Precondicion: Ninguna
  Complejidad Temporal: T(n) = T(n-1) + 1 = n, O(n)
  Complejidad Espacial: M(n) = M(n-1) + 1 = n, O(n)
*/

void ABB::imprimirRecorrido(Nodo *raizSubarbol)
{
  cout<<raizSubarbol->contenido<<endl;
  if(raizSubarbol->hijoIzquierdo!=NULL)
    {
      cout<<"I";
      imprimirRecorrido(raizSubarbol->hijoIzquierdo);
      cout<<endl;
    }
  if(raizSubarbol->hijoDerecho!=NULL)
    {
      cout<<"D";
      imprimirRecorrido(raizSubarbol->hijoDerecho);
      cout<<endl;
    }
}



/* leerArbol
  Lee todo el arbol
  Entrada: Ninguna
  Retorno: Ninguno
  Precondicion: Ninguna
  Complejidad Temporal: T(n) = n + 1, O(n)
  Complejidad Espacial: M(n) = n + 1, O(n)
*/

void ABB::leerArbol()
{
  raiz=leerSubarbol(NULL);
}

/*leeSubarbol
  Lee un arbol dado su padre
  Entrada: Nodo padre
  Retorno: Ninguno
  Precondicion: Ninguna
  Complejidad Temporal: T(n) = 2*T(n) + 1 = 2n - 1, O(n)
  Complejidad Espacial: M(n) = 2*M(n) + 1 = 2n - 1, O(n) 
*/

Nodo * ABB::leerSubarbol(Nodo *padre)
{
  int contenido;
  cin>>contenido;
  if(contenido>=0)
    {
      Nodo *arbol=new Nodo;
      arbol->contenido=contenido;
      arbol->hijoIzquierdo=leerSubarbol(arbol);
      arbol->hijoDerecho=leerSubarbol(arbol);
      arbol->padre=padre;
      return arbol;
    }
  else
    {
      return NULL;
    }
}

/*insertar
  Inserta un nodo en el arbol
  Entrada: El elemento a insertar
  Retorno: Ninguno
  Precondicion: El nodo no debe de existir
  Complejidad Temporal: T(n) = 2n + 1, O(n)
  Complejidad Espacial: M(n) = 2n + 1, O(n)
*/

void ABB::insertar (int nuevoElemento) {

  assertdomjudge(this->buscar(nuevoElemento) == nullptr); //O(n)
  Nodo* nuevoNodo = new Nodo();
  nuevoNodo->contenido = nuevoElemento;
  nuevoNodo->padre = nullptr;
  nuevoNodo->hijoIzquierdo = nullptr;
  nuevoNodo->hijoDerecho = nullptr;
  if (this->raiz == nullptr) {
    this->raiz = nuevoNodo;
  } else {
    Nodo* nodoPadre = this->buscarHueco(raiz,nuevoElemento); //O(n)
    nuevoNodo->padre = nodoPadre;
    if (nuevoElemento < nodoPadre->contenido) {
      nodoPadre->hijoIzquierdo = nuevoNodo;
    } else {
      nodoPadre->hijoDerecho = nuevoNodo;
    }
  }
  this->n++;
}

/*buscarHueco
  Busca el padre de donde hay un hueco para insertar el nodo
  Entrada: Raiz del subarbol y elemento a insertar
  Retorno: Padre del posible hueco
  Precondicion: Ninguna
  Complejidad Temporal: T(n) = T(n-1) + 1, O(n)
  Complejidad Espacial: M(n) = M(n-1) + 1, O(n)
*/

Nodo* ABB::buscarHueco(Nodo *raizSubarbol, int elementoAInsertar) {
  if (elementoAInsertar < raizSubarbol->contenido) {
    if (raizSubarbol->hijoIzquierdo == nullptr) {
      return raizSubarbol;
    } else {
      return this->buscarHueco(raizSubarbol->hijoIzquierdo,elementoAInsertar);
    }
  } else {
    if (raizSubarbol->hijoDerecho == nullptr) {
      return raizSubarbol;
    } else {
      return this->buscarHueco(raizSubarbol->hijoDerecho,elementoAInsertar);
    }
  }
}

/*buscarMaximo
  Busca el nodo con el maximo elemento
  Entrada: Nodo Raiz del subarbol donde buscar el maximo
  Retorno: Nodo con el elemento minimo
  Precondicion: Ninguno
  Complejidad Temporal: T(n) = T(n-1) + 1 = n, O(n)
  Complejidad Espacial: M(n) = M(n-1) + 1 = n, O(n)
*/

Nodo *ABB::buscarMaximo (Nodo *raizSubarbol){
  if (raizSubarbol->hijoDerecho != nullptr) {
    return this->buscarMaximo(raizSubarbol->hijoDerecho);
  } else {
    return raizSubarbol;
  }
}

/*buscarMinimo
  Busca el nodo con el minimo elemento
  Entrada: Nodo Raiz del subarbol donde buscar el minimo
  Retorno: Nodo con el elemento minimo
  Precondicion: Ninguno
  Complejidad Temporal: T(n) = T(n-1) + 1 = n, O(n)
  Complejidad Espacial: M(n) = M(n-1) + 1 = n, O(n)
*/

Nodo *ABB::buscarMinimo (Nodo *raizSubarbol){
  if (raizSubarbol->hijoIzquierdo != nullptr) {
    return this->buscarMinimo(raizSubarbol->hijoIzquierdo);
  } else {
    return raizSubarbol;
  }
}

/*alturaNodo
  Calcula la altura de un nodo
  Entrada: Nodo Raiz del subarbol del que calcular la altura
  Retorno: Altura del nodo
  Precondicion: Ninguno
  Complejidad Temporal: T(n) = n, O(n)
  Complejidad Espacial: M(n) = n, O(n)
*/

int ABB::alturaNodo(Nodo *raizSubarbol) {
  if (raizSubarbol == nullptr) {
    return -1;
  }

  int alturaIzquierda = alturaNodo(raizSubarbol->hijoIzquierdo);
  int alturaDerecha = alturaNodo(raizSubarbol->hijoDerecho);
  
  if (alturaIzquierda > alturaDerecha) {
    return 1 + alturaIzquierda;
  } else {
    return 1 + alturaDerecha;
  }

}

/*eliminarNodo
  Elimina un nodo del arbol
  Entrada: nodo a eliminar
  Retorno: Ninguno
  Precondicion: Ninguno
  Complejidad Temporal: T(n) = 3*O(n) + 1, O(n)
  Complejidad Espacial: M(n) = 3*O(n) + 1, O(n)
*/

void ABB::eliminarNodo (Nodo *nodoParaEliminar) {

  Nodo* nodoSustituto = nullptr;

  if (nodoParaEliminar->hijoIzquierdo == nullptr && nodoParaEliminar ->hijoDerecho == nullptr) {
    Nodo* nodoPadre = nodoParaEliminar->padre;
    if (nodoParaEliminar == this->raiz) {
      this->raiz = nullptr;
    } else if (nodoPadre->hijoIzquierdo == nodoParaEliminar){
      nodoPadre->hijoIzquierdo = nullptr;
    } else if (nodoPadre->hijoDerecho == nodoParaEliminar) {
      nodoPadre->hijoDerecho = nullptr;
    }
    delete nodoParaEliminar;
    return;

  } else if (nodoParaEliminar->hijoIzquierdo != nullptr && nodoParaEliminar->hijoDerecho == nullptr) {
    nodoSustituto = this->buscarMaximo(nodoParaEliminar->hijoIzquierdo); //O(n)

  } else if (nodoParaEliminar->hijoIzquierdo == nullptr && nodoParaEliminar->hijoDerecho != nullptr) {
    nodoSustituto = this->buscarMinimo(nodoParaEliminar->hijoDerecho); //O(n)

  } else {
    int alturaIzq = this->alturaNodo(nodoParaEliminar->hijoIzquierdo); //O(n)
    int alturaDer = this->alturaNodo(nodoParaEliminar->hijoDerecho); //O(n)

    if (alturaIzq >= alturaDer) {
      nodoSustituto = this->buscarMaximo(nodoParaEliminar->hijoIzquierdo); //O(n)
    } else {
      nodoSustituto = this->buscarMinimo(nodoParaEliminar->hijoDerecho); //O(n)
    }
  }
  nodoParaEliminar->contenido = nodoSustituto->contenido;
  this->eliminarNodo(nodoSustituto); //O(n)

}

/*buscar
  busca un nodo en el arbol
  Entrada: elemento del nodo a buscar
  Retorno: Nodo a buscar
  Precondicion: Ninguno
  Complejidad Temporal: T(n) = T(n-1) + 1 = n, O(n)
  Complejidad Espacial: M(n) = M(n-1) + 1 = n, O(n)
*/

Nodo *ABB::buscar(int elementoABuscar) {
  Nodo* nodoABuscar = this->buscarRecursivo(this->raiz,elementoABuscar);
  return nodoABuscar;
}

/*buscarRecursivo
  Busca recursivamente un nodo en el arbol
  Entrada: elemento del nodo a buscar y nodo del subarbol de donde buscar
  Retorno: Nodo a buscar
  Precondicion: Ninguno
  Complejidad Temporal: T(n) = T(n-1) + 1 = n, O(n)
  Complejidad Espacial: M(n) = M(n-1) + 1 = n, O(n)
*/

Nodo *ABB::buscarRecursivo (Nodo *raizSubarbol, int elementoABuscar) {

  if (raizSubarbol == nullptr) {
    return nullptr;
  }

  if (raizSubarbol->contenido == elementoABuscar) {
    return raizSubarbol;
  } else if (elementoABuscar > raizSubarbol->contenido) {
    return this->buscarRecursivo(raizSubarbol->hijoDerecho,elementoABuscar);
  } else {
    return this->buscarRecursivo(raizSubarbol->hijoIzquierdo,elementoABuscar);
  }
} 

/*eliminar
  Elimina un nodo del arbol
  Entrada: elemento a eliminar
  Retorno: Ninguno
  Precondicion: El nodo debe existir
  Complejidad Temporal: T(n) = 3*O(n) + 1, O(n)
  Complejidad Espacial: M(n) = 3*O(n) + 1, O(n)
*/

void ABB::eliminar(int elementoAEliminar) {
  Nodo* nodoAEliminar = this->buscar(elementoAEliminar);
  assertdomjudge(nodoAEliminar != nullptr);
  this->eliminarNodo(nodoAEliminar);
  this->n--;  
}

/*esABB
  Comprueba si un arbol es un arbol binario de busqueda
  Entrada: Ninguna
  Retorno: True si es un ABB y False si no es un ABB
  Precondicion: Ninguna
  Complejidad Temporal: T(n) = T(n-1) + n = O(n^2) 
  Complejidad Espacial: M(n) = M(n-1) + 1 = O(n)
*/

bool ABB::esABB() {
  return this->esSubABB(this->raiz);
}

/*esSubABB
  Comprueba si un subarbol es un subarbol binario de busqueda
  Entrada: Raiz de Subarbol
  Retorno: True si es un ABB y False si no es un ABB
  Precondicion: Ninguna
  Complejidad Temporal: T(n) = T(n-1) + n = O(n^2) 
  Complejidad Espacial: M(n) = M(n-1) + 1 = O(n)
*/

bool ABB::esSubABB(Nodo *raizSubarbol) {
  if (raizSubarbol == nullptr) {
    return true;
  }

  if (raizSubarbol->hijoIzquierdo != nullptr) {
    if (raizSubarbol->contenido < this->buscarMaximo(raizSubarbol->hijoIzquierdo)->contenido) {
      return false;
    }
  }

  if (raizSubarbol->hijoDerecho != nullptr) {
    if (raizSubarbol->contenido > this->buscarMinimo(raizSubarbol->hijoDerecho)->contenido) {
      return false;
    }
  }

  return this->esSubABB(raizSubarbol->hijoIzquierdo) && this->esSubABB(raizSubarbol->hijoDerecho); //2*T(n/2)
}

/*esAVL
  Comprueba si un arbol es un arbol binario de busqueda
  Entrada: Ninguna
  Retorno: True si es un ABB y False si no es un ABB
  Precondicion: Ninguna
  Complejidad Temporal: T(n) = O(n^2) + O(n) = O(n^2)
  Complejidad Espacial: M(n) = O(n) + O(n) = O(n)
*/

bool ABB::esAVL() {
  return this->esABB() && this->esSubAVL(this->raiz);
}

/*esSubAVL
  Comprueba si un subarbol es un subarbol binario de busqueda
  Entrada: Raiz de Subarbol
  Retorno: True si es un ABB y False si no es un ABB
  Precondicion: Ninguna
  Complejidad Temporal: T(n) = O(n) 
  Complejidad Espacial: M(n) = O(n)
*/

bool ABB::esSubAVL(Nodo *raizSubarbol) {

  if (raizSubarbol == nullptr) {
    return true;
  }

  int alturaIzq = this->alturaNodo(raizSubarbol->hijoIzquierdo);
  int alturaDer = this->alturaNodo(raizSubarbol->hijoDerecho);

  bool balance = abs(alturaIzq-alturaDer) <= 1;

  return balance && this->esSubAVL(raizSubarbol->hijoIzquierdo) && this->esSubAVL(raizSubarbol->hijoDerecho);

}

/*eliminarSubarbol
  Elimina un subarbol dada su raiz
  Entrada: Raiz de Subarbol
  Retorno: Ninguno
  Precondicion: Ninguna
  Complejidad Temporal: T(n) = O(n) 
  Complejidad Espacial: M(n) = O(n)
*/

void ABB::eliminarSubarbol (Nodo *raizSubarbol) {
  if (raizSubarbol == nullptr) {
    return;
  }

  this->eliminarSubarbol(raizSubarbol->hijoIzquierdo);
  this->eliminarSubarbol(raizSubarbol->hijoDerecho);

  delete raizSubarbol;
}

/*Destructor
  Elimina todo el arbol
  Entrada: Ninguna
  Retorno: Ninguno
  Precondicion: Ninguna
  Complejidad Temporal: T(n) = O(n) 
  Complejidad Espacial: M(n) = O(n)
*/

ABB::~ABB(){
  this->eliminarSubarbol(this->raiz);
}