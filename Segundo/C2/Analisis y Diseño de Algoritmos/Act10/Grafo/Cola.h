#include"Nodo.h"  
class Cola
{
 private:
  Nodo *principio;
  Nodo *final;
 public:
  Cola();
  void encolar(int num);  
  int desencolar();
  bool estaVacia();
  ~Cola();  
};

  
