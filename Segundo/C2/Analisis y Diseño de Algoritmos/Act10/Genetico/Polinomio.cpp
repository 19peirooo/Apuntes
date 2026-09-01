#include "Polinomio.h"
#include "assertdomjudge.h"
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <math.h>

using namespace std;


/* obtenerAleatorioNormalEstandar
	Calcular una variable aleatoria estandar
	Entrada: Ninguna
	Salida: Variable aletoria
	Precondicion: Ninguna
	Complejidad Temporal: O(1)
	Complejidad Espacial O(1)
*/

float Polinomio::obtenerAleatorioNormalEstandar() {
	// Una variable aleatoria normal est�ndar se puede calcular o bien con "normal_distribution" de la biblioteca "random" (versi�n 2011 de C++)
	// o bien mediante 12 sumas sucesivas de valores aleatorios uniformes entre 0 y 1 (nos lo da rand()/(float)RAND_MAX),
	// y luego rest�ndole 6. M�s detalles sobre este m�todo en 
	// http://en.wikipedia.org/wiki/Normal_distribution#Generating_values_from_normal_distribution
	// Para calcular una normal no est�ndar recordemos que ser�a X = media + desviaci�n*Z, donde Z es la normal est�ndar

	float suma=0; // Suma de 12 variables aleatorias uniformes entre 0 y 1
	for (int i=0; i<12; i++) suma = suma + rand()/(float)RAND_MAX;
	return(suma-6);	
}

/*	obtenerRaizRecursivo
	Obtiene la raiz de un polinomio
	Entrada: Solucion Padre
	Salida: Valor de la raiz
	Precondicion: Ninguna
	Complejidad Temporal: O(n*m), m = num de llamadas recursivas
	Complejidad Espacial: O(m)
*/

float Polinomio::obtenerRaizRecursivo(SolucionParcial padre) {

	// Imprimimos el padre
        cout<<"Seleccionada"<<endl;
	padre.imprimir();
	cout<<"Mutaciones"<<endl;
	
	SolucionParcial mejorHijo = padre;

	// Calculamos la mutaci�n para cada hijo (10)  y evaluamos el polinomio para dicha mutaci�n
	SolucionParcial* hijos = new SolucionParcial[10];
	for (int i = 0; i < 10; i++) {
		float mutacion = this->obtenerAleatorioNormalEstandar();
		hijos[i].x = padre.x + mutacion;
		hijos[i].y = this->evaluar(hijos[i].x);
		// Imprimimos la solucion parcial encontrada para las mutaciones (hijo.imprimir()
		hijos[i].imprimir();

		if (fabs(hijos[i].y) < fabs(mejorHijo.y)) {
			mejorHijo = hijos[i];
		}

	}

	// Si el mejor hijo es mejor que el padre, hacemos que tenga descendencia. Si no, hemos acabado
	if (fabs(mejorHijo.y) < fabs(padre.y)) {
		return this->obtenerRaizRecursivo(mejorHijo);
	} else {
		return padre.x;
	}

	
}

/*	Constructor
	Contruye un polinomio de grado n
	Entrada: Grado y coeficientes del polinomio
	Salida: Ninguna
	Precondicion: Grado >= 0 y Coeficientes no nulos
	Complejidad Temporal: O(1)
	Complejidad Espacial: O(1)
*/

Polinomio::Polinomio(int n, float *coeficientes) {
	assertdomjudge(n >= 0);
	assertdomjudge(coeficientes != nullptr);
	this->n = n;
	this->coeficientes = coeficientes;
}

/*	evaluar
	Dado un valor de x, devuelve el valor de ese x en la funcion
	Entrada: Valor de x
	Salida: Valor de f(x)
	Precondicion: Ninguna
	Complejidad Temporal: O(n)
	Complejidad Espacial: O(1)
*/

float Polinomio::evaluar(float x) {
	float resultado = 0.0;
	for (int i = 0; i <= this->n; i++) {
		resultado += this->coeficientes[i]*pow(x,i);
	}
	return resultado;
}

/*	obtenerRaiz
	Obtiene la raiz de un polinomio
	Entrada: Ninguna
	Salida: Valor de la raiz
	Precondicion: Ninguna
	Complejidad Temporal: O(n*m), m = num de llamadas recursivas
	Complejidad Espacial: O(m)
*/

float Polinomio::obtenerRaiz() {
	SolucionParcial padre;
	padre.x = 0;
	padre.y = this->evaluar(padre.x);
	return this->obtenerRaizRecursivo(padre);
}

/*	Destructor
	Destruye la clase borrando la memoria del array de coeficientes
	Entrada: Ninguna
	Salida: Ninguna
	Precondicion: Ninguna
	Complejidad Temporal: O(1)
	Complejidad Espacial: O(1)
*/

Polinomio::~Polinomio() {
	delete[] this->coeficientes;
}
