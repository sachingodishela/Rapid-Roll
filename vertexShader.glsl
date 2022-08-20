#version 430 core
layout (location = 0) in double type;
layout (location = 1) in vec2 position;
layout (location = 2) in vec4 color;
out vec4 vertexColor;
void main()
{
	gl_Position = vec4(position.x, position.y, 0, 1.0f);
	vertexColor = color;
}