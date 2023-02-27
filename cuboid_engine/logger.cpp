#include <cassert>

#include "cuboid_engine.h"

namespace ce {

	namespace internal {
		static std::unique_ptr<logger> logr;

		logger::logger(const std::string& loggerName, const std::string& loggerFile, const log_level lvl) :
			loggerName(loggerName), logLevel(lvl) {

			try {
				loggerStream.open(loggerFile, std::ios_base::in);
			}
			catch(std::exception except) {
				log("Failed to initialize logger", 2);
			}
		}

		logger::logger(const std::string& loggerName, const log_level lvl) :
			loggerName(loggerName), logLevel(lvl) { }

		logger::~logger() {
			if (loggerStream.is_open()) {
				log("Closing logger stream...");
				loggerStream.close();
			}
		}

		void logger::set_log_level(const log_level lvl) {
			logLevel = lvl;
		}


		void init_logger( const std::string& loggerName, const std::string& loggerFile, const log_level lvl ) {
			assert(logr == nullptr && "Logger already exists!");
			logr = std::make_unique<logger>(loggerName, loggerFile, lvl);
		}

		void init_logger(const std::string& loggerName, const log_level lvl) {
			assert(logr == nullptr && "Logger already exists!");
			logr = std::make_unique<logger>(loggerName, lvl);
		}

		logger* get_logger() {
			return logr.get();
		}
	}

	void set_log_level(const log_level lvl) {
		internal::get_logger()->set_log_level(lvl);
	}

}
