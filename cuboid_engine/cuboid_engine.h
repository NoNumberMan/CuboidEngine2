#pragma once

#define CE_EXPORT __declspec(dllexport)

#include "logger.h"

namespace ce {

	CE_EXPORT struct ce_window_size {
		size_t width;
		size_t height;
	};

	CE_EXPORT struct ce_init_data {
		ce_window_size windowSize		= {0, 0};
		std::string logFile				= "";
		std::string logName				= "CuboidGame";
		log_level logLevel				= 0;
	};



	CE_EXPORT void init(const ce_init_data&);

	CE_EXPORT void run();

}
