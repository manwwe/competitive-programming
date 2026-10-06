// https://leetcode.com/problems/maximum-average-subarray-i/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    double findMaxAverage(vector<int> &nums, int k) {
        int current_sum = reduce(nums.begin(), nums.begin() + k);
        int max_sum = current_sum;

        for (int right = k; right < nums.size(); right++) {
            current_sum -= nums[right - k];
            current_sum += nums[right];

            max_sum = max(max_sum, current_sum);
        }

        return (double)max_sum / k;
    }
};
