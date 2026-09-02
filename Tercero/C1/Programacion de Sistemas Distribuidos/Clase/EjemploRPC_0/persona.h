#pragma once
#include <string>

using namespace std;

class Persona{
		private:
			string nombre;
			int edad;
		public:
			Persona();
			Persona(string nombre, int edad);
			~Persona();
			void setNombre(string nombre);
			void setEdad(int edad);
			string getNombre();
			int getEdad();
};
