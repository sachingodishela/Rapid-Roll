#include "Step.h"

bool Step::touches(double X, double Y, double radius)
{
	if(
	(this->position[0] - (this->width / 2) < X)
	&&
	(this->position[0] + (this->width / 2) > X)
	&&
	(this->position[1] + (this->height / 2) - Y + radius > -0.008)
	&&
	(this->position[1] + (this->height / 2) - Y + radius < 0.008)
	)
	{
		return true;
	}
	return false;
}

void Step::draw(unsigned int vao)
{
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glDrawArrays(GL_POINTS, 0, 1);
}