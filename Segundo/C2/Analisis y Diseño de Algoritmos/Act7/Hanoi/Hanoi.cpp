#include<iostream>
#include"Pila.h"
#include"assertdomjudge.h"
using namespace std;

/*  Hanoi
    Constructor de la pila
    Entrada: Nombre de la pila
    Retorno: Ninguna
    Precondicion: Ninguna
    Complejidad Temporal: T(n) =2*T(n-1) + 1 = 2^n - 1, O(2^n)
    Complejidad Espacial: M(n) = 1, O(1)
*/

void Hanoi(int n,Pila *origen,Pila *destino,Pila *temporal) 
{
  if (n > 0) { 
    Hanoi(n-1,origen,temporal,destino); //T(n) = T(n-1)
    destino->apilar(origen->desapilar()); //T(n) = 1
    Hanoi(n-1,temporal,destino,origen); //T(n) = T(n-1)
  }
}


int main()
{  
  Pila *A=new Pila("A");
  Pila *B=new Pila("B");
  Pila *C=new Pila("C");

  int n;
  cin>>n;

  assertdomjudge(n>0);

  for(int i=n;i>0;i--)
    A->apilar(i);

  Hanoi(n,A,C,B);
  
  for(int i=0;i<n;i++)
    C->desapilar();
  return 0;
  
}

