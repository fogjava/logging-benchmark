#pragma once
#include "LoggerModule.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <memory>
#include "ctrack.hpp"

class LoggerSpdlog : public LoggerModule {
 public:
    void init(int argc, char* argv[]) override final {
       logger_ = spdlog::basic_logger_mt("file_logger", "/home/vboxuser/spdlog.txt");
       logger_->set_pattern("[%Y-%m-%d %H:%M:%S] [%l] %v");
    }

    void log_info(const std::string& msg) override final {
        CTRACK;
        logger_->info(msg);
    }

    void shutdown() override final {
        spdlog::shutdown();
    }
 private:
    std::shared_ptr<spdlog::logger> logger_;
};
