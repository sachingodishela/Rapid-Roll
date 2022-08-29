#include "PhysicalObject.h"

void PhysicalObject::draw(unsigned int vao)
{
	return;
}

bool PhysicalObject::touches(double X, double Y)
{
	return X == this->position[0] and Y == this->position[1];
}
