#include "Render.h"
#include "EventManager.h"


Render::Render()
{
	// Inicializar GLFW

	if (glfwInit() != GLFW_TRUE) { // Si no es "true", errores

		cout << "ERROR Iniciando GLFW\n";
	}
	else { // Código OpenGl

		// Crear ventana para el contexto
		this->window = glfwCreateWindow(640, 480, "PRGR 2026", nullptr, nullptr);

		// Información de OpenGl para pintar en la ventana creada
		glfwMakeContextCurrent(this->window);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
		gladLoadGL(glfwGetProcAddress); //usarla después de haber iniciado GLFW

		this->salir = false;
		EventManager::initEventManager(this->window);

		//glEnable(GL_DEPTH_TEST);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}
}


void Render::setupObject(Object3D* obj)
{
	// generar buffers
	bufferObject_t bo = { -1, -1, -1, };
	glGenVertexArrays(1, &bo.bufferId);	// generar lista de buffers
	glGenBuffers(1, &bo.vertexBufferId);	// genera un buffer de vértices
	glGenBuffers(1, &bo.indexBufferId);	// genera un buffer de ids de vértices
	// copiar datos
		// activar buffer (enlazar el buffer)
	glBindVertexArray(bo.bufferId);	// Activar lista de buffers
	glBindBuffer(GL_ARRAY_BUFFER, bo.vertexBufferId);			// activar buffer de vertices
	// Copiar datos a buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_t) * obj->vertexList.size(), obj->vertexList.data(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bo.indexBufferId);	// activar buffer de ids de buffers
	//Copiar datos a buffer
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * obj->indexList.size(), obj->indexList.data(), GL_STATIC_DRAW);

	// guardar  identificadores
	bufferObjectsList[obj->objId] = bo;
}

void Render::updateObjects(double timeStep)
{
	cam->moveCamera(timeStep);
	for (auto& obj : objectList) {
		obj->moveObject(timeStep); //actualizo posiciones
		obj->colliderTree->updateTree(obj->colliderTree->root,obj->computeModelMatrix());
	}

	// eliminar objetos desactivados
	map<float,vector<Object3D*>> aux;
	for (auto& obj : objectList) {
		
		if (!obj->shouldDelete) {

			float dist = 0;
			dist = distance(cam->pos, obj->position);
			aux[dist].push_back(obj);
		}
		else {
			delete obj;
		}

	}

	// añadir objetos nuevos a la lista
	for (auto& obj : nextObjectList) {
		float dist = 0;
		dist = distance(cam->pos, obj->position);
		aux[dist].push_back(obj);
	}

	objectList.clear();
	for (auto l = aux.rbegin(); l != aux.rend(); l++) {
		int size = l->second.size();
		int origSize = objectList.size();
		objectList.resize(objectList.size() + size);
		std::memcpy(objectList.data() + origSize, l->second.data(), size * sizeof(Object3D*));
	}
	nextObjectList.clear();
}

void Render::addObject(Object3D* obj)
{
	//steup de objeto
	setupObject(obj);
	nextObjectList.push_back(obj);
}

void Render::drawObjects()
{
	// por cada objeto
	for (auto& obj : objectList) {
		auto bo = bufferObjectsList[obj->objId];					// recuperar lista buffers
		// setear buffers
		obj->prg->useProgram();										//activar shader
		glBindVertexArray(bo.bufferId);								// Activar lista de buffers
		glBindBuffer(GL_ARRAY_BUFFER, bo.vertexBufferId);			// activar buffer de vertices
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bo.indexBufferId);	// activar buffer de ids de buffers

		// setear matriz modelo
		Matrix4x4f model = obj->computeModelMatrix();
		Matrix4x4f mvp = transpose(cam->computeProjectionMatrix(-0.001f, 1000.0f, 45, 4.0f / 3.0f) * cam->computeViewMatrix() * model);
		obj->prg->setMatrix(mvp, "MVP");
		obj->prg->setMatrix(model, "M");
		obj->prg->setCamera(cam);
		obj->prg->setLight(luz);
		obj->prg->setMaterial(obj->mat);
		// describir datos
		obj->prg->setAttributeData("vPos", 4, GL_FLOAT, sizeof(vertex_t), (void*)offsetof(vertex_t, position));
		obj->prg->setAttributeData("vColor", 4, GL_FLOAT, sizeof(vertex_t), (void*)offsetof(vertex_t, color));
		obj->prg->setAttributeData("vNormal", 4, GL_FLOAT, sizeof(vertex_t), (void*)offsetof(vertex_t, normal));
		obj->prg->setAttributeData("vTextureCoords", 4, GL_FLOAT, sizeof(vertex_t), (void*)offsetof(vertex_t, textureCoords));

		// dibujar
		glDrawElements(GL_TRIANGLES, obj->indexList.size(), GL_UNSIGNED_INT, nullptr);
	}
}

void Render::mainLoop()
{
	float lastTime = 0;
	double newTime = glfwGetTime();
	double deltaTime = newTime - lastTime;

	while (!salir) {

		// hacer cosas
		// Calcular tiempo de render
		newTime = (glfwGetTime());
		deltaTime = newTime - lastTime;
		lastTime = newTime;

		updateObjects(deltaTime);

		if (EventManager::keyMap[GLFW_KEY_ESCAPE] || glfwWindowShouldClose(window)) {
			salir = true;
		}
		// limpiar buffers
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		// dibujar
		drawObjects();
		// intercambiar buffer
		glfwSwapBuffers(window);
		// poll de eventos
		EventManager::updateEvents();
	}

	glfwTerminate(); // Última función, libera memoria GLFW
}