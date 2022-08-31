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
	double radius;
	Ball(colors ballColor, double radius) {
		this->lives = 3;
		this->position[0] = 0.0;
		this->position[1] = 0.0;
		this->velocity[0] = 0.0;
		this->velocity[1] = -0.05;
		this->acceleration[0] = 0.0;
		this->acceleration[1] = 0.0;
		this->radius = radius;
		this->color = Color(ballColor);
	}
	void draw(unsigned int);
	bool touches(double, double);
	void moveLeft(double);
	void moveRight(double);
};

