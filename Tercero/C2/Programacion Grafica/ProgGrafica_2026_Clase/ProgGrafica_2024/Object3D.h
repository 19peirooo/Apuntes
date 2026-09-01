#pragma once

#include "libMath.h"
#include "Shader.h"
#include "Material.h"
#include "Colliders.h"

typedef enum {
	shipType,
	enemyType,
	objectType,
	bulletType
}objTypes;

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

using namespace std;

typedef struct {
	Vector4f position;
	Vector4f color;
	Vector4f normal;
	Vector4f textureCoords;
} vertex_t;

class Object3D{

	public:

		static inline unsigned int idCounter;

		unsigned int objId;
		objTypes type = objectType;

		vector<vertex_t> vertexList;
		vector<unsigned int> indexList;

		Vector4f position = { 0,0,0,1 };
		Vector4f rotacion = { 0,0,0,1 };
		Vector4f escalado = { 0,0,0,1 };

		Shader* prg = nullptr;
		Material* mat = new Material();
		string frsModel = "";
		ColliderTree<Sphere>* colliderTree = new ColliderTree<Sphere>(nullptr);

		bool shouldDelete = false;

		Object3D();
		Object3D(string frsModel);

		Matrix4x4f computeModelMatrix();
		virtual void moveObject(double timeStep) {};

		void computeNormals();

		void loadFromFile();
};

class Ship : public Object3D {
	public: 
		Ship(string frsFile) : Object3D(frsFile) { this->type = shipType; };

		void moveObject(double timeStep);
};

class Bullet : public Object3D {
public:
	
	Vector4f dir = { 0,0,0,0 };

	Bullet(string frsFile) : Object3D(frsFile) { this->type = bulletType; };

	void moveObject(double timeStep);
};

class Enemy : public Object3D {
public:
	Enemy(string frsFile) : Object3D(frsFile) { this->type = enemyType; };

	void moveObject(double timeStep);
};
