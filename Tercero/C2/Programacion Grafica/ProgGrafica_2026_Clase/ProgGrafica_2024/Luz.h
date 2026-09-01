#pragma once
#include "libMath.h"
#include "common.h"
using namespace libMath;

class Luz
{
	public:
		Vector4f posicion = {0,0,0,1};
		Vector4f color = { 1,1,1,1 };

		const float Ia=0, Id=0, Is=0;

		bool active = false;


		Luz(Vector4f pos,Vector4f color = {1,1,1,1}, float Ia=1, float Id=1, float Is=1);

		void moveObject(double timeStep);
};

