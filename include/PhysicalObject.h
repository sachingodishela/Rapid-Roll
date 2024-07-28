#pragma once
#include "Color.h"

class PhysicalObject
{
public:
	double position[2];
	Color color;
	double velocity[2];
	double acceleration[2];
	virtual void draw(unsigned int vao);
	virtual bool touches(double X, double Y);
};

