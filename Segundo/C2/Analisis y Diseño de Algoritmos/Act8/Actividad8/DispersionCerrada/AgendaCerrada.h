#include <string>

using namespace std;

// Tabla hash que guarda los nombres de los estudiantes de una universidad
class Agenda
{

protected:
	int capacidad; // Capacidad de la tabla. Permanece invariante a lo largo de la vida del objeto

	// Vectores que guardar�n la informaci�n de la tabla hash
	string *nombres; // Vector con los nombres de los contactos
	bool *ocupada;   // Vector con los flags que indican si una posici�n est� vac�a (false) o no (true). Si esta vacia, tiene basura.
	long *telefonos; // Vector con los telefonos de los contactos
	bool *borradas; //Vector con los flags que indican si una posicion ha sido borrada
	// M�todo de hashing
	int obtenerPosicion (long telefono);

public:

	// Constructor
	Agenda(int capacidad);

	// Comprueba si un contacto est� o no en la tabla hash
	bool existeContacto (long telefono);

	// Obtiene un contacto (su nombre) a partir de su telefono
	string getContacto (long telefono);

	int buscarContacto(long telefono);

	int buscarHueco(long telefono);

	bool isLlena();

	// Inserta un contacto en la tabla
	void introducirContacto (long telefono, string contacto);

	// Elimina un contacto de la tabla
	void eliminarContacto (long telefono);

	// Imprime toda la tabla hash. Viola el principio de separaci�n entre interfaz y modelo
	void imprimir();


	// Destructor
	~Agenda();

};

