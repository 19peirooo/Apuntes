#include"Cola.h"

class Supermercado
{
private:
  Cola *cajas;
  int n_cajas;
public:
  Supermercado(int n);
  void nuevoUsuario(int n,int id);  
  void cerrarCaja(int n);  
  int atenderUsuario(int n);
  bool cajaVacia(int n);
  ~Supermercado();
};
