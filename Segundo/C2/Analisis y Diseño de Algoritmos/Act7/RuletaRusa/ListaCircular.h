#include<cstdlib>
#include "Nodo.h"

class ListaCircular
{
	Nodo *lista;

	int n;

	Nodo * getNodo (int posicion);

public:

	ListaCircular();

	string getValor(int posicion);

	void setValor(int posicion, string nuevoValor);

	int getN(); 

	void insertar (int posicion, string nuevoValor);

	void eliminar (int posicion);

	void girar (int p);

	~ListaCircular();
};







