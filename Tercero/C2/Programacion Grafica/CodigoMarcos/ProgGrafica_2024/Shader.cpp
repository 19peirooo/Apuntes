#include "Shader.h"

ShaderProgram::ShaderProgram(string fileName)
{
    this->fileName = fileName;
    //leer fichero
    std::ifstream f(fileName);
    if (f.is_open()) {
        code = std::string(std::istreambuf_iterator<char>(f), {});
    }
    else {
        std::cout << "ERROR: FICHERO NO ENCONTRADO " <<
            __FILE__ << ":" << __LINE__ << " " << fileName << "\n";
    }
    //compilar{
        // generar id
        // detectar tipo shader

    if (fileName.ends_with(".vertex"))
        this->type = vertex;
    if (fileName.ends_with(".fragment"))
        this->type = fragment;

    this->shaderID = glCreateShader(type);
        // compilar código
    const char* src[] = { this->code.c_str() };
    glShaderSource(shaderID, 1, src, nullptr);
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
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &fragment_compiled);
    if (fragment_compiled != GL_TRUE)
    {
        GLsizei log_length = 0;
        GLchar message[1024];
        glGetShaderInfoLog(shaderID, 1024, &log_length, message);
        std::cout << "ERROR " << fileName << "\n" << message << "\n\n";
    }
    else
        compiled = true;

}

void Shader::addShaderProgram(string fileName)
{
    ShaderProgram* shPrg = new ShaderProgram(fileName);
    //si no hay errores, se añade
    this->programs.push_back(shPrg);
}

void Shader::linkProgram()
{

    this->programID = glCreateProgram();

    for (auto& shPrg : programs)
    {
        glAttachShader(this->programID, shPrg->shaderID);
    }
    glLinkProgram(this->programID);

    //check errores
    checkErrors();
    readVarList();

    //limpiar datos intermedios
    for (auto& shPrg : programs)
    {
        glDetachShader(this->programID, shPrg->shaderID);
        delete shPrg;
    }



}

void Shader::checkErrors()
{
    GLint program_linked;
    glGetProgramiv(programID, GL_LINK_STATUS, &program_linked);
    if (program_linked != GL_TRUE)
    {
        GLsizei log_length = 0;
        GLchar message[1024];
        glGetProgramInfoLog(programID, 1024, &log_length, message);
        std::cout << "ERROR " << message << "\n\n";
    }
    else 
        linked = true;
}

void Shader::readVarList()
{

    int numAttributes = 0;
    int numUniforms = 0;
    glGetProgramiv(programID, GL_ACTIVE_ATTRIBUTES, &numAttributes);
    for (int i = 0; i < numAttributes; i++)
    {
        char varName[100];
        int bufSize = 100, length = 0, size = 0;
        GLenum type = -1;
        glGetActiveAttrib(programID, (GLuint)i, bufSize, &length, &size, &type, varName);
        varList[std::string(varName)] = glGetAttribLocation(programID, varName);
    }
    glGetProgramiv(programID, GL_ACTIVE_UNIFORMS, &numUniforms);
    for (int i = 0; i < numUniforms; i++)
    {
        string varName; varName.resize(100);
        int bufSize = 100, length = 0, size = 0;
        GLenum type = -1;
        glGetActiveUniform(programID, (GLuint)i, bufSize, &length, &size, &type, varName.data());
        varName = std::string(varName.c_str()); //interrogar con nombre
        if (varName[varName.length() - 1] == ']') {//si es de tipo array
            std::string arrName = varName.substr(0, varName.find('['));
            for (int i = 0; i < size; i++) //coneguir la lista completa de nombres
            {
                std::string arrNameIdx = arrName + "[" + std::to_string(i) + "]";
                varList[arrNameIdx] = glGetUniformLocation(programID, arrNameIdx.c_str());
            }
        }
        else
            varList[varName] = glGetUniformLocation(programID, varName.c_str());
    }


}

void Shader::setMatrix(matrix4x4f m, string matrixName)
{
    //si existe la variable
    auto var = varList.find(matrixName);
    if(var!=varList.end()){
        //setear datos
        glUniformMatrix4fv(var->second, 1, GL_FALSE, (float*) & m);
    }
    //else
        //error
    else {
        cout << "Variable " << matrixName << " no encontrada\n";
    }
    
}
void Shader::setLight(Luz* luz)
{
    glUniform4f(varList["luz.pos"], luz->posicion.x, luz->posicion.y, luz->posicion.z, luz->posicion.w);
    glUniform4f(varList["luz.color"], luz->color.x, luz->color.y, luz->color.z,luz->color.w);
    glUniform1f(varList["luz.Ia"], luz->Ia);
    glUniform1f(varList["luz.Id"], luz->Id);
    glUniform1f(varList["luz.Is"], luz->Is);
    glUniform1i(varList["luz.activa"], luz->activa);
}

void Shader::setMaterial(Material* mat)
{
    glUniform4f(varList["material.color"], mat->color.x, mat->color.y, mat->color.z, mat->color.w);
    glUniform1f(varList["material.ka"], mat->ka);
    glUniform1f(varList["material.kd"], mat->kd);
    glUniform1f(varList["material.ks"], mat->ks);
    glUniform1f(varList["material.alpha"], mat->alpha);
    glUniform1i(varList["material.usaTextura"], mat->usaTextura);
    glUniform1i(varList["material.shiny"], mat->shiny);

    if (mat->usaTextura) {
        //configurar unidad de texturado
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, mat->textura->GLId);
    }
    //configurar sampler2D de shader
    glUniform1i(varList["colorTexture"], 1);//usamos la unidad 0 de texturas


}

void Shader::setCamera(Camera* cam)
{
    glUniform4f(varList["camara.posicion"], cam->pos.x, cam->pos.y, cam->pos.z, cam->pos.w);
   
}


void Shader::setAttributeData(string attribName, int count, GLenum dataType, size_t stride, void* offset)
{

    //si existe la variable
    auto var = varList.find(attribName);
    if (var != varList.end()) {
        //setear datos

        glEnableVertexAttribArray(var->second);
        glVertexAttribPointer(var->second, count, dataType, GL_FALSE, stride, offset);
    }
    //else
        //error
    else {
        cout << "Variable " << attribName << " no encontrada\n";
    }


}



