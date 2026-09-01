#include "Luz.h"
#include "EventManager.h"
Luz::Luz(vec4float pos, vec4float color, float Ia, float Id, float Is)
    : posicion(pos), color(color), Ia(Ia), Id(Id), Is(Is)
{
}


void Luz::moveObject(double timeStep) {

    if (EventManager::keyMap[GLFW_KEY_1])
        activa = true;

    if (EventManager::keyMap[GLFW_KEY_0])
        activa = false;
}
