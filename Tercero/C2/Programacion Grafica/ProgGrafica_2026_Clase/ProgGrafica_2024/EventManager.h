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
	}mouse_t;
	
	static inline mouse_t mouseState; //Eventos de raton
	static inline map<int, bool> keyMap; // estado de teclado
	static inline GLFWwindow* window = nullptr;

	static void initEventManager(GLFWwindow* window);

	static void keyboardManager(GLFWwindow* window, int key, int scancode, int action, int mods);	// eventos de teclado
	static void mouseMoveManager(GLFWwindow* window, double xpos, double ypos);
	static void mouseButtonManager(GLFWwindow* window, int button, int action, int mods);

	static void updateEvents();
};