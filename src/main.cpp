#include <iostream>
#include "benchmark.h"
int main() {
   std::cout << " Logging benchmark start" << std::endl;
   run_benchmark("empty", [](int i) {}, 4, 1000000);
   return 0;
}
