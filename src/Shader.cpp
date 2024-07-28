#include "Shader.h"


void Shader::use() {
	glUseProgram(this->id);
}

Shader::Shader(const char* vertexShaderFilePath, const char* fragmentShaderFilePath) {
	std::ifstream ifs(vertexShaderFilePath);
	std::string vertexShaderSource((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
	const char* vertexShaderCode = vertexShaderSource.c_str();

	std::ifstream ifs2(fragmentShaderFilePath);
	std::string fragmentShaderSource((std::istreambuf_iterator<char>(ifs2)), (std::istreambuf_iterator<char>()));
	const char* fragmentShaderCode = fragmentShaderSource.c_str();

	// vertex shader
	GLuint vertexShaderObject = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShaderObject, 1, &vertexShaderCode, NULL);
	glCompileShader(vertexShaderObject);
	std::cout << "Compiling Vertex Shader: ";
	char vertexShaderInfoLog[512];
	GLsizei vertexShaderInfoLogLength;
	glGetShaderInfoLog(vertexShaderObject, 512, &vertexShaderInfoLogLength, vertexShaderInfoLog);
	std::cout << (vertexShaderInfoLogLength ? vertexShaderInfoLog : "DONE!") << std::endl;

	// fragment shader
	GLuint fragmentShaderObject = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShaderObject, 1, &fragmentShaderCode, NULL);
	glCompileShader(fragmentShaderObject);
	std::cout << "Compiling Fragment Shader: ";
	char fragmentShaderInfoLog[512];
	GLsizei fragmentShaderInfoLogLength;
	glGetShaderInfoLog(fragmentShaderObject, 512, &fragmentShaderInfoLogLength, fragmentShaderInfoLog);
	std::cout << (fragmentShaderInfoLogLength ? fragmentShaderInfoLog : "DONE!") << std::endl;

	GLuint shaderProgram = glCreateProgram();
	this->id = shaderProgram;
	glAttachShader(shaderProgram, vertexShaderObject);
	glAttachShader(shaderProgram, fragmentShaderObject);
	glLinkProgram(shaderProgram);
}

void Shader::setBool(const std::string& uniform, bool value) const {
	glUniform1i(glGetUniformLocation(this->id, uniform.c_str()), (int)value);
}

void Shader::setInt(const std::string& uniform, int value) const {
	glUniform1i(glGetUniformLocation(this->id, uniform.c_str()), value);
}

void Shader::setFloat(const std::string& uniform, float value) const {
	glUniform1f(glGetUniformLocation(this->id, uniform.c_str()), value);
}