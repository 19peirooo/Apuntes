#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Texture::Texture(int w, int h, pixel_t color)
{
    this->w = w;
    this->h = h;
    //iniciar identificadore
    glGenTextures(1, &GLId);

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
    //iniciar identificadore
    glGenTextures(1, &GLId);
    int numChannels = 0;
    //cargar datos en gpu
    
    unsigned char* pixels = 
        stbi_load(fileName.c_str(), &w, &h, &numChannels, 4);
    this->rawImage.resize(w * h);

    std::memcpy(rawImage.data(), pixels, sizeof(pixel_t) * w * h);
    
    stbi_image_free(pixels);
    
    updateTexture();
}

void Texture::updateTexture()
{
    glBindTexture(GL_TEXTURE_2D, GLId);//activa el buffer de textura de este objeto
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE,rawImage.data());
   
}
