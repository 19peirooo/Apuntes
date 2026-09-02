#include "persona.h"

Persona::Persona():nombre(""),edad(0){}
Persona::Persona(string nombre, int edad):nombre(nombre),edad(edad){}
Persona::~Persona(){}
	
void Persona::setNombre(string nombre){this->nombre=nombre;}
void Persona::setEdad(int edad){this->edad=edad;}
string Persona::getNombre(){return nombre;}
int Persona::getEdad(){return edad;}
