#pragma once
#include <functional>
#include <string>
void run_benchmark(const std::string& name,
		   std::function<void(int)> fn,
		   int n_threads,
		   int n_logs);
