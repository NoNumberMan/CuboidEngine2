#pragma once

#define CE_EXPORT __declspec(dllexport) //TODO define this in other header
#include <format>
#include <fstream>
#include <iostream>

namespace ce {
	using log_level = unsigned int;


	namespace internal {
		class logger {
			private:
			const std::string loggerName;
			std::fstream loggerStream;
			log_level logLevel;

			public:
			logger(const std::string& loggerName, const std::string& loggerFile, const log_level lvl);
			logger(const std::string& loggerName, const log_level lvl);
			~logger();

			void set_log_level(const log_level lvl);


			template<class... Types>
			void log(const std::string_view str, const Types&... args) {
				print(str, args...);
			}

			template<class... Types>
			void log(const std::string_view str, const log_level lvl, const Types&... args) {
				if (lvl >= logLevel) print(str, args...);
			}

			template<class... Types>
			void print(const std::string_view str, const Types&... args) {
				const std::string fmt = std::format(str, args...);

				if (loggerStream.is_open()) loggerStream << fmt;
				std::cout << fmt;
			}
		};

		void init_logger(const std::string& loggerName, const std::string& loggerFile, const log_level lvl);
		void init_logger(const std::string& loggerName, const log_level lvl);

		logger* get_logger();
	}


	template<class... Types>
	void log(const std::string_view str, const Types&... args) {
		internal::get_logger()->log(str, args...);
	}

	template<class... Types>
	void log(const std::string_view str, const log_level lvl, const Types&... args) {
		internal::get_logger()->log(str, lvl, args...);
	}

	CE_EXPORT void set_log_level(const log_level lvl);
}
