#include<iostream>
#include "Game.h"

Game* game;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	//std::cout << "key=" << key << ", action=" << action << std::endl;
	if (action == GLFW_RELEASE and key == GLFW_KEY_W) {
		GLint mode[2], newMode;
		glGetIntegerv(GL_POLYGON_MODE, mode);
		if (mode[0] == GL_LINE) {
			newMode = GL_FILL;
		}
		else {
			newMode = GL_LINE;
		}
		glPolygonMode(GL_FRONT_AND_BACK, newMode);
	}
	double increment = action * 0.01;
	if (key == GLFW_KEY_LEFT) {
		game->moveBallLeft(increment);
	}

	if (key == GLFW_KEY_RIGHT) {
		game->moveBallRight(increment);
	}

	if (key == GLFW_KEY_UP) {
		game->moveBallUp(increment);
	}

	if (key == GLFW_KEY_DOWN) {
		game->moveBallDown(increment);
	}
}
int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow* window;
	window = glfwCreateWindow(400, 600, "Rapid Roll", NULL, NULL);
	if (!window) {
		std::cout << "GLFW window creation failed..." << std::endl;
		return -1;
	}
	glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "OpenGL Library Loading Failed..." << std::endl;
		return 0;
	}
	glViewport(0, 0, 400, 600);

	game = new Game();
	glfwSetKeyCallback(window, key_callback);
	game->init(window);
	game->terminate();


	return 0;
}