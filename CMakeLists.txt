cmake_minimum_required(VERSION 3.10)
project(logging_benchmark)

set(CMAKE_CXX_STANDARD 17)
#find glog
find_package(glog REQUIRED)

add_executable(bench
	       src/main.cpp
	       src/BenchmarkRunner.cpp
              )
target_link_libraries(bench PRIVATE glog::glog)
