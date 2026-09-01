#define STB_IMAGE_IMPLEMENTATION

#include "Texture.h"
#include "stb_image.h"

Texture::Texture(int w, int h, pixel_t color)
{
	this->w = w;
	this->h = h;
	//inicar identificadores
	glGenTextures(1,&this->GLId);
	//cargar datos en gpu
	this->rawImage.resize(w * h);

	for (auto& p : rawImage) {
		p = color;
	}
	updateTexture();
}

Texture::Texture(string fileName)
{
	this->w = 0;
	this->h = 0;
	//inicar identificadores
	glGenTextures(1, &this->GLId);
	int numChannels = 0;
	//cargar datos en gpu
	unsigned char* pixels = stbi_load(fileName.c_str(),&w,&h,&numChannels,4); //El numChannels se ignora porque se va a extender a 4 canales
	this->rawImage.resize(w * h);
	int counter = 0;
	
	std::memcpy(rawImage.data(), pixels, sizeof(pixel_t) * w * h); //Mas rapido que el for de arriba
	stbi_image_free(pixels);
	updateTexture();
}

void Texture::updateTexture()
{
	glBindTexture(GL_TEXTURE_2D, this->GLId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, rawImage.data());
}
