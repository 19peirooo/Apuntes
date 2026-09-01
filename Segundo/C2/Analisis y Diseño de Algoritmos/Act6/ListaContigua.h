#pragma once


class ListaContigua
{
	int *vector;

	int n;

	int capacidad;

	int incremento;

public:

	ListaContigua(int incremento);

	int getValor(int posicion);

	void setValor(int posicion, int nuevoValor);

	int getN(); 

	int getCapacidad(); 

	void insertar(int posicion, int nuevoValor);

	void eliminar(int posicion);

	void concatenar(ListaContigua *listaAConcatenar);

	int buscar(int elementoABuscar);

	~ListaContigua();
};








