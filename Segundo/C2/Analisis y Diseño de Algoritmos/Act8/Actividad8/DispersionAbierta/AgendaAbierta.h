#include <string>
#include "ListaEnlazada.h"

using namespace std;

// Tabla hash que guarda los nombres de los estudiantes de una universidad
class Agenda
{

protected:
	int capacidad; // Capacidad de la tabla. Permanece invariante a lo largo de la vida del objeto

	int n;

	ListaEnlazada *tabla;

	int obtenerPosicion (long telefono);

public:

	// Constructor
	Agenda(int capacidad);

	// Comprueba si un contacto est� o no en la tabla hash
	bool existeContacto (long telefono);

	// Obtiene un contacto (su nombre) a partir de su telefono
	string getContacto (long telefono);

	// Inserta un contacto en la tabla
	void introducirContacto (long telefono, string contacto);

	// Elimina un contacto de la tabla
	void eliminarContacto (long telefono);

	// Imprime toda la tabla hash. Viola el principio de separaci�n entre interfaz y modelo
	void imprimir();

	// Destructor
	~Agenda();

};

