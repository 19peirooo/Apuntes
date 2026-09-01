#include "Camera.h"
using namespace libMath;

Camera::Camera(Vector4f pos, Vector4f lookAt, Vector4f up)
{
	this->pos = pos;
	this->rot = { 0, 0, 0, 0 };
	this->lookAt = lookAt;
	this->lookAtPrime = lookAt - pos;
	this->lookAtPrime.w = 1.0f;
	this->up = up;
	this->forward = normalize(lookAt - pos);
	this->right = normalize(this->forward ^ this->up);
}

Matrix4x4f Camera::computeViewMatrix()
{
	Matrix4x4f view = make_identityf();
	this->forward = normalize(lookAt - pos);

	this->right = normalize(this->forward ^ this->up);
	Vector4f upCamera = normalize(this->right ^ this->forward);	// normal plano horizontal a la camera
	Vector4f position = make_vector4f(-1*(this->right * this->pos), -(upCamera * this->pos), this->forward * this->pos, 1);

	view.t[0] = this->right;
	view.t[1] = upCamera;
	view.t[2] = this->forward * -1.0f;
	view.t[3] = { 0, 0, 0, 1 };
	view.t[0].v[3] = position.x;
	view.t[1].v[3] = position.y;
	view.t[2].v[3] = position.z;
	return view;
}

void Camera::moveCamera(double timeStep)
{
	float speed = 0.5f;
	float angularSpeedY = EventManager::mouseState.velX * 10;
	float angularSpeedX = EventManager::mouseState.velY * 10;


	if (EventManager::keyMap[GLFW_KEY_UP]) {
		this->pos = pos + forward * speed * timeStep;
	}
	if (EventManager::keyMap[GLFW_KEY_DOWN]) {
		this->pos = pos - forward * speed * timeStep;
	}
	if (EventManager::keyMap[GLFW_KEY_RIGHT]) {
		this->pos = pos + right * speed * timeStep;
	}
	if ((EventManager::keyMap[GLFW_KEY_LEFT])) {
		this->pos = pos - right * speed * timeStep;
	}
	
	rot.y += angularSpeedY * timeStep;
	rot.x += angularSpeedX * timeStep;

	Matrix4x4f rotMatrix = make_rotateY(rot.y) * make_rotateX(rot.x);
	this->lookAt = rotMatrix * this->lookAtPrime;
	Matrix4x4f trasM = make_traslate(this->pos.x, this->pos.y, this->pos.z);
	this->lookAt = trasM * this->lookAt;

	EventManager::mouseState.velX = 0;
	EventManager::mouseState.velY = 0;
}

Matrix4x4f Camera::computeProjectionMatrix(float zNear, float zFar, float fovy, float aspectRatio)
{
	Matrix4x4f projMatrix = make_identityf();
	projMatrix.t[0].v[0] = 1.0f / (aspectRatio * tan(fovy * 0.5f));
	projMatrix.t[1].v[1] = 1.0f / tan(fovy * 0.5f);
	projMatrix.t[2].v[2] = -(zFar + zNear) / (zFar - zNear);
	projMatrix.t[2].v[3] = 2.0f * zFar * zNear / (zFar - zNear);
	projMatrix.t[3].v[2] = -1.0f;


	return projMatrix;
}