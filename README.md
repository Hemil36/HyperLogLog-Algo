# HyperLogLog-Algo

HyperLogLog Implementation

📌 Overview

This repository contains an implementation of the HyperLogLog (HLL) algorithm — a probabilistic data structure used for cardinality estimation (i.e., estimating the number of distinct elements in a dataset).

Instead of storing all elements, HyperLogLog uses hashing and bit-pattern analysis to provide an approximate distinct count with very low memory usage.

**Compilation**

```
# Compile HyperLogLog class
g++ -c hyperloglog.cpp -o hyperloglog.o

# Compile main program
g++ -c main.cpp -o main.o

# Link object files to create executable
g++ main.o hyperloglog.o -o main.exe

# Run the program
./main.exe
```

