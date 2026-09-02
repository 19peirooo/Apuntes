#pragma once
#include "utils.h"
#include "persona.h"
using namespace std;
typedef enum{

	PersonaF,//constructor defecto
	PersonaParamsF,//constructor parametros
	PersonaDF,//destructor
	setNombreF,
	setEdadF,
	getNombreF,
	getEdadF,
	
	ackMSG
}personaFuncs;

class clientManager{

		public:
		
			static inline map<int, Persona> clients;
			static inline map<Persona*,connection_t > connectionIds;
			
			
			
			static inline bool salir=false;			
			static void atiendeCliente(int clientId);
};