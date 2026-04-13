cmake_minimum_required(VERSION 3.14)
project(logging_benchmark)

include (FetchContent)
FetchContent_Declare(
  ctrack
  GIT_REPOSITORY git@github.com:Compaile/ctrack.git
  GIT_TAG        main
)
FetchContent_MakeAvailable(ctrack)

set(CMAKE_CXX_STANDARD 17)
#find glog
find_package(glog REQUIRED)
find_package(spdlog REQUIRED)

add_executable(bench
	       src/main.cpp
	       src/BenchmarkRunner.cpp
              )
target_link_libraries(bench PRIVATE glog::glog spdlog::spdlog ctrack)
