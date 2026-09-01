#pragma once
#include "ListaContigua.h"

// Clase que implementa una cola con prioridad mediante un monticulo (arbol binario completo en el cual la clave de cada nodo es menor que la de sus descendientes) e implementado sobre una lista contigua
class ColaPrioridad
{
protected:

	ListaContigua vector; 

public:

	void encolar(int nuevoElemento);

	int desencolar();

	bool estaVacia();

protected:
	
	void reestructurar();
};

