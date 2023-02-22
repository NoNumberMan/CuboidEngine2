#include "cuboid_engine.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <cstdio>

void create_window() {
	glfwInit();
	GLFWwindow* w = glfwCreateWindow(512, 512, "ello", nullptr, nullptr);
	glfwMakeContextCurrent(w);

	int version = gladLoadGL();
	if (version == 0) {
		printf("Failed to initialize OpenGL context\n");
		return;
	}
	else printf("hi3\n");

	while(!glfwWindowShouldClose( w )) {
		glfwPollEvents();
	}

	glfwTerminate();
}
