#include "Luz.h"
#include "EventManager.h"
using namespace libMath;

Luz::Luz(Vector4f pos, Vector4f color, float Ia, float Id, float Is)
	: posicion(pos), color(color), Ia(Ia), Id(Id), Is(Is)
{

}

void Luz::moveObject(double timeStep)
{
	if (EventManager::keyMap[GLFW_KEY_1]) {
		active = true;
	}
	if (EventManager::keyMap[GLFW_KEY_0]) {
		active = false;
	}

}
