#include <iostream>
#include <iomanip>
using namespace std;

// Representa una soluci�n parcial del problema de optimizaci�n gen�tica
class SolucionParcial {
 public:
  float x; // Posici�n del hijo
  float y; // Valor del hijo
  void imprimir()
  {
    cout<<setprecision(5)<<"("<<x<<","<<y<<")"<<endl;
  }
  
};
