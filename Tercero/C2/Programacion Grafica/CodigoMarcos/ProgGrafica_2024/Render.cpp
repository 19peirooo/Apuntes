#include "Render.h"
#include "EventManager.h"



Render::Render()
{

    if (glfwInit() != GLFW_TRUE) //si no es "true", errores
    {
        cout << "ERROR Iniciando GLFW\n";
    }
    else { //código opengl
#ifdef __APPLE__
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif

        this->window = glfwCreateWindow(640, 480, "PRGR 2026",
            nullptr, nullptr);

        glfwMakeContextCurrent(window);

        gladLoadGL(glfwGetProcAddress); //usarla después de haber iniciado GLFW

        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
        //		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

        //bucle de renderizado
        this->salir = false;
        EventManager::initEventManager(window);

        //Object3D triangulo;
        //glEnable(GL_DEPTH_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }
}

void Render::setupObject(Object3D* obj)
{
    //generar buffers
    bufferObject_t bo = { 0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF };
    glGenVertexArrays(1, &bo.bufferId); //generar lista de buffers
    glGenBuffers(1, &bo.vertexBufferId); //genera un buffer de vértices
    glGenBuffers(1, &bo.indexBufferId); //genera un buffer de ids de vértice
    //copiar datos
        //activar buffer
    glBindVertexArray(bo.bufferId);//activar lista de buffers
    glBindBuffer(GL_ARRAY_BUFFER, bo.vertexBufferId); //activar buffer de vertices
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_t) * obj->vertexList.size(),
        obj->vertexList.data(), GL_STATIC_DRAW);    //copiar datos a buffer


    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bo.indexBufferId); //activar buffer de identificadores
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * obj->indexList.size(),
        obj->indexList.data(), GL_STATIC_DRAW);    //copiar datos a buffer

    //guardar identificadores
    bufferObjectList[obj->objectId] = bo;

}

void Render::addObject(Object3D* obj)
{
    //setup de objeto
    setupObject(obj);
    //añadirlo a lista de futuros objetos
    nextObjectList.push_back(obj);
}

void Render::updateObjects(double timeStep)
{
    cam->moveObject(timeStep);
    luz->moveObject(timeStep);

    for (auto& obj : objectList)
    {
        obj->moveObject(timeStep);//actualizo posiciones
        //actualizo collider
        obj->coll->updateTree(obj->coll->root,obj->computeModelMatrix());
    }
    //eliminar objetos desactivados
    map<float,vector<Object3D*>> aux;
    for (auto& obj : objectList)
    {
        if (!obj->shouldDelete)
        {
            float dist = 0;
            dist = distance(cam->pos, obj->posicion);
            aux[dist].push_back(obj);
           
        }
        else
            //eliminar de sistema
            delete obj;
    }
    //añadir objetos nuevos a lista activa
    for (auto& obj : nextObjectList)
    {    
        float dist = 0;
        dist = distance(cam->pos, obj->posicion);
        aux[dist].push_back(obj);
    }
    //intercambiar listas
    objectList.clear();
    for (auto l = aux.rbegin(); l != aux.rend(); ++l) 
    {
        int size = l->second.size();
        int origSize = objectList.size();
        objectList.resize(origSize + size);
        std::memcpy(objectList.data()+origSize,
                    l->second.data(),
                    size*sizeof(Object3D*));
    }
    nextObjectList.clear();
}

void Render::drawObjects()
{
    //por cada objeto
    for(auto& obj: objectList){
        //setear buffers
        obj->prg->useProgram();
        auto bo = bufferObjectList[obj->objectId]; //recuperar lista buffers
        glBindVertexArray(bo.bufferId);//activar lista de buffers
        glBindBuffer(GL_ARRAY_BUFFER, bo.vertexBufferId); //activar buffer de vertices
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bo.indexBufferId); //activar buffer de identificadores


        matrix4x4f model = obj->computeModelMatrix();
        //setear matriz modelo
        //matriz Modelo Vista Proyección
        

        auto mvp= transpose(
                            cam->computeProjectionMatrix(-0.001f,1000.0f, 3.1416f/4.0f, 4.0f/3.0f)*
                            cam->computeViewMatrix()*
                            model);



        obj->prg->setMatrix(mvp, "MVP");
        obj->prg->setMatrix(transpose(model), "M");
        obj->prg->setCamera(cam);
        obj->prg->setLight(luz);
        obj->prg->setMaterial(obj->mat);
        //describir datos:
        obj->prg->setAttributeData("vPos",4,GL_FLOAT, sizeof(vertex_t),(void*)offsetof(vertex_t, posicion));
        obj->prg->setAttributeData("vColor", 4, GL_FLOAT, sizeof(vertex_t), (void*)offsetof(vertex_t, color));
        obj->prg->setAttributeData("vNormal", 4, GL_FLOAT, sizeof(vertex_t), (void*)offsetof(vertex_t, normal));
        obj->prg->setAttributeData("vTextureCoords", 4, GL_FLOAT,
                 sizeof(vertex_t), (void*)offsetof(vertex_t, texturaCoords));


        //dibujar
        glDrawElements(GL_TRIANGLES,obj->indexList.size(), GL_UNSIGNED_INT, nullptr);
    }

}

void Render::mainLoop()
{
    double lastTime = 0;
    double newTime = (glfwGetTime());
    double deltaTime = newTime - lastTime;

    while (!salir)
    {

        //hacer cosas
            //calcular tiempo de render
        newTime = (glfwGetTime());
        deltaTime = newTime - lastTime;
        lastTime = newTime;

        updateObjects(deltaTime);

        if (EventManager::keyMap[GLFW_KEY_ESCAPE] || glfwWindowShouldClose(window))
            salir = true;
        //limpiar 
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        //dibujar
        drawObjects();
        //intercambiar buffers
        glfwSwapBuffers(window);
        //poll de eventos
        EventManager::updateEvents();

    }
    glfwTerminate();//última función, libera memoria GLFW
}
