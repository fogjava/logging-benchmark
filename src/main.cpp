#include <iostream>
#include "benchmark.h"
#include "LoggerGlog.h"
#include "LoggerSpdlog.h"
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

   LoggerSpdlog logger1;
   logger1.init(argc, argv);
   BenchmarkRunner runner1(&logger1, 4, 100000);
   runner1.run();
   logger1.shutdown();
   return 0;
}
