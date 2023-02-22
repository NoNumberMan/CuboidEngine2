#include <format>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include "cuboid_engine.h"


template<class... Types>
void print(const std::string_view str, const Types&... args) {
	std::cout << std::format(str, args...);
}

int main() {
	print("Inc of {0} = {1}!\n", 1, Inc<1>());
	create_window();
}