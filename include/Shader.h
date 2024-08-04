#pragma once
#include <string>
#include <GL/glew.h>
#include <iostream>
#include <fstream>

class Shader
{
public:
	GLuint id;
	Shader(const char* vertexShaderFilePath, const char* fragmentShaderFilePath);
	Shader(std:: string vertexShaderFiePath, std::string fragmentShadeFilePath);
	void setBool(const std::string& uniform, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;
	void use();
};
