#include <iostream>
#include <chrono>
#include <random>
#include "lis_dp.h"
#include "lis_reg.h"

using namespace std;
using namespace std::chrono;

int main() 
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distr(1, 1000);

    vector<int> nums;

    // Control input size n here
    for (int i = 0; i < 100; ++i)
    {
        nums.push_back(distr(gen));
    }

    // O(2^n) - DFS recursive approach
    auto start_reg = high_resolution_clock::now();
    int result_reg = lengthOfLIS_reg(nums);
    auto stop_reg = high_resolution_clock::now();

    auto duration_reg = duration_cast<microseconds>(stop_reg - start_reg);
    cout << "O(2^n) Answer: " << result_reg << endl;
    cout << "O(2^n) Time: " << duration_reg.count() << " µs" << endl << endl;

    // O(n^2) - Dynamic Programming
    auto start_dp = high_resolution_clock::now();
    int res_dp = lengthOfLIS_dp(nums);
    auto stop_dp = high_resolution_clock::now();

    auto duration_dp = duration_cast<microseconds>(stop_dp - start_dp);
    cout << "O(n^2) Answer: " << res_dp << endl;
    cout << "O(n^2) Time: " << duration_dp.count() << " µs" << endl;

    return 0;
}
