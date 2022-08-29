#include "Step.h"

bool Step::touches(double X, double Y)
{
	return this->position[1] - this->height / 2 <= Y and
		this->position[1] + this->height / 2 >= Y and
		this->position[0] - this->width / 2 <= X and
		this->position[0] + this->width / 2 >= X;
}

void Step::draw(unsigned int vao)
{
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glDrawArrays(GL_POINTS, 0, 1);
}