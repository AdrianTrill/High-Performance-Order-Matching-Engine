# High-Performance Order Matching Engine

## Overview
This project implements a high-performance **Order Matching Engine (OME)** designed for low-latency execution of limit and market orders.

## Features
- Efficient priority-based order matching using heaps.
- Multi-threaded execution with lock-free optimizations.
- Real-time order simulation and performance benchmarks.

## Build Instructions
```
make
./order_matching
```

## Performance Testing
Run latency benchmarks:
```
g++ -std=c++17 -O2 -Wall -Wextra -pthread benchmarks/latency_test.cpp -o latency_test
./latency_test
```