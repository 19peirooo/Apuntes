#include "Object3D.h"
#include "EventManager.h"
Object3D::Object3D()
{
    objectId = idCounter++;

    vertexList = 
    {       
        {{ -0.5,  0.5 , 0, 1 },{1,0,0,1}}, //vertice superior izquierda de triangulo
        {{  0.5,  0.5 , 0, 1 },{1,0,0,1}}, //vertice superior derecha de triangulo
        {{ -0.5, -0.5 , 0, 1 },{1,1,0,1}}, // vertice inferior izquierda
        {{  0.5, -0.5 , 0, 1 },{0,0,1,1}}// vertice inferior derecha
    };

    indexList = { 0,1,2 , 2,1,3 };

    prg = new Shader();
    prg->addShaderProgram("data/shader.vertex");
    prg->addShaderProgram("data/shader.fragment");
    prg->linkProgram();

    computeNormals();

}

Object3D::Object3D(string frsModel)
{
    objectId = idCounter++;

    this->frsModel = frsModel;
    loadFromFile();
    //crear collider
    vec4float max = this->vertexList[0].posicion;
    vec4float min = this->vertexList[0].posicion;

    for (auto& v : vertexList) {
        max.x = std::fmaxf(v.posicion.x, max.x);
        max.y = std::fmaxf(v.posicion.y, max.y);
        max.z = std::fmaxf(v.posicion.z, max.z);
        min.x = std::fminf(v.posicion.x, min.x);
        min.y = std::fminf(v.posicion.y, min.y);
        min.z = std::fminf(v.posicion.z, min.z);
    }
    vec4float pixelSize;
    auto tex = this->mat->textura;

    pixelSize.x = (max.x - min.x) / tex->w;
    pixelSize.y = (max.y - min.y) / tex->h;

    vec4float pixelMax = { -FLT_MAX,-FLT_MAX,0,0 };
    vec4float pixelMin = { FLT_MAX,FLT_MAX,0,0 };;

    coll->root = new colliderNode;
    coll->root->bv = new Sphere();

    for (int y = 0;y < tex->h;y++)
        for (int x = 0;x < tex->w;x++)
        {
            if (tex->rawImage[y * tex->w + x].a > 0)//es un pixel de color
            {
                particle3D* p = new particle3D;//particula con ese pixel

                float newX = min.x + (pixelSize.x * x);
                float newY = min.y + (pixelSize.y * y);

                pixelMax.x = newX + pixelSize.x;
                pixelMax.y = newY + pixelSize.y;

                pixelMin.x = newX;
                pixelMin.y = newY;

                p->pos = pixelMin + (pixelMax - pixelMin) / 2;
                p->size = pixelMax - pixelMin;
                coll->root->bv->addParticle(p);
            }
        }
    ColliderTree<Sphere>::subdivide(coll->root);
}

matrix4x4f Object3D::computeModelMatrix()
{
    matrix4x4f model =
        make_traslate(posicion.x, posicion.y, posicion.z) *
        make_rotate(rotacion.x, rotacion.y, rotacion.z) *
        make_scale(escalado.x, escalado.y, escalado.z);
    return model;
}

/*void Object3D::moveObject(double timeStep)
{
    float speed = 0;
     if (EventManager::keyMap[GLFW_KEY_A])
        posicion.x -= speed * timeStep;

    if (EventManager::keyMap[GLFW_KEY_D])
        posicion.x += speed * timeStep;
        
    if (EventManager::keyMap[GLFW_KEY_D])
        this->mat->usaTextura = false;
    if (EventManager::keyMap[GLFW_KEY_A])
        this->mat->usaTextura = true;

    if (EventManager::keyMap[GLFW_KEY_T])
    {
        int w = mat->textura->w;
        int h = mat->textura->h;
       
        for (int i = 0;i < w;i++)
        {
            for (int j = 0;j < h;j++)
                if (i == j)
                    mat->textura->rawImage[i * w + j] = { 0,0,0,1 };
        }
        mat->textura->updateTexture();
    }
}*/

void Object3D::computeNormals()
{
    //reset de normales de vertices
    for (auto& v : vertexList) {
        v.normal = { 0,0,0,0 };
    }

    //por cada cara
    auto it = indexList.begin();
    while (it != indexList.end()){
        int v1 = *it; it++;
        int v2 = *it; it++;
        int v3 = *it; it++;

        vec4float arista1 = normalize(vertexList[v2].posicion - vertexList[v1].posicion);
        vec4float arista3 = normalize(vertexList[v3].posicion - vertexList[v1].posicion);
        //calcular normal
        vec4float normal = cross(arista1, arista3);
        //interpolar con normales de vertices compartidos por cara

        vertexList[v1].normal = vertexList[v1].normal + normal;
        vertexList[v2].normal = vertexList[v2].normal + normal;
        vertexList[v3].normal = vertexList[v3].normal + normal;
    }


    //normalizacion de normales de vertices
    for (auto& v : vertexList) {
        v.normal = normalize(v.normal);
    }
}




#define skipComments()\
lineReader = istringstream(line);\
 do {\
    std::getline(f >> std::ws, line);\
 } while (line[0] == 'â');\
lineReader = istringstream(line);\

#define readMultipleData()\
vector<float> data;\
while (!lineReader.eof() && lineReader.tellg() != -1)\
{\
    float d = 0;\
    lineReader >> d;\
    data.push_back(d);\
}\
data.pop_back();\


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
                lineReader >> vertexList[i].posicion.x;
                lineReader >> vertexList[i].posicion.y;
                lineReader >> vertexList[i].posicion.z;
                vertexList[i].posicion.w = 1.0f;
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
                vec4float color = make_vec4float(
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
                vec4float normal = make_vec4float(
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
                    vertexList[data[j]].texturaCoords.x = textureCoord[0];
                    vertexList[data[j]].texturaCoords.y = textureCoord[1];
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
    prg->addShaderProgram(vertexShader);
    prg->addShaderProgram(fragmentShader);
    prg->linkProgram();

    mat->textura = new Texture(textureFile);
    mat->usaTextura = true;

}


#include "System.h"

void Ship::moveObject(double timeStep)
{
    float speed = 0.5f;
    if (EventManager::keyMap[GLFW_KEY_A])
        posicion.x -= speed * timeStep;

    if (EventManager::keyMap[GLFW_KEY_D])
        posicion.x += speed * timeStep;

    if (EventManager::keyMap[GLFW_KEY_SPACE])
    {
        Bullet* b = new Bullet("data/ship.frs");
        b->posicion = posicion;
        b->rotacion.z = 90;
        b->escalado = { 0.25,0.25, 0.25 , 1.0f};
        b->direccion = { 0,1,0,0 };
        System::render->addObject(b);
    }
    Sphere* s = (Sphere*)coll;
    cout << s->center.x << " " << s->center.y << " " << s->center.z << endl;

}




void Bullet::moveObject(double timeStep)
{
    float speed = 5.0f;
    this->posicion = posicion+ direccion*speed * timeStep;


    if (posicion.y > 10)
        this->shouldDelete = true;

    //si hay colisiones
    auto collList = System::getCollisions(this, enemyType);
    if (direccion.y > 0 && collList.size() > 0)
        for (auto& o : collList)//recorrer lista
            o->shouldDelete = true; //sumar puntos
      //  cout << "Colision!!\n";

  }

void Enemy::moveObject(double timeStep)
{

    float speed = 1.0f;
    this->posicion.x +=  speed * timeStep;


    if (posicion.x > 5)
        this->posicion.x = -5;
   
    if ((std::rand()%180)==0) //si debo crear bala
    {
        Bullet* b = new Bullet("data/ship.frs");
        b->posicion = posicion;
        b->rotacion.z = 90;
        b->escalado = { 0.25,0.25, 0.25 , 1.0f };
        b->direccion = { 0,-1,0,0 };
        System::render->addObject(b);
    }
}