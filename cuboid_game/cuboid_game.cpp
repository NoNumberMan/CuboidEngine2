#include <format>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include "cuboid_engine.h"

int main() {

	ce::init({.logFile = "out.txt", .logName = "CuboidGame"});
	ce::log("this is a {0}\n", "msg");

	// ce::init({.windowSize = 1,
	// .loggerFile = "log.txt",
	// .loggerName = ""}); //Maybe add more stuff later

	// [dd/hh/mm/ss][Name] - msg

	// ce::start(game : public CuboidGame) //

	// ce::run(loadSequence, menuHandler)

	// in menuHandler, we create a button with a callback, such that
	// addButton(x, y, [](int rx, int ry, int evt) { ce::open_world<game_world>() });

	// notice open_world initializes game_world by itself. game_world inherits from cuboid_world,
	// and defines all game behaviour. Including menus, UI, events such as clicks, etc.
}