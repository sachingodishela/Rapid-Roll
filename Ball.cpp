#include "Ball.h"

void Ball::draw(unsigned int vao)
{
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glDrawArrays(GL_POINTS, 0, 1);
}

void Ball::moveLeft(double distance = 0.5)
{
	this->position[0] -= distance;
	if (this->position[0] < -1) this->position[0] += 2;
}

void Ball::moveRight(double distance = 0.5)
{
	this->position[0] += distance;
	if (this->position[0] > 1) this->position[0] -= 2;
}

void Ball::moveUp(double distance)
{
	this->position[1] += distance;
	if (this->position[1] > 1) this->position[1] -= 2;
}

void Ball::moveDown(double distance)
{
	this->position[1] -= distance;
	if (this->position[1] < -1) this->position[1] += 2;
}

bool Ball::touches(double X, double Y)
{
	return true;
}