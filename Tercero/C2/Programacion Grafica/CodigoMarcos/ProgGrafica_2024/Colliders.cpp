#include "Colliders.h"

bool Sphere::collisionTest(Collider* coll)
{
    Sphere* other = (Sphere*)coll;
    return distance(this->center,other->center)<(this->radius+other->radius);
}

void Sphere::addParticle(particle3D* p)
{
    this->particleList.push_back(p);
    vec4float newSize = { 0,0,0,0 };
    //calcular tamaño con todas las partículas
    max.x = ((p->pos.x + p->size.x / 2) > max.x) ?
                (p->pos.x + p->size.x / 2) :
                max.x;
    max.y = ((p->pos.y + p->size.y / 2) > max.y) ?
        (p->pos.y + p->size.y / 2) :
        max.y;
    max.z = ((p->pos.z + p->size.z / 2) > max.z) ?
        (p->pos.z + p->size.z / 2) :
        max.z;

    min.x = ((p->pos.x - p->size.x / 2) < min.x) ?
        (p->pos.x - p->size.x / 2) :
        min.x;
    min.y = ((p->pos.y - p->size.y / 2) < min.y) ?
        (p->pos.y - p->size.y / 2) :
        min.y;
    min.z = ((p->pos.z - p->size.z / 2) < min.z) ?
        (p->pos.z - p->size.z / 2) :
        min.z;
    
    newSize = (max - min);
    float newRadious = length(newSize)/2;
    vec4float newCenter = min + (newSize / 2);
    
    newCenter.w = 1;
    radius = newRadious;
    center = centerPrime= newCenter;

}

void Sphere::updateCollider(matrix4x4f mat)
{
    this->center = mat * centerPrime;
    auto newMax = mat * max;
    auto newMin = mat * min;
    radius = length(newMax-newMin) / 2;

    
}

