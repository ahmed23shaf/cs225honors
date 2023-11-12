#include "lis_dp.h"
using namespace std;
// #include <iostream>

// O(n^2)
int lengthOfLIS_dp(vector<int>& nums) 
{
    int n = nums.size();
    if (n == 0) 
    {
        return 0;
    }

    // "memoization" array
    vector<int> LIS(n, 1);

    for (int i = nums.size()-1; i >= 0; i--) {
        for (int j = i+1; j < nums.size(); j++) {
            if (nums[i] < nums[j])
            {
                LIS[i] = max(LIS[i], LIS[j] + 1);
            }
        }
    }

    // for (auto e : LIS)
    // {
    //     cout << e << endl;
    // }
    auto max = max_element(LIS.begin(), LIS.end());
    return *max;
}
