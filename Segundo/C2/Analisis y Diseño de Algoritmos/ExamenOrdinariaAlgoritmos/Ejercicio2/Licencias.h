#include <string>
#include "ListaEnlazada.h"

using namespace std;

class Licencias
{

	protected:

		int capacidad; 
		int n; 

		ListaEnlazada *tabla; 
	public:

		Licencias(int capacidad);

		int obtenerPosicion (long codigo);

		void insertarLicencia (long codigo, string herramienta);

		void eliminarLicencia (long codigo);

		void imprimir();

};

