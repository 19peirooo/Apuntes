#include"ColaPrioridad.h"

class Supermercado
{
private:
  ColaPrioridad *cajas;
  int n_cajas;
public:
  Supermercado(int n);
  void nuevoUsuario(int n,int id);  
  void cerrarCaja(int n);  
  int atenderUsuario(int n);
  bool cajaVacia(int n);
};
