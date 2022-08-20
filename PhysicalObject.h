#pragma once
#include "Color.h"

class PhysicalObject
{
public:
	double position[2];
	Color color;
	double velocity;
	double acceleration;
	virtual void draw(unsigned int vao);
};

