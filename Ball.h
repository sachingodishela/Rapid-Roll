#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Color.h"
#include "PhysicalObject.h"

class Ball : public PhysicalObject
{
private:
	unsigned int lives;
public:
	Ball(colors ballColor) {
		this->lives = 3;
		this->position[0] = 0.0;
		this->position[1] = 0.0;
		this->velocity = 0;
		this->acceleration = 0;
		this->color = Color(ballColor);
	}
	void draw(unsigned int);
	void moveLeft(double);
	void moveRight(double);
	void moveUp(double);
	void moveDown(double);
};

