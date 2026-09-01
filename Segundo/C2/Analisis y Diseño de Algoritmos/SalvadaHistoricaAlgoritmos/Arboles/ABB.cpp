#include "ABB.h"
#include "../assertdomjudge.h"
#include "iostream"

using namespace std;

void ABB::imprimir()
{
  if(raiz==NULL)
    cout<<"VACIO"<<endl;
  else   
      imprimirRecorrido(raiz);    
}

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

void ABB::leerArbol()
{
  raiz=leerSubarbol(NULL);
}

Nodo * ABB::leerSubarbol(Nodo *padre)
{
  int contenido;
  cin>>contenido;
  if(contenido>=0)
    {
      Nodo *arbol=new Nodo{contenido};
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

ABB::ABB() {
  this->raiz = nullptr;
  this->n = 0;
}

ABB::~ABB() {
  this->eliminarSubarbol(this->raiz);
}

void ABB::insertar(int nuevoElemento) {
  assertdomjudge(this->buscar(nuevoElemento) == nullptr);
  Nodo* nodo = new Nodo{nuevoElemento,nullptr,nullptr,nullptr};
  if (this->n == 0) {
    this->raiz = nodo;
  } else {
    Nodo* padre = this->buscarHueco(this->raiz,nuevoElemento);
    nodo->padre = padre;
    if (nodo->contenido > padre->contenido) {
      padre->hijoDerecho = nodo;
    } else {
      padre->hijoIzquierdo = nodo;
    }
  }
  this->n++;
}

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

Nodo* ABB::buscar(int elementoABuscar) {
  return this->buscarRecursivo(this->raiz,elementoABuscar);
}

Nodo* ABB::buscarRecursivo (Nodo *raizSubarbol, int elementoABuscar) {

  if (raizSubarbol == nullptr) {
    return nullptr;
  }

  if (elementoABuscar == raizSubarbol->contenido) {
    return raizSubarbol;  
  } else if (elementoABuscar < raizSubarbol->contenido) {
    return this->buscarRecursivo(raizSubarbol->hijoIzquierdo,elementoABuscar);
  } else {
    return this->buscarRecursivo(raizSubarbol->hijoDerecho,elementoABuscar);
  }

}

void ABB::eliminar (int elementoAEliminar) {
  assertdomjudge(this->buscar(elementoAEliminar) != nullptr);
  Nodo* nodoAEliminar = this->buscar(elementoAEliminar);
  this->eliminarNodo(nodoAEliminar);
  this->n--;
}

void ABB::eliminarNodo (Nodo *nodoParaEliminar) {
  Nodo* nodoSustituto;
  if (this->n == 1) {
    this->raiz = nullptr;
    delete nodoParaEliminar;
  } else {
    if (nodoParaEliminar->hijoIzquierdo == nullptr && nodoParaEliminar->hijoDerecho == nullptr) {
      Nodo* padre = nodoParaEliminar->padre;
      if (nodoParaEliminar->contenido < padre->contenido) {
        padre->hijoIzquierdo = nullptr;
      } else {
        padre->hijoDerecho = nullptr;
      }
      delete nodoParaEliminar;
      return;
    } else if (nodoParaEliminar->hijoIzquierdo == nullptr && nodoParaEliminar->hijoDerecho != nullptr) {
      nodoSustituto = this->buscarMinimo(nodoParaEliminar->hijoDerecho);
    } else if (nodoParaEliminar->hijoIzquierdo != nullptr && nodoParaEliminar->hijoDerecho == nullptr) {
      nodoSustituto = this->buscarMaximo(nodoParaEliminar->hijoIzquierdo);
    } else {
      int alturaIzq = this->alturaNodo(nodoParaEliminar->hijoIzquierdo);
      int alturaDer = this->alturaNodo(nodoParaEliminar->hijoDerecho);

      if (alturaDer >= alturaIzq) {
        nodoSustituto = this->buscarMinimo(nodoParaEliminar->hijoDerecho);
      } else {
        nodoSustituto = this->buscarMaximo(nodoParaEliminar->hijoIzquierdo);
      }
    }
    nodoParaEliminar->contenido = nodoSustituto->contenido;
    this->eliminarNodo(nodoSustituto);
  }
}

Nodo* ABB::buscarMaximo(Nodo *raizSubarbol) {
  if (raizSubarbol->hijoDerecho != nullptr) {
    return this->buscarMaximo(raizSubarbol->hijoDerecho);
  } else {
    return raizSubarbol;
  }
}

Nodo* ABB::buscarMinimo (Nodo *raizSubarbol) {
  if (raizSubarbol->hijoIzquierdo != nullptr) {
    return this->buscarMinimo(raizSubarbol->hijoIzquierdo);
  } else {
    return raizSubarbol;
  }
}

int ABB::alturaNodo(Nodo *raizSubarbol) {
  if (raizSubarbol == nullptr) {
    return -1;
  }

  int alturaIzq = this->alturaNodo(raizSubarbol->hijoIzquierdo);
  int alturaDer = this->alturaNodo(raizSubarbol->hijoDerecho);

  if (alturaIzq > alturaDer) {
    return 1 + alturaIzq;
  } else {
    return 1 + alturaDer;
  }

}

bool ABB::esABB() {
  return this->esSubABB(this->raiz);
}

bool ABB::esAVL() {
  return this->esABB() && this->esSubAVL(this->raiz);
}

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
    if (raizSubarbol->contenido > this->buscarMinimo(raizSubarbol->hijoDerecho)->contenido){
      return false;
    }
  }

  return this->esSubABB(raizSubarbol->hijoIzquierdo) && this->esSubABB(raizSubarbol->hijoDerecho);
}

bool ABB::esSubAVL(Nodo *raizSubarbol) {

  if (raizSubarbol == nullptr) {
    return true;
  }

  int alturaIzq = this->alturaNodo(raizSubarbol->hijoIzquierdo);
  int alturaDer = this->alturaNodo(raizSubarbol->hijoDerecho);

  if (abs(alturaIzq - alturaDer) <= 1) {
    return this->esSubAVL(raizSubarbol->hijoIzquierdo) && this->esSubAVL(raizSubarbol->hijoDerecho);
  } else {
    return false;
  }
}

void ABB::eliminarSubarbol (Nodo *raizSubarbol) {
  if (raizSubarbol == nullptr) {
    return;
  }
  this->eliminarSubarbol(raizSubarbol->hijoIzquierdo);
  this->eliminarSubarbol(raizSubarbol->hijoDerecho);
  delete raizSubarbol;
}
  
