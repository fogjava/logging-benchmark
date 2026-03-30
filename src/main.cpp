#include <iostream>
#include "benchmark.h"
#include "LoggerGlog.h"
#include "BenchmarkRunner.h"
int main(int argc, char** argv) {
/*
   std::cout << " Logging benchmark start" << std::endl;
   run_benchmark("empty", [](int i) {}, 4, 1000000);
  */
   LoggerGlog logger;
   logger.init(argc, argv);
   BenchmarkRunner runner(&logger, 4, 100000);
   runner.run();
   logger.shutdown();
   return 0;
}
