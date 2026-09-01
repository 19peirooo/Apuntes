#include "Object3D.h"
#include "EventManager.h"
#include "System.h"

Object3D::Object3D()
{
	objId = idCounter++;
	vertexList = { 
		{{-0.5,0.5,0,1},{1,0,0,1}}, //Superior Izq
		{{0.5,0.5,0,1},{1,0,1,0}}, //Superior Der
		{{-0.5,-0.5,0,1},{1,1,0,1}}, //Inferior Izq
		{{0.5,-0.5,0,1},{0,0,1,1}} // Inferior Der
	};

	indexList = { 0,1,2 , 2,1,3 };

	prg = new Shader();
	prg->addShader("data/shader.vertex");
	prg->addShader("data/shader.fragment");
	prg->linkProgram();

	computeNormals();
}

Object3D::Object3D(string frsModel)
{
    this->frsModel = frsModel;
    objId = idCounter++;
    loadFromFile();
    //crear collider
    Vector4f max = this->vertexList[0].position;
    Vector4f min = this->vertexList[0].position;
    
    for (auto& v : vertexList) {
        max.x = fmaxf(v.position.x,max.x);
        max.y = fmaxf(v.position.y, max.y);
        max.z = fmaxf(v.position.z, max.z);

        min.x = fminf(v.position.x, min.x);
        min.y = fminf(v.position.y, min.y);
        min.z = fminf(v.position.z, min.z);
    }


    auto& tex = this->mat->texture;
    Vector4f pixelSize;
    pixelSize.x = (max.x - min.x) / tex->w;
    pixelSize.y = (max.y - min.y) / tex->w;

    Vector4f pixelMax = {-FLT_MAX,-FLT_MAX ,-FLT_MAX ,0 };
    Vector4f pixelMin = { FLT_MAX , FLT_MAX , FLT_MAX , 0};

    this->colliderTree->root = new colliderNode;
    this->colliderTree->root->bv = new Sphere();

    for (int y = 0; y < tex->h; y++) {
        for (int x = 0; x < tex->w; x++) {
            if (tex->rawImage[y * tex->w + x].a > 0) {

                particle3D* p = new particle3D;

                float newX = min.x + (pixelSize.x * x);
                float newY = min.y + (pixelSize.y * y);
                pixelMax.x = newX + pixelSize.x; 
                pixelMax.y = newY + pixelSize.y;

                pixelMin.x = newX; 
                pixelMin.y = newY;

                p->pos = pixelMin + ((pixelMax - pixelMin) / 2); 
                p->tam = pixelMax - pixelMin;
                this->colliderTree->root->bv->addParticle(p);
            }
        }
    }
    ColliderTree<Sphere>::subdivide(colliderTree->root);
}

Matrix4x4f Object3D::computeModelMatrix()
{
    Matrix4x4f T = make_traslate(position.x, position.y, position.z);
    Matrix4x4f R = make_rotate(rotacion.x, rotacion.y, rotacion.z);
    Matrix4x4f S = make_scale(escalado.x, escalado.y, escalado.z);

    return T * R * S;
}

void Object3D::computeNormals()
{
	//reset de normal de vertices
	for (auto v : vertexList) {
		v.normal = { 0,0,0,0 };
	}

	//por cada cara
	auto it = indexList.begin();
	while (it != indexList.end()) {
		int v1 = *it; it++;
		int v2 = *it; it++;
		int v3 = *it; it++;

		Vector4f arista1 = normalize(vertexList[v2].position - vertexList[v1].position);
		Vector4f arista2 = normalize(vertexList[v3].position - vertexList[v1].position);

		//calcular normal
		Vector4f normal = arista1 ^ arista2;
		//interpolae con normal es de vertices compartidos por cara
		vertexList[v1].normal = vertexList[v1].position + normal;
		vertexList[v2].normal = vertexList[v2].position + normal;
		vertexList[v3].normal = vertexList[v3].position + normal;
	}

	// normalizacion de normales
	for (auto v : vertexList) {
		v.normal = normalize(v.normal);
	}
		
}

void Object3D::loadFromFile()
{
    typedef enum {
        vertices, faces, normals, colors, textureCoords, done
    }dataTypesReading;
    string textureFile;
    string vertexShader;
    string fragmentShader;

    istringstream lineReader;
    std::ifstream f(frsModel);
    dataTypesReading mode = vertices;
    string line = "";
    do {
        switch (mode)
        {
        case vertices: {
            //leer numVertices
            int numVertex = 0;
            skipComments();
            lineReader >> numVertex;
            vertexList.resize(numVertex);
            for (int i = 0;i < numVertex;i++) {
                skipComments();
                lineReader = istringstream(line);
                lineReader >> vertexList[i].position.x;
                lineReader >> vertexList[i].position.y;
                lineReader >> vertexList[i].position.z;
                vertexList[i].position.w = 1.0f;
            }
            mode = faces;
        }break;
        case faces: {
            //leer numVertices
            int numFaces = 0;
            skipComments();
            lineReader >> numFaces;
            indexList.resize(numFaces * 3);
            for (int i = 0;i < numFaces;i++) {
                skipComments();
                lineReader = istringstream(line);
                lineReader >> indexList[i * 3] >> indexList[i * 3 + 1] >> indexList[i * 3 + 2];
            }
            mode = colors;
        }break;

        case colors: {
            //leer numVertices
            int numColors = 0;
            skipComments();
            lineReader >> numColors;
            for (int i = 0;i < numColors;i++) {
                skipComments();
                readMultipleData();
                int numVertexIds = data.size() - 4;
                Vector4f color = make_vector4f(
                    data[numVertexIds],
                    data[numVertexIds + 1],
                    data[numVertexIds + 2],
                    data[numVertexIds + 3]
                );
                for (int j = 0;j < numVertexIds;j++) {
                    vertexList[data[j]].color = color;
                }
            }
            mode = normals;
        }break;


        case normals: {
            //leer numVertices
            int numNormals = 0;
            skipComments();
            lineReader >> numNormals;
            for (int i = 0;i < numNormals;i++) {
                skipComments();
                readMultipleData();

                int numVertexIds = data.size() - 4;
                Vector4f normal = make_vector4f(
                    data[numVertexIds],
                    data[numVertexIds + 1],
                    data[numVertexIds + 2],
                    data[numVertexIds + 3]
                );
                for (int j = 0;j < numVertexIds;j++) {
                    vertexList[data[j]].normal = normal;
                }
            }
            mode = textureCoords;
        }break;

        case textureCoords: {
            //leer numVertices
            int numTC = 0;
            skipComments();
            lineReader >> numTC;
            for (int i = 0;i < numTC;i++) {
                skipComments();
                readMultipleData();
                int numVertexIds = data.size() - 2;
                float textureCoord[2] = {
                    data[numVertexIds],
                    data[numVertexIds + 1] };
                for (int j = 0;j < numVertexIds;j++) {
                    vertexList[data[j]].textureCoords.x = textureCoord[0];
                    vertexList[data[j]].textureCoords.y = textureCoord[1];
                }
            }
            skipComments();
            lineReader >> textureFile;
            skipComments();
            lineReader >> vertexShader;
            skipComments();
            lineReader >> fragmentShader;

            mode = done;
        }break;
        };

    } while (!f.eof() && mode != done); //Saltar comentarios iniciales
    prg = new Shader();
    prg->addShader(vertexShader);
    prg->addShader(fragmentShader);
    prg->linkProgram();

    this->mat->texture = new Texture(textureFile);
    mat->usaTextura = true;

}

void Ship::moveObject(double timeStep) {
    float speed = 0.5f;
    if (EventManager::keyMap[GLFW_KEY_A]) {
        position.x -= speed * timeStep;
    }

    if (EventManager::keyMap[GLFW_KEY_D]) {
        position.x += speed * timeStep;
    }

    if (EventManager::keyMap[GLFW_KEY_SPACE]) {
        //Añadir bala
        Bullet* b = new Bullet("data/bullet.frs");
        b->position = position;
        b->rotacion.z = 90;
        b->escalado = { 0.25,0.25,0.25,1 };
        b->dir = { 0,1,0,0 };
        System::render->addObject(b);
    }
}

void Bullet::moveObject(double timeStep)
{
    float speed = 5.0f;
  

    this->position = this->position + this->dir*speed * timeStep;

    if (position.y > 10) {
        //Borrarse
        this->shouldDelete = true;
    }

    //Si hay colision, borrar
    auto collList = System::getCollisions(this, enemyType);
    if (dir.y > 0 && collList.size() > 0) {
        for (auto& o : collList) {
            o->shouldDelete = true; 
        }
    }

}

/*void Object3D::moveObject(double timeStep)
{
    float speed = 0;
    if (EventManager::keyMap[GLFW_KEY_A]) {
        position.x -= speed * timeStep;
    }
    else if (EventManager::keyMap[GLFW_KEY_D]) {
        position.x += speed * timeStep;
    }
    else if (EventManager::keyMap[GLFW_KEY_W]) {
        position.y -= speed * timeStep;
    }
    else if (EventManager::keyMap[GLFW_KEY_S]) {
        position.y += speed * timeStep;
    }

    if (EventManager::keyMap[GLFW_KEY_D]) {
        this->mat->usaTextura = true;
    }

    if (EventManager::keyMap[GLFW_KEY_A]) {
        this->mat->usaTextura = false;
    }

    if (EventManager::keyMap[GLFW_KEY_T]) {
        int w = mat->texture->w;
        int h = mat->texture->h;
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                if (i == j) {
                    mat->texture->rawImage[i * w + j] = { 0,0,0,1 };
                }
            }
        }
        mat->texture->updateTexture();
    }
}*/

void Enemy::moveObject(double timeStep)
{

    float speed = 1.0f;
    this->position.x += speed * timeStep; 

    if (position.x > 5) 
        this->position.x = -5;
    
    if (rand()%180 == 0) { //Si debo crear una bala
        //Añadir bala
        Bullet* b = new Bullet("data/bullet.frs");
        b->position = position;
        b->rotacion.z = 90;
        b->escalado = { 0.25,0.25,0.25,1 };
        b->dir = { 0,-1,0,0 };
        System::render->addObject(b);
    }

}
