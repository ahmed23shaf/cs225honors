#include "vector.h"
// #include "list.h"
#include <iostream>
#include <chrono>

int main() {
    const int numIterations = 100000; // Adjust the number of iterations as needed
    List list;

    // Measure the time it takes to insertFront
    auto start_time = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < numIterations; ++i) {
        list.insertFront(i);
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

    std::cout << "Time taken for " << numIterations << " insertFront operations: " << elapsed_time << " ms" << std::endl;

    // Reset the list for the next test
    list = List();

    // Measure the time it takes to insertMiddle
    start_time = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < numIterations; ++i) {
        list.insertMiddle(i);
    }

    end_time = std::chrono::high_resolution_clock::now();
    elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

    std::cout << "Time taken for " << numIterations << " insertMiddle operations: " << elapsed_time << " ms" << std::endl;

    return 0;
}
