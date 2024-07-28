#include "Ball.h"

void Ball::draw(unsigned int vao)
{
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 25);
}

void Ball::moveLeft(double distance = 1)
{
	this->position[0] -= distance;
	if (this->position[0] < -1) this->position[0] += 2;
}

void Ball::moveRight(double distance = 0.5)
{
	this->position[0] += distance;
	if (this->position[0] > 1) this->position[0] -= 2;
}

void Ball::updateXPositionForNextFrame()
{
	if (this->velocity[0]) {
		this->position[0] += this->velocity[0] * 0.01;
	}
	if (this->position[0] >= 1 - this->radius) this->position[0] = 1 - this->radius;
	else if (this->position[0] < -1 + this->radius) this->position[0] = -1 + this->radius;
}

bool Ball::touches(double X, double Y)
{
	return true;
}