#pragma once
#include "LoggerModule.h"
#include <thread>
#include <vector>
#include <atomic>
class BenchmarkRunner {
 public:
     BenchmarkRunner(LoggerModule* logger, int threads, int logs_per_thread)
	     : logger_(logger), num_threads(threads), logs_per_thread_(logs_per_thread) {}
     void run();
 private:
     void write_csv(const std::string& logger_name, int total_logs, double elapsed_s, double logs_per_s);
     LoggerModule* logger_;
     int num_threads;
     int logs_per_thread_;
};
