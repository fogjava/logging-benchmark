#include "BenchmarkRunner.h"
#include <chrono>
#include <iostream>

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
    std::cout << "Total logs: " << counter.load() << std::endl;
    std::cout << "Time taken: " << sec << " s" << std::endl;
    std::cout << "Logs per second: " << counter.load() / sec << std::endl;
}
