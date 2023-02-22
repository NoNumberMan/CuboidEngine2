#pragma once

template<typename T> requires requires (T t) { ++t; }
T Inc(T t) { return ++t;  }

template<int N>
consteval int Inc() { return N + 1; }

namespace ce {
	int create_window();
}
