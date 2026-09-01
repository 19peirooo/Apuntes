#pragma once
#include "Nodo.h"

// Árbol binario de búsqueda. 
class ABB
{
	Nodo *raiz; 
	int n; 
public:

	ABB();
	void insertar (int nuevoElemento);
	Nodo *buscar(int elementoABuscar);
	void eliminar (int elementoAEliminar);
	void imprimir();
	bool esABB();
	bool esAVL();
	void leerArbol();
	~ABB();

protected:
	void eliminarSubarbol (Nodo *raizSubarbol);
	Nodo *buscarHueco(Nodo *raizSubarbol, int elementoAInsertar);
	Nodo *buscarRecursivo (Nodo *raizSubarbol, int elementoABuscar);
	Nodo *buscarMaximo (Nodo *raizSubarbol);
	Nodo *buscarMinimo (Nodo *raizSubarbol);
	void eliminarNodo (Nodo *nodoParaEliminar);
	int alturaNodo(Nodo *raizSubarbol);
	void imprimirRecorrido(Nodo *raizSubarbol);
	bool esSubABB(Nodo *raizSubarbol);
	bool esSubAVL(Nodo *raizSubarbol);
	Nodo * leerSubarbol(Nodo *padre);	
};

