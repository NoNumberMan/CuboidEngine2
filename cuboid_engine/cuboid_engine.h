// CuboidEngine.h : Include file for standard system include files,
// or project specific include files.

#pragma once

template<typename T> requires requires (T t) { ++t; }
T Inc(T t) { return ++t;  }

template<int N>
consteval int Inc() { return N + 1; }

void create_window();
	


