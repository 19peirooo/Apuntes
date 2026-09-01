#include "Matriz.h"
#include <iostream>
#include<math.h>
#include<stdlib.h>
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

//Asignacion de matrices

Matriz& Matriz::operator= (const Matriz &m)
{
  if(matriz!=NULL)
    {
      for (int i = 0; i < n_filas; i++)
	delete[] matriz[i];
      
      delete[] matriz;
      matriz=NULL;
    }

  this->n_filas=m.n_filas;
  this->n_columnas=m.n_columnas;
  this->matriz=NULL;
  if(n_filas>0 && n_columnas>0)
    {
      matriz= new double *[n_filas];
  
      for (int i = 0; i < n_filas; i++)
	{
	  matriz[i] = new double[n_columnas];  
	  for(int j=0; j <n_columnas; j++)
	    matriz[i][j]=m.matriz[i][j];
	}
    }
  
    return(*this); 
}


// Leer matriz
void Matriz::rellenarManual()
{
  double elemento;
  for (int i = 0; i < n_filas; i++)
    {
      cout << "Fila " << i << endl;
      for (int j = 0; j < n_columnas; j++)
	{
	  cout << "Elemento " << j  << endl;
	  cin >> elemento;
	  matriz[i][j] = elemento;
        }
      cout << endl;
    }
  
}

// Rellenar Matriz Aleatoria
void Matriz::rellenarAleatorio(long seed)
{
  srand(seed);
  for (int i = 0; i < n_filas; i++)
    for (int j = 0; j < n_columnas; j++)
      matriz[i][j]=rand();
  
}



// Imprimir Matriz
void Matriz::mostrarMatriz()
{
  for (int i = 0; i < n_filas; i++) {
	  for (int j = 0; j < n_columnas; j++) {
      cout << matriz[i][j] << " "; 
    }      
    cout << endl;
    }
}

//Constructores
Matriz::Matriz(int n_filas, int n_columnas){
  this->n_filas = n_filas;
  this->n_columnas = n_columnas;

  //Asigna memoria para la matriz. Primero a las filas y luego a cada columna
  this->matriz = new double*[this->n_filas];
  for (int i = 0; i < this->n_filas; i++) {
    matriz[i] = new double[this->n_columnas];
  }
}

//Matriz por defecto
Matriz::Matriz() {
  this->n_filas = 0;
  this->n_columnas = 0;
  this->matriz = nullptr;
}

//Constructor para Duplicar
Matriz::Matriz(Matriz &matrizOriginal){
  this->n_filas = matrizOriginal.n_filas;
  this->n_columnas = matrizOriginal.n_columnas;

  this->matriz = new double*[this->n_filas];
  for (int i = 0; i < this->n_filas; i++){
    this->matriz[i] = new double[this->n_columnas];
    for (int j = 0; j < this->n_columnas; j++){
      this->matriz[i][j] = matrizOriginal.matriz[i][j];
    }
  }
}

//Destructor
Matriz::~Matriz(){
  for (int i = 0; i < this->n_filas; i++) {
    delete[] matriz[i];
  }
  delete[] matriz;
}

//Suma 2 matrices
Matriz Matriz::operator+ (Matriz &m1) {
  //La suma solo es posible si las dimensiones coinciden
  assertdomjudge((this->n_filas == m1.n_filas) && (this->n_columnas == m1.n_columnas))
  Matriz *mResult = new Matriz(this->n_filas, this->n_columnas);
  for (int i = 0; i < this->n_filas; i++){
    for (int j = 0; j < this->n_columnas; j++){
      mResult->matriz[i][j] = this->matriz[i][j] + m1.matriz[i][j];
    }
  }
  return *mResult;
}

//Resta 2 matrices
Matriz Matriz::operator- (Matriz &m1) {
  //La resta solo es posible si las dimensiones coinciden
  assertdomjudge((this->n_filas == m1.n_filas) && (this->n_columnas == m1.n_columnas))
  Matriz *mResult = new Matriz(this->n_filas, this->n_columnas);
  for (int i = 0; i < this->n_filas; i++){
    for (int j = 0; j < this->n_columnas; j++){
      mResult->matriz[i][j] = this->matriz[i][j] - m1.matriz[i][j];
    }
  }
  return *mResult;
}

//Producto por escalar
Matriz Matriz::operator* (double num) {
  Matriz *mResult = new Matriz(*this);
  for (int i = 0; i < this->n_filas; i++) {
    for (int j = 0; j < this->n_columnas; j++) {
      mResult->matriz[i][j] *= num;
    }
  }
  return *mResult;
}

//Producto de dos matrices
Matriz Matriz::operator* (Matriz &m1) {
  //Solo es posible multiplicar matrices si el nº columnas primero = nº filas segundo
  assertdomjudge(this->n_columnas == m1.n_filas);
  //Dimensiones de la matriz resultado son filas primero para las filas y columnas segundo para las columnas
  Matriz *mResult = new Matriz(this->n_filas, m1.n_columnas);
  for (int i = 0; i < mResult->n_filas; i++){
    for (int j = 0; j < mResult->n_columnas; j++){
      mResult->matriz[i][j] = 0;
      for (int k = 0; k < this->n_columnas; k++){
        //Multiplica todos los elementos de una fila del primero por todos los de una columna del segundo
        mResult->matriz[i][j] += this->matriz[i][k] * m1.matriz[k][j];
      } 
    }
  }
  return *mResult;
}

//Calcula la Matriz Traspuesta. Cambia filas por columnas
Matriz Matriz :: calcularTraspuesta() {
  Matriz *mResult = new Matriz (this->n_columnas, this->n_filas);
  for (int i = 0; i < mResult->n_filas; i++){
    for (int j = 0; j < mResult->n_columnas; j++) {
      mResult->matriz[i][j] = this->matriz[j][i];
    }
  }
  return *mResult;
}

//Comprueba si una matriz es simetrica
bool Matriz::esSimetrica() {
  bool esSimetrica = true;
  //Para que sea simetrica ha de ser cuadrada
  assertdomjudge(this->n_filas == this->n_columnas)
  for (int i = 0; i < this->n_filas; i++){
    for (int j = 0; i < this->n_columnas; i++) {
      if (this->matriz[i][j] != this->matriz[j][i]) {
        esSimetrica = false;
      }
    }
  }
  if (!(this->n_filas == this->n_columnas)) {
    esSimetrica = false;
  }
  return esSimetrica;
}

//Obtiene el elemento maximo de una matriz
double Matriz::obtenerMaximo(){
  double valMax = -1000000000;
  for (int i = 0; i < this->n_filas; i++){
    for (int j = 0; j < this->n_columnas; j++) {
      if (this->matriz[i][j] > valMax){
        valMax = this->matriz[i][j];
      }
    }
  }
  return valMax; 
}

//Obtiene el elemento minimo de una matriz
double Matriz::obtenerMinimo(){
  double valMin = 100000000;
  
  for (int i = 0; i < this->n_filas; i++){
    for (int j = 0; j < this->n_columnas; j++) {
      if (this->matriz[i][j] < valMin){
        valMin = this->matriz[i][j];
      }
    }
  }
  return valMin;

}

/*  Calculadora Determinantes
    Calcula la Raiz Cuadrada de un numero mediante aproximaciones sucesivas. Calcula hasta que la diferencia entre 
    la aproximacion al cuadrado y el numero sea menor que 0
    Precondicion: n >= 0, error > 0
    Complejidad Temporal: 
    Complejidad Espacial: O(1) --> Solo se crean variables
*/

double Matriz::calcularDeterminante() {
  double det=0;

  assertdomjudge(this->n_filas == this->n_columnas);

  if (this->n_filas == 1 && this->n_columnas == 1){
    return this->matriz[0][0];
  }

  if (this->n_filas == 2 && this->n_columnas == 2) {
    return this->matriz[0][0] * this->matriz[1][1] - this->matriz[0][1] * this->matriz[1][0];
  }

  for (int fila = 0; fila < this->n_filas; fila++){
    Matriz adjunto(this->n_filas-1,this->n_columnas-1);
    int filAdj=0;
    for (int i = 0; i < this->n_filas; i++) {
      int colAdj = 0;
      if (fila != i){
        for (int j = 0; j < this->n_columnas; j++) {
          if (j != 0){
            adjunto.matriz[filAdj][colAdj] = this->matriz[i][j];
            colAdj++;
          }
        }
        filAdj++;
      }
    }
    int signo = 0;
    if (fila % 2 == 0) {
      signo = 1;
    } else {
      signo = -1;
    }

    det += signo * this->matriz[fila][0] * adjunto.calcularDeterminante();
  }
  return det;
}