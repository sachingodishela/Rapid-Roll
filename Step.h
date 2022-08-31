#pragma once
#include "PhysicalObject.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Color.h"

class Step :
    public PhysicalObject
{
public:
    double width;
    double height;
    Step(double centerX, double centerY, double lengthX, double lengthY)
    {
        this->position[0] = centerX;
        this->position[1] = centerY;
        this->width = lengthX;
        this->velocity[0] = 0;
        this->velocity[1] = 0.05;
        this->height = lengthY;
        this->color = Color(BLUE);
    }
    bool touches(double, double, double);
    void draw(unsigned int);
};

