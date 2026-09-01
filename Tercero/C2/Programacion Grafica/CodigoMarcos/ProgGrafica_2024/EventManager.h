#pragma once
#include "common.h"
using namespace std;
class EventManager
{
public:  
    
    
    typedef struct {
        double posX, posY;
        double velX, velY;
        map<int, bool> mouseMap;
    
    } mouse_t;

    static inline map<int, bool> keyMap;//estado de teclado
    static inline mouse_t mouseState; //eventos de ratón
    static inline GLFWwindow* window = nullptr;

    static void initEventManager(GLFWwindow* window);

    static void keyboardManager(GLFWwindow* window, int key, int scancode,
        int action, int mods);//eventos de teclado

    static void mouseMoveManager(GLFWwindow* window, double xpos, double ypos);//movimientos de ratón

    static void updateEvents();
};

