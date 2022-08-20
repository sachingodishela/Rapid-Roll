#include "Game.h"

template <class T>
void Game::registerObject(T* object) {
	this->physicalObjects.push_back(object);
}


void Game::configureVAOandVBOs()
{
	// configure for ball
	double ballData[] = {
		0, // 0 indicates ball
		this->physicalObjects[0]->position[0],
		this->physicalObjects[0]->position[1],
		this->physicalObjects[0]->color.getColorChannels()[0],
		this->physicalObjects[0]->color.getColorChannels()[1],
		this->physicalObjects[0]->color.getColorChannels()[2],
		this->physicalObjects[0]->color.getColorChannels()[3]
	};
	//std::cout << "R: " << ballData[3] << ", G: " << ballData[4] << ", B: " << ballData[5] << ", A: " << ballData[6] << std::endl;
	glBindVertexArray(this->VAO[0]);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(ballData), ballData, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 1, GL_DOUBLE, GL_FALSE, 7*8, (void*)0); // Ball indicator
	glVertexAttribPointer(1, 2, GL_DOUBLE, GL_FALSE, 7*8, (void*)8); // Position attributes
	glVertexAttribPointer(2, 4, GL_DOUBLE, GL_FALSE, 7*8, (void*)24); // Color attributes
}

void Game::init(GLFWwindow* window)
{
	// Register objects and start physics engine
	registerObject(this->ball);

	unsigned int nObjects = this->physicalObjects.size();

	// First create VAOs, which contain everything vertex related. (VBO, EBO, data etc.)
	this->VAO = new GLuint[nObjects];
	glGenVertexArrays(nObjects, this->VAO);

	// VBOs: To bring data from CPU to GPU, create 2 VBOs
	this->VBO = new GLuint[nObjects];
	glGenBuffers(nObjects, this->VBO);

	// Configure vertices of the objects

	glClearColor(5.0/256, 205.0/256, 227.0f/256, 1.0f);
	glPointSize(20);
	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);
		this->configureVAOandVBOs();
		for (int i = 0; i < nObjects; i++) {
			this->physicalObjects[i]->draw(this->VAO[i]);
		}
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

void Game::terminate()
{
	glDeleteVertexArrays(2, this->VAO);
	glDeleteBuffers(2, this->VBO);
	unsigned int nObjects = this->physicalObjects.size();
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
