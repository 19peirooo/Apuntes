#include "System.h"

vector<Object3D*> System::getCollisions(Object3D* obj, objTypes type)
{
	vector<Object3D*> res;

	for (auto& o : render->objectList) {
		
		//Sino es el mismo, es del tipo correcto y colisionan
		if (obj != o && o->type == type &&
			ColliderTree<Sphere>::collisionTest(o->colliderTree->root, obj->colliderTree->root))
			res.push_back(o);
	}

	return res;
}
