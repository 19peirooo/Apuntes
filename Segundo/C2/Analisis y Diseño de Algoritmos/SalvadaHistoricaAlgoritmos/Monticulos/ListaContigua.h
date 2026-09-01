#pragma once

// Numero de posiciones en que se incrementa/decrementa la capacidad de la ListaContigua cada vez que es necesario
// Precondici�n: INCREMENTO >= 1
#define INCREMENTO 2

// Clase que representa a una lista contigua en memoria y cuya capacidad se redimensiona autom�ticamente
// de modo que el usuario no tiene que preocuparse por su capacidad
class ListaContigua
{
	// Puntero que apuntar� a la zona de memoria en donde empieza la ListaContigua
	int *vector;

	// Numero actual de elementos que tiene la ListaContigua
	// Precondici�n: n>=0
	int n;

	// Capacidad actual de la ListaContigua
	// Precondiciones: capacidad >= n
	int capacidad;

	// Nos dice si la ListaContigua est� llena o no.
	// Retorno: verdadero si est� llena, falso si no est� llena
	// Complejidad temporal y espacial: O(1)
	bool isLlena();

public:

	// Constructor. Crea una ListaContigua de tama�o 0
	// Complejidad temporal y espacial: O(1)
	ListaContigua();

	// Devuelve un elemento de la ListaContigua
	// Par�metro: la posici�n del elemento
	// Retorno: el elemento encontrado en esa posici�n
	// Precondiciones: posicion en [0, n-1]
	// Complejidad temporal y espacial: O(1)
	int getValor(int posicion);

	// Modifica un elemento de la ListaContigua
	// Par�metros:
	// - posicion: la posici�n del elemento que queremos modificar
	// - nuevoValor: el nuevo valor del elemento
	// Precondiciones:
	// - posicion en [0, n-1]
	// Complejidad temporal y espacial: O(1)
	void setValor(int posicion, int nuevoValor);

	// Devuelve el tama�o actual de la ListaContigua
	// Retorno: n�mero actual de elementos de la ListaContigua
	// Complejidad temporal y espacial: O(1)
	int getN(); 

	// Devuelve la capacidad actual de la ListaContigua
	// Retorno: n�mero m�ximo que actualmente podr�a contener la ListaContigua
	// Complejidad temporal y espacial: O(1)
	int getCapacidad(); 

	// Inserta un nuevo elemento en la �ltima posici�n de la ListaContigua, 
	// ampliando previamente la capacidad si es necesario
	// Par�metros:
	// - nuevoValor: el nuevo elemento que queremos poner
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(n)
	void insertarAlFinal (int nuevoValor);

	// Elimina el elemento de la �ltima posici�n de la ListaContigua,
	// disminuyendo posteriormente la capacidad si es necesario
	// Complejidad temporal: O(1)
	// Complejidad espacial: O(1)
	void eliminarAlFinal();

	// Inserta un nuevo elemento en una posici�n de la lista, dejando primero un hueco para meterlo ah�
	// Los elementos que hab�a desde la posici�n hasta el final de la ListaContigua se desplazar�n una posici�n a la derecha
	// Par�metros:
	// - posici�n: la posici�n en donde queremos poner el nuevo elemento. Si es 0 se inserta al principio, si es n se inserta al final
	// - nuevoValor: el nuevo elemento que queremos poner
	// Precondiciones:
	// - posicion en [0, n]
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(n)
	void insertar(int posicion, int nuevoValor);

	// Elimina un elemento en una posici�n dada.
	// Los elementos que hab�a desde posicion+1 hasta el final de la ListaContigua se desplazar�n una posici�n a la izquierda
	// Par�metros:
	// - posicion: la posici�n del elemento que queremos borrar. Si es 0 se elimina el primero y si es n-1 se elimina el �ltimo
	// Precondiciones:
	// - posicion en [0, n-1]
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(n), por memmove()
	void eliminar(int posicion);

	// Concatena una lista al final de la lista actual. 
	// Cada uno de los elementos de la lista a concatenar se copian, en orden, al final de la lista actual
	// Par�metro: puntero a la lista cuyos elementos queremos concatenar al final de nuestra lista
	// Precondici�n: listaAConcatenar!=NULL
	// Complejidad temporal: O(n+m), siendo m = listaAConcatenar.getN()
	// Complejidad espacial: O(n+m), siendo m = listaAConcatenar.getN()
	void concatenar(ListaContigua *listaAConcatenar);

	// Busca la posici�n de un elemento en la ListaContigua
	// Par�metro: el elemento a buscar
	// Retorno: posici�n del elemento (de 0 a n-1) si se encuentra, o -1 en caso contrario
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(1)
	int buscar(int elementoABuscar);

	// Destructor. Libera memoria
	// Complejidad temporal y espacial: O(1)
	~ListaContigua();
};








