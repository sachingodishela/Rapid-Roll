#include "Game.h"
#include <algorithm>

double* ballVertexData = new double[7];
double* stepsVertexData = new double[168];

void updateStepVertexPositions(int vertexIndex, int startIndexInBuffer, Step* step)
{
	if (vertexIndex == 0) {
		stepsVertexData[startIndexInBuffer + 1] = step->position[0] - (step->width / 2);
		stepsVertexData[startIndexInBuffer + 2] = step->position[1] + (step->height / 2);
	}
	else if (vertexIndex == 1) {
		stepsVertexData[startIndexInBuffer + 1] = step->position[0] + (step->width / 2);
		stepsVertexData[startIndexInBuffer + 2] = step->position[1] + (step->height / 2);
	}
	else if (vertexIndex == 2) {
		stepsVertexData[startIndexInBuffer + 1] = step->position[0] - (step->width / 2);
		stepsVertexData[startIndexInBuffer + 2] = step->position[1] - (step->height / 2);
	}
	else {
		stepsVertexData[startIndexInBuffer + 1] = step->position[0] + (step->width / 2);
		stepsVertexData[startIndexInBuffer + 2] = step->position[1] - (step->height / 2);
	}
}

void nextFrame(Ball* ball, Step** steps, GLuint* VBO)
{
	glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
	for (int i = 0; i < 6; i++)
	{
		steps[i]->position[1] += 0.01 * steps[i]->velocity[1];
		if (steps[i]->position[1] > 1) {
			steps[i]->position[1] -= 2;
			steps[i]->position[0] *= -1;
		}
		for (int v = 0; v < 4; v++)
		{
			updateStepVertexPositions(v, (i * 4 + v) * 7, steps[i]);
			glBufferSubData(GL_ARRAY_BUFFER, 8 * ((i * 4 + v) * 7 + 1), 16, &(stepsVertexData[(i * 4 + v) * 7 + 1]));
		}
	}

	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
	glBufferSubData(GL_ARRAY_BUFFER, 8, 16, &(ball->position[0]));
}

void initializeStepVertex(int vertexIndex, int stepIndex, Step* step)
{
	// 0             1
	// ===============
	// 2             3

	int startIndexInBuffer = (stepIndex * 4 + vertexIndex) * 7;
	stepsVertexData[startIndexInBuffer] = 1;
	updateStepVertexPositions(vertexIndex, startIndexInBuffer, step);
	stepsVertexData[startIndexInBuffer + 3] = step->color.getColorChannels()[0];
	stepsVertexData[startIndexInBuffer + 4] = step->color.getColorChannels()[1];
	stepsVertexData[startIndexInBuffer + 5] = step->color.getColorChannels()[2];
	stepsVertexData[startIndexInBuffer + 6] = step->color.getColorChannels()[3];
}

void initializeStepVertices(int stepIndex, Step** steps)
{
	// each step has 4 vertices and we need to use glDrawElements to draw the triangle
	for (int i = 0; i < 4; i++) initializeStepVertex(i, stepIndex, steps[stepIndex]);
}

void drawSteps(GLuint elementBuffer, GLuint vao)
{
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}

void Game::configureVAOandVBOs()
{
	// initialize the ball vertex data
	ballVertexData[0] = 0;
	ballVertexData[1] = this->ball->position[0];
	ballVertexData[2] = this->ball->position[1];
	ballVertexData[3] = this->ball->color.getColorChannels()[0];
	ballVertexData[4] = this->ball->color.getColorChannels()[1];
	ballVertexData[5] = this->ball->color.getColorChannels()[2];
	ballVertexData[6] = this->ball->color.getColorChannels()[3];

	// initialize the steps vertex data
	for (int i = 0; i < 6; i++) initializeStepVertices(i, this->steps);

	// VAO & VBO for ball
	glBindVertexArray(this->VAO[0]);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO[0]);
	glBufferData(GL_ARRAY_BUFFER, 56, ballVertexData, GL_DYNAMIC_DRAW);

	glVertexAttribPointer(0, 1, GL_DOUBLE, GL_FALSE, 7 * 8, (void*)0); // Ball / Step indicator
	glVertexAttribPointer(1, 2, GL_DOUBLE, GL_FALSE, 7 * 8, (void*)8); // Position attributes
	glVertexAttribPointer(2, 4, GL_DOUBLE, GL_FALSE, 7 * 8, (void*)24); // Color attributes

	// VAO & VBO for steps
	glBindVertexArray(this->VAO[1]);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO[1]);
	glBufferData(GL_ARRAY_BUFFER, 4 * 7 * 6 * 8, stepsVertexData, GL_DYNAMIC_DRAW);

	glVertexAttribPointer(0, 1, GL_DOUBLE, GL_FALSE, 7 * 8, (void*)0); // Ball / Step indicator
	glVertexAttribPointer(1, 2, GL_DOUBLE, GL_FALSE, 7 * 8, (void*)8); // Position attributes
	glVertexAttribPointer(2, 4, GL_DOUBLE, GL_FALSE, 7 * 8, (void*)24); // Color attributes
}

void Game::init(GLFWwindow* window)
{
	unsigned int nObjects = 2;
	// First create VAOs, which contain everything vertex related. (VBO, EBO, data etc.)
	this->VAO = new GLuint[nObjects];
	glGenVertexArrays(nObjects, this->VAO);

	// VBOs: To bring data from CPU to GPU, create 2 VBOs
	this->VBO = new GLuint[nObjects];
	glGenBuffers(nObjects, this->VBO);


	// Configure vertices of the objects
	this->configureVAOandVBOs();
	for (int i = 0; i < 4 * 6 * 7; i++) {
		std::cout << i / 7 << ": " << stepsVertexData[i] << std::endl;
	}

	// EBO: To denote vertex indices and avoid duplication of vertices
	GLuint indices[] = {
		0,  1,  2,  1,  2,  3,
		4,  5,  6,  5,  6,  7,
		8,  9,  10, 9,  10, 11,
		12, 13, 14, 13, 14, 15,
		16, 17, 18, 17, 18, 19,
		20, 21, 22, 21, 22, 23 };
	GLuint elementBuffer;
	glGenBuffers(1, &elementBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	glClearColor(5.0/256, 205.0/256, 227.0f/256, 1.0f);
	glPointSize(20);

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);
		this->ball->draw(VAO[0]);
		drawSteps(elementBuffer, VAO[1]);
		glfwSwapBuffers(window);
		glfwPollEvents();
		nextFrame(this->ball, this->steps, VBO);
	}
}

void Game::terminate()
{
	unsigned int nObjects = 2;
	glDeleteVertexArrays(nObjects, this->VAO);
	glDeleteBuffers(nObjects, this->VBO);
	glDeleteProgram(this->shader->id);
}

void Game::moveBallLeft(double distance)
{
	this->ball->moveLeft(distance);
}

void Game::moveBallRight(double distance)
{
	this->ball->moveRight(distance);
}

void Game::moveBallUp(double distance)
{
	this->ball->moveUp(distance);
}

void Game::moveBallDown(double distance)
{
	this->ball->moveDown(distance);
}
