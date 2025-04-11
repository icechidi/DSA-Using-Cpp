# Data Structures and Algorithms (DSA) Project

This repository contains C++ implementations and performance comparisons of fundamental algorithms in data structures and algorithms, including:

- Linear Search
- Selection Sort
- Binary Search

## Description

The code demonstrates how different algorithms perform on randomly generated arrays. It compares the time taken and the number of iterations for each operation.

### Features

- **Linear Search**: A simple search that checks each element until the key is found.
- **Selection Sort**: A basic sorting algorithm that repeatedly finds the minimum element.
- **Binary Search**: A highly efficient searching algorithm that requires a sorted array.

## Technologies Used

- C++
- `<cstdlib>` for random number generation
- `<chrono>` for measuring performance
- `<ctime>` for seeding randomness

## How to Run

1. Clone the repository:
   ```bash
   git clone https://github.com/icechidi/dsa-project.git
   cd dsa-project

2.	Compile the program:
    ```bash
    g++ -std=c++11 -o dsa main.cpp

3.	Run the executable:
    ```bash
    ./dsa
    
Output Example

Linear Search:
 Result: 682
 Time: 0.000012 seconds
 Iterations: 452

Selection Sort:
 Time: 0.003210 seconds
 Iterations: 499500

Binary Search:
 Result: 682
 Time: 0.000001 seconds
 Iterations: 9

Complexity Overview
Algorithm
Time Complexity
Linear Search
O(n)
Selection Sort
O(n²)
Binary Search
O(log n)

Note: Binary search only works on sorted arrays, which is why selection sort is applied before binary search.

Author
	• Ice Chidi

License
This project is open source and available under the MIT License.

