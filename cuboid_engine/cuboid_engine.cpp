#include "cuboid_engine.h"

#include <cassert>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <cstdio>
#include <exception>
#include <format>
#include <iostream>
#include <string_view>
#include "glm/glm.hpp"

namespace ce {

	namespace internal {
		static GLFWwindow* window = nullptr;
	}




	void init(const ce_init_data& data) {
		using namespace internal;

		init_logger(data.logName, data.logName, data.logLevel);
		get_logger()->log("Logger {0}\n", "initialized");

		assert(window == nullptr && "Window already exists!");

		if (!glfwInit()) return;
		window = glfwCreateWindow(512, 512, "hello", nullptr, nullptr);
		glfwMakeContextCurrent(window);

		if (!gladLoadGL()) return;

		while (!glfwWindowShouldClose(window)) {
			glfwPollEvents();
		}

		glfwTerminate();
	}

}



