cmake_minimum_required(VERSION 3.10)
project(logging_benchmark)

set(CMAKE_CXX_STANDARD 17)
add_executable(bench
	       src/main.cpp
	       src/benchmark.cpp
              )
