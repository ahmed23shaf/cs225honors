#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <chrono>
#include <random>

// Radix Sorting Function
// Obtained from https://sortingsearching.com/2015/09/26/radix-sort.html
void radixSort(std::vector<int> &data) 
{
    constexpr int word_bits = std::numeric_limits<int>::digits;

    int max_bits = 1;
    while ((static_cast<size_t>(1) << (3 * (max_bits + 1))) <= data.size()) {
        ++max_bits;
    }
    const int num_groups = (word_bits + max_bits - 1) / max_bits;

    // Temporary arrays.
    std::vector<size_t> count;
    std::vector<int> new_data(data.size());

    // Iterate over bit groups, starting from the least significant.
    for (int group = 0; group < num_groups; ++group) {
        // The current bit range.
        const int start = group * word_bits / num_groups;
        const int end = (group + 1) * word_bits / num_groups;
        const int mask = (static_cast<size_t>(1) << (end - start)) - 1;

        // Count the values in the current bit range.
        count.assign(static_cast<size_t>(1) << (end - start), 0);
        for (const int &x : data) ++count[(x >> start) & mask];

        // Compute prefix sums in count.
        size_t sum = 0;
        for (size_t &c : count) {
            size_t new_sum = sum + c;
            c = sum;
            sum = new_sum;
        }

        // Shuffle data elements.
        for (const int &x : data) {
            size_t &pos = count[(x >> start) & mask];
            new_data[pos++] = x;
        }

        // Move the data to the original array.
        data.swap(new_data);
    }
}

int main() 
{
    const int numberOfElements = 100000000;
    const int minValue = 1;
    const int maxValue = 100;

    std::vector<int> data(numberOfElements);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(minValue, maxValue);

    // Fill data with a unsorted integer list
    for (int& num : data) 
    {
        num = dis(gen);
    }

    std::cout << "# of elements: " << numberOfElements << '\n';

    // std::sort
    std::vector<int> stdSortData = data;
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(stdSortData.begin(), stdSortData.end());
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "std::sort took " << duration.count() << " milliseconds" << '\n';

    // Radix Sort
    std::vector<int> radixSortData = data;
    start = std::chrono::high_resolution_clock::now();
    radixSort(radixSortData);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Radix sort took " << duration.count() << " milliseconds" << '\n';

    return 0;
}
