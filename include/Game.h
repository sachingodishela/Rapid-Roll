#pragma once

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Ball.h"
#include "Step.h"
#include "Shader.h"

class Game
{
private:
	unsigned int lives;
	unsigned int score;
	GLuint * VAO, * VBO;
	Shader* shader;

public:
	Ball* ball;
	Step** steps;
	unsigned int nObjects;
	Game()
	{
		srand(time(NULL));
		this->lives = 3;
		this->score = 0;
		this->ball = new Ball(colors::RED, 0.05);
		this->steps = new Step*[6];
		this->nObjects = 2;
		for (int i = 0; i < 6; i++) this->steps[i] = new Step(-0.8 + ((double)rand() / RAND_MAX) * 1.6, -0.6 + (i / 6.0) * 2, 0.4, 0.04);
		this->VAO = new GLuint[nObjects];
		this->VBO = new GLuint[nObjects];
		this->shader = new Shader("shaders/vertexShader.glsl", "shaders/fragmentShader.glsl");
		shader->use();
	}

	void configureVAOandVBOs();
	void init(GLFWwindow* window);
	void terminate();
	void setBallHorizontalVelocity(int action);
};