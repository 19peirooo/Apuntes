#pragma once
#include "libMath.h"
#include "Luz.h"
#include "Camera.h"
#include "Material.h"


class ShaderProgram
{
	public:

		typedef enum {
			vertex = GL_VERTEX_SHADER,
			fragment = GL_FRAGMENT_SHADER,
			error = -1
		}ProgramType;

		string fileName = "";
		string code = "";
		unsigned int shaderID = -1;
		ProgramType type = error;

		ShaderProgram(string fileName);
		~ShaderProgram();

		bool compiled = false;
		void checkErrors();
};

class Shader
{
	public:
		
		unsigned int programID = ShaderProgram::error;
		vector<ShaderProgram*> programs;
		map<string, unsigned int> varList; //lista de variables en GPU

		Shader() {};

		void addShader(string fileName);
		void linkProgram(); //Linka todos los codigos de shader compilados

		bool linked = false;
		void checkErrors(); // Checkea errores
		void useProgram(); // activa este programa linkado para uso en gpu
		void readVarList(); // parsea el codigo para buscar lista de variables
		void setMatrix(Matrix4x4f m, string matrixName);
		void setLight(Luz* luz);
		void setMaterial(Material* mat);
		void setCamera(Camera* cam);
		void setAttributeData(string attribName, int count, GLenum dataType, size_t stride, void* offset);
};

