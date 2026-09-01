#pragma once
#include "Object3D.h"
#include "Camera.h"
#include "Luz.h"
#include "libMath.h"

class Render
{
	public:
		typedef struct {
			unsigned int bufferId;
			unsigned int vertexBufferId;
			unsigned int indexBufferId;
		} bufferObject_t;

		vector<Object3D*> objectList; //Lista de objetos que se estan tratando
		vector<Object3D*> nextObjectList;
		map<unsigned int, bufferObject_t> bufferObjectsList;
		bool salir = false;
		GLFWwindow* window = nullptr;

		Camera* cam=new Camera({ 0,0,20,1 }, { 0, 0, 0, 1 });
		Luz* luz = new Luz({0,0,3,1});
		
		Render();

		//Crea datos en gpu
		void setupObject(Object3D* obj);

		//actualiza estado de objetos
		void updateObjects(double deltaTime);

		void addObject(Object3D* obj);

		//dibujar
		void drawObjects();

		//bucle principal
		void mainLoop();

};

