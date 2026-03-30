#pragma once
#include <string>

class LoggerModule {
 public:
     virtual ~LoggerModule() = default;
     virtual void init(int argc, char* argv[]) = 0;

     virtual void log_info(const std::string& msg) = 0;
     virtual void shutdown() = 0;
};
