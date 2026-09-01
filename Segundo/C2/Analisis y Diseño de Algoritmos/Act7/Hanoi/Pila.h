#include"Nodo.h"
#include<string>
#include<iostream>
using namespace std;

class Pila
{
 private:
  Nodo *cima;
  string name;
 public:
  Pila(string name);
  string nombrePila();
  void apilar(int num); 
  int desapilar();
  bool estaVacia();
};

  
