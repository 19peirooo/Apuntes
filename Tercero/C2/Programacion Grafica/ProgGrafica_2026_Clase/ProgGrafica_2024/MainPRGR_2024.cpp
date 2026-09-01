#define GLAD_BIN // Activador de OpenGL. ESTA MACRO SOLO APARECE UNA VEZ EN EL ARCHIVO QUE CONTENGA EL MAIN()

#include <iostream>

#include "common.h"
#include "EventManager.h"
#include "Object3D.h"
#include "Render.h"
#include "System.h"
using namespace std;


int main(int argc, char** argv)
{

	System::render = new Render();
	
	auto ship = new Ship("data/nave.frs");
	ship->mat->alpha = 1.0f;
	ship->position.y = -5;
	ship->rotacion.z = 90;

	auto enemy = new Enemy("data/nave.frs");
	ship->mat->alpha = 1.0f;
	ship->position.y = 5;
	ship->rotacion.z = -90;

	System::render->addObject(ship);
	System::render->addObject(enemy);
	System::render->mainLoop(); 
	
	return 0;

}