#pragma once
#include "common.h"
#include "libMath.h"
using namespace libMath;

typedef struct {

	Vector4f pos;
	Vector4f tam;

} particle3D;

class Collider
{
	public:
		vector<particle3D*> particleList;
		Vector4f min = { -1000000,-1000000,-1000000,-1000000 };
		Vector4f max = { 1000000,1000000,1000000,1000000 };
		Collider() {};

		virtual bool collisionTest(Collider* coll)=0;
		virtual void addParticle(particle3D* particle)=0;
		virtual void updateCollider(Matrix4x4f mat)=0;

};

class Sphere : public Collider {

	public:
		float radius = 0;
		Vector4f center = { 0,0,0,1 };
		Vector4f centerPrime = { 0,0,0,1 };


		virtual bool collisionTest(Collider* coll);
		virtual void addParticle(particle3D* particle);
		virtual void updateCollider(Matrix4x4f mat);

};

typedef struct colliderNode {
	Collider* bv; //Volumen Envolvente
	struct colliderNode* childNodes[2]; //dos hijos
}colliderNode;

template <class colliderType>
class ColliderTree
{

public:
	colliderNode* root;

    ColliderTree(colliderNode* root) : root(root) {};

    static bool collisionTest(colliderNode* coll, colliderNode* otherColl)
    {
        //Si raiz de uno y raiz de otro collisiona


        if (coll->bv->collisionTest(otherColl->bv)) {

            //testeo hijos todos con todos
            if (coll->childNodes[0] || coll->childNodes[1]
                || otherColl->childNodes[0] || otherColl->childNodes[1]) //Alguno tiene hijos
            {
                bool colisionDetected = false;
                if (coll->childNodes[0] && otherColl->childNodes[0]) { //ambos son subarboles
                    for (int i = 0; i < 2; i++) {
                        if (coll->childNodes[i]) { //Si hay hijo 
                            for (int j = 0; j < 2; j++) {
                                if (otherColl->childNodes[j]) {
                                    colisionDetected |= collisionTest(coll->childNodes[i], otherColl->childNodes[j]);
                                }
                            }
                        }
                    }
                }
                else if (!coll->childNodes[0]) { // el izquierdo no tiene hijos
                    for (int j = 0; j < 2; j++) {
                        if (otherColl->childNodes[j]) {
                            colisionDetected |= collisionTest(coll, otherColl->childNodes[j]);
                        }
                    }
                }
                else { // el derecho no tiene hijos
                    for (int j = 0; j < 2; j++) {
                        if (otherColl->childNodes[j]) {
                            colisionDetected |= collisionTest(coll->childNodes[j], otherColl);
                        }
                    }
                }
                return colisionDetected;

            }
            else // Ninguno tiene hijos --> Ambos son hoja
                return true;
        }
        else {
            return false;
        }

    }

    static void subdivide(colliderNode* node)
    {
        // crear 2 hijos

        colliderNode* n1 = new colliderNode;
        colliderNode* n2 = new colliderNode;

        n1->bv = new colliderType();
        n2->bv = new colliderType();

        //repartir particulas

        Vector4f center = ((Sphere*)node->bv)->center;
        //izquierda a hijo1, derecha a hijo2
        for (auto& p : node->bv->particleList) {
            //Calcular centro particula
            Vector4f centerParticle = p->pos;

            if (p->tam.x > p->tam.y && p->tam.x > p->tam.z) // ejeX mas largo
            {
                if (p->pos.x < center.x) {
                    n1->bv->addParticle(p);
                }
                else {
                    n2->bv->addParticle(p);
                }
            }
            else if (p->tam.y > p->tam.x && p->tam.y > p->tam.z) { // ejeY mas largo
                if (p->pos.y < center.y) {
                    n1->bv->addParticle(p);
                }
                else {
                    n2->bv->addParticle(p);
                }
            } 
            else { // ejeZ mas largo
                if (p->pos.z < center.z) {
                    n1->bv->addParticle(p);
                }
                else {
                    n2->bv->addParticle(p);
                }
            }
            
        }

        //si hijos distintos
        if (n1->bv->particleList.size() > 0 &&
            n2->bv->particleList.size() > 0) {
            //subdividir hijos
            node->childNodes[0] = n1;
            node->childNodes[1] = n2;
            subdivide(n1);
            subdivide(n2)
        }
        //else
        else {
            //acabar
            delete n1;
            delete n2;
            node->childNodes[0] = node->childNodes[1] = nullptr
        }
            

    }

    static void updateTree(colliderNode* root ,Matrix4x4f mat) {

        root->bv->updateCollider(mat);

        if (root->childNodes[0]) {
            updateTree(root->childNodes[0], mat);
            updateTree(root->childNodes[1], mat)
        }
    }

};

