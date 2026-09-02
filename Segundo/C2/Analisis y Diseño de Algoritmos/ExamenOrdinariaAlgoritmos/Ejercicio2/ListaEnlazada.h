#pragma once
#include "Nodo.h"

class ListaEnlazada
{
	Nodo *lista;

	int n;

	Nodo * getNodo (int posicion);

public:

	ListaEnlazada();

	Licencia getValor(int posicion);

	void setValor(int posicion, Licencia nuevoValor);

	int getN(); 

	void insertar (int posicion, Licencia nuevoValor);

	void eliminar (int posicion);

	int buscar(Licencia elementoABuscar);

	void imprimir();

	~ListaEnlazada();
};







