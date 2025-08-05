# Multithreaded Merge Sort in C++

This project implements a comparison between a **standard single-threaded merge sort** and a **multithreaded version** using POSIX Threads (`pthread`) in C++.

---

## Overview

Merge sort is a classic divide-and-conquer sorting algorithm. The single-threaded version recursively sorts both halves sequentially.

The multithreaded version splits large arrays into two halves and sorts them concurrently using separate threads. Threads are joined before merging the sorted halves.

---

## How It Works

### 1. Include the `pthread` Library  
Enable multithreading support:
```cpp
#include <pthread.h>
```

### 2. Thread Parameter Struct  
Define a structure to pass array pointers and index ranges (`low`, `high`) into thread functions.

### 3. Threaded Recursive Sort  
Each thread executes the recursive sorting function on its assigned subarray.

### 4. Thread Joining  
Use `pthread_join()` to wait for threads to finish before merging sorted subarrays.

---

## Threshold Optimization

To minimize thread creation overhead, sorting falls back to the single-threaded version when array size < threshold (e.g. 5000 elements). For larger arrays, the algorithm leverages multithreading for faster performance.

---

## Performance Comparison

Benchmark results highlight how the multithreaded implementation significantly improves sorting time for large inputs compared to the sequential version.

---

## Features

- **Single-threaded merge sort** for baseline comparison  
- **Multithreaded merge sort** using POSIX threads  
- **Adaptive threshold** to balance overhead and performance  
- **Benchmarking** for performance evaluation

---

## Tech Stack

- Language: **C++**  
- Library: **POSIX Threads (`pthread`)**  
- Compiler: `g++` or `gcc` with `-pthread` flag

---

## Usage

Compile and run with:
```bash
g++ -pthread -o parallel_sort src/app/*.cpp
./parallel_sort
```

---
