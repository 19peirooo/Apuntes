#include"Pila.h"
#include "assertdomjudge.h"

/*  Constructor
    Constructor de la pila
    Entrada: Nombre de la pila
    Retorno: Ninguno
    Precondicion: Ninguna
    Complejidad Temporal: T(n) = 1, O(1)
    Complejidad Espacial: M(n) = 1, O(1)
*/

Pila::Pila(string name)
{
  this->name = name;
  this->cima = nullptr;
}

/*  nombrePila
    Devuelve el nombre de la pila
    Entrada: Ninguna
    Retorno: Nombre de la pila
    Precondicion: Ninguna
    Complejidad Temporal: T(n) = 1, O(1)
    Complejidad Espacial: M(n) = 1, O(1)
*/

std::string Pila::nombrePila()
{
  return this->name;
}

/*  apilar
    Añade un elemento a la cima de la pila
    Entrada: Numero a apilar
    Retorno: Ninguna
    Precondicion: Ninguna
    Complejidad Temporal: T(n) = 1, O(1)
    Complejidad Espacial: M(n) = 1, O(1)
*/

void Pila::apilar(int num)
{
  Nodo* nodo = new Nodo{num,this->cima};
  this->cima = nodo;
  cout<<"Apilando disco "<<num<<" en poste "<<name<<endl;
}

/*  desapilar
    Elimina el elemento de la cima
    Entrada: Ninguna
    Retorno: Valor desapliada
    Precondicion: Lista no puede serr vacia
    Complejidad Temporal: T(n) = 1, O(1)
    Complejidad Espacial: M(n) = 1, O(1)
*/

int Pila::desapilar()
{    
  assertdomjudge(!(this->estaVacia()));
  int num = this->cima->valor;
  Nodo* nodoDesapilado = this->cima;
  this->cima = this->cima->siguiente;
  
  delete nodoDesapilado;

  cout<<"Desapilando disco "<<num<<" del poste "<<name<<endl;
  return num;
}

/*  estaVacia
    Comprueba si la lista esta vacia
    Entrada: Ninguna
    Retorno: true o false en funcion de si esta vacia o no
    Precondicion: Ninguna
    Complejidad Temporal: T(n) = 1, O(1)
    Complejidad Espacial: M(n) = 1, O(1)
*/

bool Pila::estaVacia()
{
  return this->cima == nullptr;
}

