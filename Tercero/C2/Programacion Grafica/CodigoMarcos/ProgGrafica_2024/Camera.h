#pragma once
#include "common.h"
#include "libMath.h"
using namespace libMath;
using namespace std;

class Camera
{
public:
    vec4float pos;//posición de cámara
    vec4float rot;//rotaciones respecto de la cámara en reposo
    vec4float lookAt; //punto al que mira
    vec4float lookAtPrime; //punto al que mira en reposo
    vec4float forward, right, up;//vectores de cálculo de matriz vista
    
    Camera(vec4float pos, vec4float lookAt, vec4float up = { 0,1,0,0 });
    matrix4x4f computeViewMatrix();
    matrix4x4f computeProjectionMatrix(float zNear,float zFar, float fovy,float aspectRatio);

    void moveObject(double timeStep);

};

