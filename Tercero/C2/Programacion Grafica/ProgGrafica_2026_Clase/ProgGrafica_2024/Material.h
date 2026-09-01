#pragma once

#include "libMath.h"
#include "Texture.h"
using namespace libMath;

class Material
{
	public:

		float ka=1, kd=1, ks=1;
		bool usaTextura = false;
		Vector4f color = {1,1,1,1};
		Texture* texture = nullptr;
		float alpha = 0.5f;
		int shiny = 1;

		Material() {};
};

