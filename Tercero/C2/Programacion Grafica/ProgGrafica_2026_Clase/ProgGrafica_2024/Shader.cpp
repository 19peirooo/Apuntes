#include "Shader.h"

ShaderProgram::ShaderProgram(string fileName)
{
	this->fileName = fileName;

	//leer fichero
	std::ifstream f(fileName);
	if (f.is_open()) {
		this->code = string(istreambuf_iterator<char>(f), {});
	}
	else {
		cout << "ERROR: FICHERO NO ENCONTRADO" <<__FILE__ << ":" << __LINE__ << " " << fileName << endl;
	}

	//detectar tipo shader
	if (fileName.ends_with(".vertex")) {
		this->type = vertex;
	}
	else if (fileName.ends_with(".fragment")) {
		this->type = fragment;
	}

	//generar id
	this->shaderID = glCreateShader(this->type);
	
	//compilar
	const char* src[] = {this->code.c_str()};
	glShaderSource(this->shaderID, 1, src, nullptr); //1 porque solo compilo un codigo
	glCompileShader(shaderID);

	//detectar errores
	checkErrors();

}

ShaderProgram::~ShaderProgram()
{
	glDeleteShader(this->shaderID);
}

void ShaderProgram::checkErrors()
{
	GLint retCode;
	char errorLog[1024];
	GLint fragment_compiled;
	glGetShaderiv(this->shaderID, GL_COMPILE_STATUS, &fragment_compiled);
	if (fragment_compiled != GL_TRUE)
	{
		GLsizei log_length = 0;
		GLchar message[1024];
		glGetShaderInfoLog(this->shaderID, 1024, &log_length, message);
		std::cout << "ERROR " << fileName << "\n" << message << "\n\n";
	}
	else {
		this->compiled = true;
	}
}

void Shader::addShader(string fileName)
{
	ShaderProgram* shPrg = new ShaderProgram(fileName);
	this->programs.push_back(shPrg);
}

void Shader::linkProgram()
{
	
	this->programID = glCreateProgram();

	for (auto& shPrg : this->programs) {
		glAttachShader(this->programID, shPrg->shaderID);
	}

	glLinkProgram(this->programID);

	//check errores
	checkErrors();
	readVarList();

	//limpiar datos intermedios
	for (auto& shPrg : this->programs) {
		glDetachShader(this->programID, shPrg->shaderID);
		delete shPrg;
	}

}

void Shader::checkErrors()
{
	GLint program_linked;
	glGetProgramiv(this->programID, GL_LINK_STATUS, &program_linked);
	if (program_linked != GL_TRUE)
	{
		GLsizei log_length = 0;
		GLchar message[1024];
		glGetProgramInfoLog(this->programID, 1024, &log_length, message);
		std::cout << "ERROR \n" << message << "\n\n";
	}
	else {
		this->linked = true;
	}
}

void Shader::useProgram()
{
	glUseProgram(this->programID);
}

void Shader::readVarList()
{
	int numAttributes = 0;
	int numUniforms = 0;
	glGetProgramiv(this->programID, GL_ACTIVE_ATTRIBUTES, &numAttributes);
	for (int i = 0; i < numAttributes; i++)
	{
		char varName[100];
		int bufSize = 100, length = 0, size = 0;
		GLenum type = -1;
		glGetActiveAttrib(this->programID, (GLuint)i, bufSize, &length, &size, &type, varName);
		varList[std::string(varName)] = glGetAttribLocation(this->programID, varName);
	}
	glGetProgramiv(this->programID, GL_ACTIVE_UNIFORMS, &numUniforms);
	for (int i = 0; i < numUniforms; i++)
	{
		string varName; varName.resize(100);
		int bufSize = 100, length = 0, size = 0;
		GLenum type = -1;
		glGetActiveUniform(this->programID, (GLuint)i, bufSize, &length, &size, &type, varName.data());
		varName = std::string(varName.c_str()); //interrogar con nombre
		if (varName[varName.length() - 1] == ']') {//si es de tipo array
			std::string arrName = varName.substr(0, varName.find('['));
			for (int i = 0; i < size; i++) //coneguir la lista completa de nombres
			{
				std::string arrNameIdx = arrName + "[" + std::to_string(i) + "]";
				varList[arrNameIdx] = glGetUniformLocation(this->programID, arrNameIdx.c_str());
			}
		}
		else
			varList[varName] = glGetUniformLocation(this->programID, varName.c_str());
	}
}

void Shader::setMatrix(Matrix4x4f m, string matrixName)
{
	//si existe la variable
	auto var = varList.find(matrixName);
	if (var != varList.end()) {
		//setear datos
		glUniformMatrix4fv(var->second, 1, GL_FALSE, (float*) & m); //false --> no transpone la matriz
	}
	//sino
	else {
		//error
		cout << "Variable " << matrixName << " no encontrada" << endl;
	}
		
}

void Shader::setLight(Luz* luz)
{
	glUniform4f(varList["luz.pos"], luz->posicion.x, luz->posicion.y, luz->posicion.z, luz->posicion.w);
	glUniform4f(varList["luz.color"], luz->color.r, luz->color.g, luz->color.b, luz->color.a);
	glUniform1f(varList["luz.Ia"], luz->Ia);
	glUniform1f(varList["luz.Id"], luz->Id);
	glUniform1f(varList["luz.Is"], luz->Is);
	glUniform1f(varList["luz.activa"], luz->active);
}

void Shader::setMaterial(Material* mat)
{
	glUniform4f(varList["material.color"], mat->color.r, mat->color.g, mat->color.b, mat->color.a);
	glUniform1f(varList["material.ka"], mat->ka);
	glUniform1f(varList["material.kd"], mat->kd);
	glUniform1f(varList["material.ks"], mat->ks);
	glUniform1f(varList["material.alpha"], mat->alpha);
	glUniform1f(varList["material.usaTextura"], mat->usaTextura);
	glUniform1f(varList["material.shiny"], mat->shiny);

	if (mat->usaTextura) {
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, mat->texture->GLId);
	}
	glUniform1i(varList["colorTexture"], 1);
}

void Shader::setCamera(Camera* cam)
{
	glUniform4f(varList["camera.pos"], cam->pos.x, cam->pos.y, cam->pos.z, cam->pos.w);
}

void Shader::setAttributeData(string attribName, int count, GLenum dataType, size_t stride, void* offset)
{
	//si existe la variable
	auto var = varList.find(attribName);
	if (var != varList.end()) {
		//setear datos
		glEnableVertexAttribArray(var->second);
		glVertexAttribPointer(var->second, count,dataType, GL_FALSE, stride, offset);
	}
	//sino
	else {
		//error
		cout << "Variable " << attribName << " no encontrada" << endl;
	}
}
