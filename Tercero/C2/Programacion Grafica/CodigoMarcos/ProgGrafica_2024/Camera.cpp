#include "Camera.h"
#include "EventManager.h"

Camera::Camera(vec4float pos, vec4float lookAt, vec4float up)
{
    this->pos = pos;
    this->rot = { 0,0,0,0 };
    this->lookAt= lookAt;
    this->lookAtPrime = lookAt - pos;
    this->lookAtPrime.w=1.0f;
    this->up = up;
    this->forward = normalize(lookAt - pos);
}

matrix4x4f Camera::computeViewMatrix()
{
    matrix4x4f view = make_identityf();
    this->forward = normalize(lookAt - pos);

    right = normalize(cross(forward, up));
    vec4float upCamera = normalize(cross(right, forward));
    vec4float position = make_vec4float(-dot(right, pos), -dot(upCamera, pos), dot(forward, pos), 1);
    view.matV[0] = right;
    view.matV[1] = upCamera;
    view.matV[2] = -1.0f*forward;
    view.mat2D[0][3] = position.x;
    view.mat2D[1][3] = position.y;
    view.mat2D[2][3] = position.z;
    view.matV[3] = { 0,0,0,1 };

    return view;
}

matrix4x4f Camera::computeProjectionMatrix(float zNear, float zFar, float fovy, float aspectRatio)
{
    matrix4x4f projMatrix = make_identityf();
    projMatrix.mat2D[0][0] =  1.0f / (aspectRatio * tan(fovy * 0.5));
    projMatrix.mat2D[1][1] =  1.0f / tan(fovy * 0.5f);
    projMatrix.mat2D[2][2] = -(zFar + zNear) / (zFar - zNear);
    projMatrix.mat2D[2][3] =  2.0f * zFar * zNear / (zFar - zNear);
    projMatrix.mat2D[3][2] = -1.0f;
    return projMatrix;
}

void Camera::moveObject(double timeStep)
{
    float speed = 5.0f;
    float speedRotY = EventManager::mouseState.velX*50.0f;
    float speedRotX = EventManager::mouseState.velY * 100.0f;


    if (EventManager::keyMap[GLFW_KEY_LEFT])
    {
        pos = pos - right * speed * timeStep;
    }

    if (EventManager::keyMap[GLFW_KEY_RIGHT])
    {
        pos = pos + right * speed * timeStep;
    }
    if (EventManager::keyMap[GLFW_KEY_UP])
    {
       pos = pos + forward*speed * timeStep ;
    }
    if (EventManager::keyMap[GLFW_KEY_DOWN])
    {
        pos = pos - forward * speed * timeStep;
    }

    rot.y += speedRotY * timeStep;
    rot.x += speedRotX * timeStep;


    matrix4x4f rotM = make_rotateY(rot.y)* make_rotateX(rot.x);
    lookAt = rotM * lookAtPrime;
    matrix4x4f trasM = make_traslate(pos.x, pos.y, pos.z);
    lookAt = trasM * lookAt;

    EventManager::mouseState.velY = 0;
    EventManager::mouseState.velX = 0;


}
