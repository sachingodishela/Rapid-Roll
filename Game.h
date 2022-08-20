#pragma once

#include <vector>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Ball.h"
#include "Shader.h"

class Game
{
private:
	unsigned int lives;
	unsigned int score;
	Ball* ball;
	std::vector<PhysicalObject*> physicalObjects;
	GLuint * VAO, * VBO;
	Shader* shader;

public:
	Game()
	{
		this->lives = 3;
		this->score = 0;
		this->ball = new Ball(colors::RED);
		this->shader = new Shader("vertexShader.glsl", "fragmentShader.glsl");
		shader->use();
	}

	template <class T>
	void registerObject(T* object);
	void configureVAOandVBOs();
	void init(GLFWwindow* window);
	void terminate();
	void moveBallLeft(double);
	void moveBallRight(double);
	void moveBallUp(double);
	void moveBallDown(double);
};