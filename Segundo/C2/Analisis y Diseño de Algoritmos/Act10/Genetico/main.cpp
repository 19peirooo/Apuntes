#include "iostream"
#include "Polinomio.h"
#include "cmath"
#include "cstdlib"
#include "ctime"
#include "ctime"

using namespace std;

int main()
{
  int grado; // Grado del polinomio
  int semilla; //Semilla aleatoria
  float *coeficientes = NULL; // Array de coeficientes
  
  cin>>semilla;
  srand(semilla); // Inicializamos motor de numeros aleatorios
  
  // Pedimos el grado 
  cin >> grado;
  
  // Pedimos y guardamos los coeficientes
  coeficientes = new float[grado+1];
  for (int i=0; i<=grado; i++) cin >> coeficientes[i];
  cout << endl;
  
  // Creamos el polinomio y hacemos 5 veces la b�squeda de ra�z
  Polinomio p(grado, coeficientes);
  for (int i=0; i<5; i++) {
	cout <<"Iteracion "<<i<<endl;
	float raiz = p.obtenerRaiz();
	cout <<" Raiz " << raiz << endl;
  }
  return 0;
}
