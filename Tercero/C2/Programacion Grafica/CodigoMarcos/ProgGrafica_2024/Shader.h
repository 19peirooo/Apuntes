#pragma once
#include "common.h"
#include "libMath.h"
#include "Luz.h"
#include "Camera.h"
#include "Material.h"


using namespace std;
using namespace libMath;

class ShaderProgram
{
public:
    typedef enum {
        vertex = GL_VERTEX_SHADER,
        fragment = GL_FRAGMENT_SHADER,
        error = -1
    }ProgramType;

    string fileName="";
    string code="";
    ProgramType type=error;

    bool compiled = false;

    unsigned int shaderID=error;

    ShaderProgram(string fileName);
    ~ShaderProgram();

    void checkErrors();


};
class Shader
{
public:
    unsigned int programID = ShaderProgram::error;
    vector< ShaderProgram* > programs;
    map<string, unsigned int> varList; //lista de variables en GPU
    bool linked = false;
    Shader() {};
    void addShaderProgram(string fileName);
    void linkProgram(); //linka todos los códigos de shader compilados
    void checkErrors(); //checkea errores de linkado
    void useProgram() { glUseProgram(programID); }; //activa este programa linkado para uso en gpu
    void readVarList(); //lectura de variables activas de programa
    void setMatrix(matrix4x4f m, string matrixName); //Set de una variable de tipo matriz
    void setLight(Luz* luz);
    void setMaterial(Material* luz);
    void setCamera(Camera* luz);

    //setMaterial(...); TODO
    //set descripción de variables uniform
    void setAttributeData(string attribName, int count, GLenum dataType, size_t stride, void* offset);
};

