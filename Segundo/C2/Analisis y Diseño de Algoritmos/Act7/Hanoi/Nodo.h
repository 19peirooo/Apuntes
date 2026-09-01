#include<stdlib.h>
class Nodo
{
 public:
  int valor;
  Nodo *siguiente;
  
  Nodo(int v,Nodo *sig=NULL)
    {
      valor=v;
      siguiente=sig;
    }
};

