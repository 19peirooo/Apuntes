#pragma once
#include<string>
using namespace std;
#define assertdomjudge(x) if(!(x)) {cout << "ERROR" << endl; exit;}

// Estructura que representa una Licencia
struct Licencia {
	long codigo;
	string herramienta;
};
