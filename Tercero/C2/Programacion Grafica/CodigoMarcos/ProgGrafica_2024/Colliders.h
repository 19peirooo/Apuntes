#pragma once
#include "common.h"
#include "libMath.h"
using namespace std;
using namespace libMath;
typedef struct  
{
    vec4float pos;
    vec4float size;
}particle3D;

class Collider
{
public:
    vector<particle3D*> particleList;
    vec4float max = { -1000000,-1000000,-1000000,0 };
    vec4float min = { 1000000,1000000,1000000,0 };

    Collider() {};
    virtual bool collisionTest(Collider* coll) = 0;
    virtual void addParticle(particle3D* particle) = 0;
    virtual void updateCollider(matrix4x4f mat) = 0;
};


class Sphere :public Collider {
public:
    float radius = 0;
    vec4float center = { 0,0,0,1 };
    vec4float centerPrime = { 0,0,0,1 };


    virtual bool collisionTest(Collider* coll) override;
    virtual void addParticle(particle3D* particle) override;
    virtual void updateCollider(matrix4x4f mat) override;



};



typedef struct colliderNode {
    Collider* bv; //volumen envolvente de este nivel
    struct colliderNode* sons[2]; //dos hijos 
}colliderNode;


template <class TypeCollider>
class ColliderTree
{
public:
    colliderNode* root;

    ColliderTree(colliderNode* root) :root(root) {};

    static bool collisionTest(colliderNode* coll, colliderNode* otherColl)
    {

        //si raiz de uno y raiz otro colisiona
        if (coll->bv->collisionTest(otherColl->bv)) {
            // 
            if (coll->sons[0] || coll->sons[1]
                || otherColl->sons[0] || otherColl->sons[1]) {//alguno tiene hijos
                bool colisionDetected = false;
                if (coll->sons[0] && otherColl->sons[0])//ambos son subárboles, hay hijos
                    for (int i = 0;i < 2;i++)
                    {
                        if (coll->sons[i])//si el hijo no es nulo
                        {
                            for (int j = 0;j < 2;j++)
                            {
                                if (otherColl->sons[j])
                                {
                                    colisionDetected |= collisionTest(coll->sons[i], otherColl->sons[j]);
                                }
                            }
                        }
                    }
                else if (!coll->sons[0])//el izquierdo no tiene hijos
                {
                    for (int j = 0;j < 2;j++)//
                    {
                        colisionDetected |= collisionTest(coll, otherColl->sons[j]);
                    }
                }
                else //el derecho no tiene hijos
                {
                    for (int j = 0;j < 2;j++)//
                    {
                        colisionDetected |= collisionTest(coll->sons[j], otherColl);
                    }
                }
                return colisionDetected;
            }
            else //ninguno tiene hijos, ambos son hojas
                return true;
        }
        else
            return false;
    }

    
    static void subdivide(colliderNode* node) {
        //crear dos hijos
        colliderNode* n1 = new colliderNode;
        colliderNode* n2 = new colliderNode;
        n1->bv = new TypeCollider(); //sólo esferas
        n2->bv = new TypeCollider();

        //repartir particulas
        vec4float center = ((TypeCollider*)node->bv)->center;
        //izquierda a hijo1, derecha a hijo2
        for (auto& p : node->bv->particleList) {//por cada particula
            //calcular centro particula
            vec4float centerParticle = p->pos;

            if (p->size.x > p->size.y && p->size.x > p->size.z) //ejeX mas largo
            {
                if (p->pos.x < center.x) //falta calcular eje más largo
                    n1->bv->addParticle(p);
                else
                    n2->bv->addParticle(p);
            }
            else if (p->size.y > p->size.x && p->size.y > p->size.z) //ejeX mas largo
            {
                if (p->pos.y < center.y) //falta calcular eje más largo
                    n1->bv->addParticle(p);
                else
                    n2->bv->addParticle(p);
            }
            else //eje z más largo
            {
                if (p->pos.z < center.z) //falta calcular eje más largo
                    n1->bv->addParticle(p);
                else
                    n2->bv->addParticle(p);
            }
        }
        //si hijos distintos
        if (n1->bv->particleList.size() > 0 &&
            n2->bv->particleList.size() > 0)
        {     
            node->sons[0] = n1;
            node->sons[1] = n2;
            //subdividir hijos
            subdivide(n1);
            subdivide(n2);
            
        }
        else { //acabar, limpiar memoria
            delete n1;
            delete n2;
            node->sons[0] = node->sons[1] = nullptr;
        }


    }

    static void updateTree(colliderNode* root,matrix4x4f mat) {
    
        root->bv->updateCollider(mat);
        //si tiene hijos
        if (root->sons[0])
        {
            updateTree(root->sons[0], mat);
            updateTree(root->sons[1], mat);
        }
    
    }


};


