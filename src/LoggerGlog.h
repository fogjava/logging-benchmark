#pragma once
#include "LoggerModule.h"
#include <glog/logging.h>
class LoggerGlog : public LoggerModule {
 public:
     void init(int argc, char* argv[]) override final {
         google::InitGoogleLogging(argv[0]);
	 google::SetLogDestination(google::GLOG_INFO, "/home/vboxuser/log/info_");
     }

     void log_info(const std::string& msg) override final {
         LOG(INFO) << msg;
     }

     void shutdown() override final {
         google::ShutdownGoogleLogging();
     }
};
