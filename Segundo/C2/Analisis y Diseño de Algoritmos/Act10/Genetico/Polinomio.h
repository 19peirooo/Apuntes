#pragma once

#include "SolucionParcial.h" // Estructura que guarda el "x" e "y" de una solución parcial

// Clase que representa una función polinómica de cualquier grado y de una variable independiente
class Polinomio
{
 private:
 	int n; // Grado del polinomio. Tiene que ser >= 0
	float *coeficientes; // Array de coeficientes del polinomio (tamaño: n+1). Primero los coeficientes de los sumandos de grado menor.

	// Función para obtener un número aleatorio que siga una distribución normal estandar (media 0 y desviación 1).
	// Retorno: número aleatorio siguiendo una distribución normal entre [-6, +6]
	// Complejidad temporal y espacial: O(1)
	float obtenerAleatorioNormalEstandar();

	float obtenerRaizRecursivo(SolucionParcial solucionParcialInicial);

public:

	Polinomio(int n, float *coeficientes);
	float evaluar (float x);
	float obtenerRaiz();
	~Polinomio();
};

