#include "lis_reg.h"

// O(2^n)
int LIS_recursive(vector<int>& nums, int prevIndex, int currentIndex) 
{
    if (currentIndex == nums.size() || prevIndex == nums.size()) 
    {
        return 0;
    }

    int includeCurrent = 0;
    if (nums[currentIndex] > nums[prevIndex]) 
    {
        includeCurrent = 1 + LIS_recursive(nums, currentIndex, currentIndex + 1);
    }

    int excludeCurrent = LIS_recursive(nums, prevIndex, currentIndex + 1);

    return max(includeCurrent, excludeCurrent);
}

int lengthOfLIS_reg(vector<int>& nums) 
{
    return LIS_recursive(nums, -1, 0);
}