#pragma once
#include "common.h"
#include "libMath.h"
#include "EventManager.h"
using namespace libMath;
using namespace std;

class Camera {
public:
	Vector4f pos;		// posición de la cámara
	Vector4f rot;		// rotaciones respecto de la cámara en reposo
	Vector4f lookAt;	// punto al que mira
	Vector4f lookAtPrime;	// punto al que mira en reposo
	Vector4f forward, right, up;	// vectores de cálculo de matriz vista 

	Camera(Vector4f pos, Vector4f lookAt, Vector4f up = { 0, 1, 0, 0 });
	Matrix4x4f computeViewMatrix();
	Matrix4x4f computeProjectionMatrix(float zNear, float zFar, float fovy, float aspectRatio);
	void moveCamera(double timeStep);

};