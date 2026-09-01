#include "Colliders.h"

bool Sphere::collisionTest(Collider* coll)
{
    
    Sphere* other = (Sphere*)coll;

    return distance(this->center,other->center) < (this->radius + other->radius);
}

void Sphere::addParticle(particle3D* p)
{
    this->particleList.push_back(p);

    Vector4f newSize = { 0,0,0,0 };
    

    //Calcular tamaño de todas las particulas
    max.x = (p->pos.x + p->tam.x / 2) > max.x ? (p->pos.x + p->tam.x / 2) : max.x;
    max.y = (p->pos.y + p->tam.y / 2) > max.y ? (p->pos.y + p->tam.y / 2) : max.y;
    max.z = (p->pos.z + p->tam.z / 2) > max.z ? (p->pos.z + p->tam.z / 2) : max.z;

    min.x = (p->pos.x - p->tam.x / 2) < min.x ? (p->pos.x - p->tam.x / 2) : min.x;
    min.y = (p->pos.y - p->tam.y / 2) < min.y ? (p->pos.y - p->tam.y / 2) : min.y;
    min.z = (p->pos.z - p->tam.z / 2) < min.z ? (p->pos.z - p->tam.z / 2) : min.z;

    newSize = max - min; 
    float newRadius = length(newSize) / 2; 

    Vector4f newCenter = min + (newSize / 2);
    newCenter.w = 1;

    this->radius = newRadius;
    this->center = this->centerPrime = newCenter;

}

void Sphere::updateCollider(Matrix4x4f mat)
{

    this->center = mat * centerPrime;

    auto newMin = mat * min;
    auto newMax = mat * max;

    this->radius = length(newMax - newMin) / 2;

}


