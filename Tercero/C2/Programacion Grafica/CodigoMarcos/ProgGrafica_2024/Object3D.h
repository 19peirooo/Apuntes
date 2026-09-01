#pragma once
#include "libMath.h"
#include "common.h"
#include "Shader.h"
#include "Material.h"
#include "Colliders.h"

typedef enum {
    objectType,
    shipType,
    bulletType,
    enemyType
}objTypes;


using namespace std;
using namespace libMath;

typedef struct {
    vec4float posicion;
    vec4float color;
    vec4float normal;
    vec4float texturaCoords;
}vertex_t;

class Object3D
{
public:
    static inline unsigned int idCounter;

    unsigned int objectId;
    objTypes type = objectType;

    vector<vertex_t> vertexList;
    vector<unsigned int> indexList;
    vec4float posicion = { 0,0,0,1 };
    vec4float rotacion = { 0,0,0,1 };
    vec4float escalado = { 1,1,1,1 };

    Shader* prg = nullptr;
    Material* mat = new Material();
    string frsModel = "";
    ColliderTree<Sphere>* coll = new ColliderTree<Sphere>(nullptr);
    bool shouldDelete = false;

    Object3D();
    Object3D(string frsModel);
    void loadFromFile();

    matrix4x4f computeModelMatrix();
    virtual void moveObject(double timeStep) {};

    void computeNormals();

};

class Ship : public Object3D {
public:
    Ship(string frsFile) : Object3D(frsFile) { this->type = shipType; };
    void moveObject(double timeStep);
};

class Bullet : public Object3D {
public:
    vec4float direccion = { 0,0,0,0 };
    Bullet(string frsFile) : Object3D(frsFile) { this->type = bulletType; };
    void moveObject(double timeStep);
};


class Enemy : public Object3D {
public:
    Enemy(string frsFile) : Object3D(frsFile) { this->type = enemyType; };
    void moveObject(double timeStep);


};