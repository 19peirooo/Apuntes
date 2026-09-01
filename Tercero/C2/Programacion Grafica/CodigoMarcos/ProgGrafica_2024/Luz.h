#pragma once
#include "common.h"
#include "libMath.h"

using namespace libMath;
class Luz
{
public:
    vec4float posicion = { 0,0,0,1 };

    float Ia = 0, Id = 0, Is = 0;
    vec4float color = { 1,1,1,1 };
    bool activa = false;

    Luz(vec4float pos, vec4float color = { 1,1,1,1 },
             float Ia = 0.2, float Id = 0.3, float Is = 1);

    void moveObject(double timeStep);



};

