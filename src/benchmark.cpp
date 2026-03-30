#include "benchmark.h"
#include <thread>
#include <vector>
#include <chrono>
#include <iostream>

void run_benchmark(const std::string& name,
		   std::function<void(int)> fn,
		   int n_threads,
		   int n_logs) {
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<std::thread> threads;

    for (int t = 0; t < n_threads; t++) {
       threads.emplace_back([&]() {
          for (int i = 0; i < n_logs; i++) {
	     fn(i);
	  }
	});
    }

    for (auto& t : threads) t.join();

    auto end = std::chrono::high_resolution_clock::now();
    double sec = std::chrono::duration<double>(end - start).count();
    double throughput = (double)(n_threads * n_logs) / sec;

    std::cout << name << " | threads= " << n_threads << " | throughput= " << throughput << " logs/sec" << std::endl;
}
