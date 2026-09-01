#pragma once
#include "Object3D.h"
#include "Camera.h"
#include "Luz.h"
class Render
{
    public:
        typedef struct {
            unsigned int bufferId;
            unsigned int vertexBufferId;
            unsigned int indexBufferId;
        } bufferObject_t;

        //camara que mira al centro {0,0,0} desde {0,0,3}
        Camera* cam = new Camera({ 0,0,20,1 }, { 0,0,0,1 });
        Luz* luz = new Luz({ 0,0,3,1 });

        vector<Object3D*> objectList; //lista de objetos que se tratan ahora
        vector<Object3D*> nextObjectList; //lista de objetos "actualizados"
   
        map<unsigned int, bufferObject_t> bufferObjectList; //lista de bufferObjects por objeto
        bool salir = false;
        GLFWwindow* window = nullptr;


        Render();
        //crea datos en gpu
        void setupObject(Object3D* obj);

        void addObject(Object3D* obj);
        //actualiza estado de objetos
        void updateObjects(double timeStep);

        void drawObjects();

        //bucle principal renderizado
        void mainLoop();

};

