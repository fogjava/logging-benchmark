# Logging Benchmark

This project benchmarks and compares the performance of two popular C++ logging libraries: **glog** and **spdlog**. It provides a micro-benchmarking framework to evaluate throughput and latency in different scenarios.

## Overview

We evaluate the following:

- **glog**: Google’s logging library
- **spdlog**: High-performance, asynchronous logging library

The project provides a mechanism to:
1. Measure log throughput (logs per second).
2. Measure the latency (time taken for the logging operations).
3. Compare **glog** and **spdlog** under varying conditions (thread count, logs per thread).

### Key Features

- **Multi-threaded logging benchmark**: Measure performance across multiple threads.
- **CSV Output**: Logs results in CSV for easy analysis.
- **Python Visualization**: Generates bar charts to compare the performance.

## Requirements

- C++17 or higher
- `CMake` for building
- Python for visualization (optional)

## Build Instructions

To build the project, you need to have **CMake** installed. Follow these steps:

1. Clone the repository:

    ```bash
    git clone https://github.com/fogjava/logging-benchmark.git
    cd logging-benchmark
    ```

2. Create the build directory and run CMake:

    ```bash
    mkdir build
    cd build
    cmake ..
    ```

3. Compile the project:

    ```bash
    make -j
    ```

## Running the Benchmark

To run the benchmark, simply execute the generated executable:

```bash
./bench

### Plot
To get the plot:
```bash
python3 ../scripts/plog_logging.py
