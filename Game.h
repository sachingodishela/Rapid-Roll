#pragma once

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <glad/glad.h>
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
	Game()
	{
		srand(time(NULL));
		this->lives = 3;
		this->score = 0;
		this->ball = new Ball(colors::RED);
		this->steps = new Step*[6];
		for (int i = 0; i < 6; i++) this->steps[i] = new Step(0.5, -0.6 + (i / 6.0) * 2, 0.8, 0.04);
		this->shader = new Shader("vertexShader.glsl", "fragmentShader.glsl");
		shader->use();
	}

	void configureVAOandVBOs();
	void init(GLFWwindow* window);
	void terminate();
	void moveBallLeft(double);
	void moveBallRight(double);
	void moveBallUp(double);
	void moveBallDown(double);
};