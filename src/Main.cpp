#include<iostream>
#include "Game.h"

Game* game;

void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

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
	if (key == GLFW_KEY_LEFT) {
		game->setBallHorizontalVelocity(-action - 1);
	}

	if (key == GLFW_KEY_RIGHT) {
		game->setBallHorizontalVelocity(action + 1);
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
	GLenum err=glewInit();
	if(err!=GLEW_OK) {
		// Problem: glewInit failed, something is seriously wrong.
		std::cout << "glewInit failed: " << glewGetErrorString(err) << std::endl;
		exit(1);
	}
	glViewport(0, 0, 400, 600);
	glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
	game = new Game();
	glfwSetKeyCallback(window, key_callback);
	game->init(window);
	game->terminate();


	return 0;
}