//ESTA MACRO SÓLO APARECE UNA VEZ EN EL ARCHIVO QUE CONTENGA EL MAIN()
#define GLAD_BIN
#include "common.h"
#include "Object3D.h"
#include <iostream>
#include "EventManager.h"
#include "Render.h"
#include "System.h"

int main(int argc, char** argv)
{
	//inicializar GLFW
	System::render = new Render(); //crear ventanas opengl
	//auto obj = new Ship("data/ship.frs");
	//obj->rotacion.z = 90.0f;

	auto ship = new Ship("data/ship.frs");
	ship->mat->alpha = 1.0;
	ship->posicion.y = -5;
	ship->rotacion.z = 90;

	auto enemy = new Enemy("data/ship.frs");
	enemy->mat->alpha = 1.0;
	enemy->posicion.y = 5;
	enemy->rotacion.z = -90;

	System::render->addObject(ship); //copiar objeto a gpu
	System::render->addObject(enemy); //copiar objeto a gpu
	System::render->mainLoop(); //dibujar!


	return 0;
}