# Multithreaded Merge Sort in C using `pthreads`

This project demonstrates a comparison between a **standard (single-threaded)** merge sort and a **multithreaded merge sort** using the **POSIX threads (`pthread`)** library in C.

Multithreading helps optimize performance for large datasets by running recursive sort operations in parallel.

---

## Concept Overview

### Normal Merge Sort (Single Threaded)
The standard merge sort algorithm recursively calls the sort function for the left and right halves **sequentially in a single thread**.

![Normal Merge Sort](https://github.com/user-attachments/assets/17b26930-1471-4e80-9cee-0c42b419b1c6)

---

### Multithreaded Merge Sort (Using `pthread`)

To speed up the process, we create **separate threads for sorting the left and right halves** of the array. Here’s how it works:

#### Step 1: Include the `pthread` Library
Use the POSIX Threads library to enable multithreading:

```c
#include <pthread.h>
```

#### Step 2: Create Threads

We define a structure to pass parameters like array pointer, left index, and right index into threads:

![Creating Thread Struct](https://github.com/user-attachments/assets/0f2645f6-fe30-4390-b9a4-0232e04d24a6)

Then create threads for sorting each half:

![Creating New Threads](https://github.com/user-attachments/assets/b4226221-2df8-4ac3-84bf-b978fa42a70d)

#### Step 3: Thread Function

Each thread runs a recursive sort on its portion of the array:

![Thread Function](https://github.com/user-attachments/assets/027bd136-6e0a-4b35-8cbf-fa0fab5f92cf)

#### Step 4: Join Threads

We use `pthread_join()` to ensure that one thread waits for another to finish execution. This is necessary to merge sorted subarrays safely.

![Joining Threads](https://github.com/user-attachments/assets/8935297e-558a-4f0a-9ad7-1dd84824b0d7)

---

## Threshold Optimization

To avoid unnecessary overhead from creating too many threads for small arrays, we define a **threshold size** (e.g., 5000 elements).  
- If the array size is **less than the threshold**, we perform normal merge sort.  
- If it is **greater**, we use multithreading to parallelize sorting.

![Threshold Logic](https://github.com/user-attachments/assets/6789f4b7-0ef9-4fe5-8e92-8ce79a815217)

---

## Performance Comparison

A clear comparison between multithreaded and single-threaded merge sort for large arrays:

![Performance Comparison](https://github.com/user-attachments/assets/8ec1ef16-479a-449b-af22-8a9faac865fb)

---

## Features

- Efficient parallel sorting using threads  
- Threshold-based optimization to avoid thread overhead  
- Comparison benchmarking for single vs multithreaded performance

---

## Tech Stack

- Language: **C**
- Library: **POSIX Threads (`pthread`)**
- Compiler: `gcc` (with `-pthread` flag)

---

## How to Run

```bash
gcc mergesort.c -o mergesort -pthread
./mergesort
```

--- 
