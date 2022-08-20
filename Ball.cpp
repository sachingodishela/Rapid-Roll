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
}

void Ball::moveRight(double distance = 0.5)
{
	this->position[0] += distance;
}

void Ball::moveUp(double distance)
{
	this->position[1] += distance;
}

void Ball::moveDown(double distance)
{
	this->position[1] -= distance;
}