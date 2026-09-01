#pragma once
#include "Render.h"
class System
{
public:
    inline static Render* render = nullptr;
    static vector<Object3D*> getCollisions(Object3D* obj, objTypes type);
};

