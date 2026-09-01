#include "EventManager.h"

void EventManager::initEventManager(GLFWwindow* window)
{

    glfwSetKeyCallback(window,keyboardManager );
    glfwSetCursorPosCallback(window, mouseMoveManager);
    int w, h;
    
    glfwGetWindowSize(window, &w, &h);
    EventManager::mouseState.posX = w / 2;
    EventManager::mouseState.posY = h / 2;
    glfwSetCursorPos(window, EventManager::mouseState.posX, EventManager::mouseState.posY);

    EventManager::window = window;
}

void EventManager::keyboardManager(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    switch (action) {
        case GLFW_PRESS: {
            EventManager::keyMap[key] = true;
    
        }break;
        case GLFW_RELEASE: {
            EventManager::keyMap[key] = false;
        }break;   
    
    }
}

void EventManager::mouseMoveManager(GLFWwindow* window, double xpos, double ypos)
{
    EventManager::mouseState.velX = EventManager::mouseState.posX - xpos;
    EventManager::mouseState.velY = EventManager::mouseState.posY - ypos;

    if (std::abs(EventManager::mouseState.velX) > 320) EventManager::mouseState.velX = 0;
    if (std::abs(EventManager::mouseState.velY) > 240) EventManager::mouseState.velY = 0;


    EventManager::mouseState.posX = xpos;
    EventManager::mouseState.posY = ypos;

}

void EventManager::updateEvents()
{
    glfwPollEvents();//actualizar resto de eventos de ventana
}


