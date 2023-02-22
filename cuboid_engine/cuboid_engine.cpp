#include "cuboid_engine.h"

#include <cassert>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <cstdio>
#include <exception>

#define CE_OK 0
#define CE_GLFW_INIT_ERROR 1
#define CE_GLAD_INIT_ERROR 2

namespace ce {

	namespace internal {
		GLFWwindow* window = nullptr;
	}

	int create_window() {
		using namespace internal;

		assert(window == nullptr && "Window already exists!");

		if (!glfwInit()) return CE_GLFW_INIT_ERROR;
		window = glfwCreateWindow(512, 512, "hello", nullptr, nullptr);
		glfwMakeContextCurrent(window);

		if (!gladLoadGL()) return CE_GLAD_INIT_ERROR;

		while (!glfwWindowShouldClose(window)) {
			glfwPollEvents();
		}

		glfwTerminate();

		return CE_OK;
	}

}



