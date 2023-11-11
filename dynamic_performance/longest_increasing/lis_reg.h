#pragma once
#include <vector>
#include <algorithm>

using namespace std;

int LIS_recursive(vector<int>& nums, int prevIndex, int currentIndex);
int lengthOfLIS_reg(vector<int>& nums);