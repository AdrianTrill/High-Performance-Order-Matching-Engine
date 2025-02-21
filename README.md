# High-Performance Order Matching Engine

## Overview
This project implements a **high-performance Order Matching Engine (OME)** designed for **low-latency** execution of limit and market orders. It efficiently handles **high-frequency trading (HFT) scenarios** using advanced data structures and multithreading techniques.

## Features
✅ **Efficient Order Matching:** Uses max-heaps (buy orders) and min-heaps (sell orders) for optimal execution.  
✅ **Multithreading Support:** Processes orders in parallel for faster performance.  
✅ **Low-Latency Design:** Optimized with **lock-free data structures, cache-friendly algorithms, and SIMD acceleration**.  
✅ **Real-Time Order Simulation:** Continuously generates buy/sell orders to simulate market activity.  
✅ **Performance Benchmarking:** Includes latency measurement tools to evaluate execution speed.  

## Technologies Used
- **C++17** for high-performance computing.
- **Multithreading** for concurrent order processing.
- **Priority Queues (Heaps)** for order book management.
- **Lock-Free Hash Maps** for ultra-fast order lookup.
- **ZeroMQ** (planned) for real-time exchange simulation.

## Build & Run Instructions
### Prerequisites
Ensure you have the following installed:
- **GCC/G++ (C++17 or later)**
- **Make (for build automation)**
- **Linux/macOS/Windows (with MinGW or WSL)**

### Compilation Steps
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/High-Performance-Order-Matching-Engine.git
   cd High-Performance-Order-Matching-Engine
   ```
2. Compile the project using Makefile:
   ```bash
   make
   ```
   This will generate the executable `order_matching`.

### Running the Order Matching Engine
After compilation, run the matching engine:
```bash
./order_matching
```
This will continuously generate and match orders in real-time.

### Running Benchmarks
To measure system latency, use the built-in benchmarking tool:
```bash
./benchmarks/latency_test
```
This will output execution time in nanoseconds.

## Future Enhancements
- 🚀 **Integration with WebSockets for real-time market data.**
- 🧠 **AI-based order execution optimization.**
- ⚡ **FPGA acceleration for ultra-low-latency trading.**
- 📈 **FIX protocol support for real-world trading.**

## Contributing
Feel free to contribute by submitting issues or pull requests. Let’s build the fastest OME together! 🚀

