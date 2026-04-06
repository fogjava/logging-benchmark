#include "BenchmarkRunner.h"
#include <chrono>
#include <iostream>
#include <fstream>
#include <typeinfo>
void BenchmarkRunner::run() {
    std::atomic<int> counter(0);

    auto start = std::chrono::high_resolution_clock::now();
    std::vector<std::thread> threads;
    for (int t = 0; t < num_threads; ++t)  {
       threads.emplace_back([&]() {
          for (int i = 0; i < logs_per_thread_; i++) {
	     logger_->log_info("Logging message #" + std::to_string(i));
	     counter++;
	  }
	});
     }

    for (auto& t : threads) t.join();
    auto end = std::chrono::high_resolution_clock::now();
    double sec = std::chrono::duration<double>(end - start).count();
    double logs_per_s = counter.load() / sec;
    std::cout << "Total logs: " << counter.load() << std::endl;
    std::cout << "Time taken: " << sec << " s" << std::endl;
    std::cout << "Logs per second: " << logs_per_s << std::endl;
    std::string logger_name = typeid(*logger_).name();
    write_csv(logger_name, counter.load(), sec, logs_per_s);
}

void BenchmarkRunner::write_csv(const std::string& logger_name, int total_logs, double elapsed_s, double logs_per_s) {
   const std::string csv_file = "results/logging.csv";
   std::ifstream infile(csv_file);
   bool file_exists = infile.good();
   infile.close();

   std::ofstream out(csv_file, std::ios::app);
   if (!file_exists) {
      out << "logger, threads, total_logs, elapsed_s, logs_per_s\n";
   }
   out << logger_name << ","
       << num_threads << ","
       << total_logs << ","
       << elapsed_s << ","
       << logs_per_s << "\n";
   out.close();
}
