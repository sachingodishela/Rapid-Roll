#pragma once
#include <string>
#include <glad/glad.h>
#include <iostream>
#include <fstream>

class Shader
{
public:
	GLuint id;
	Shader(const char* vertexShaderFilePath, const char* fragmentShaderFilePath);
	void setBool(const std::string& uniform, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;
	void use();
};
