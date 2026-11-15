// https://leetcode.com/problems/minimum-positive-sum-subarray/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int min_sum = INT_MAX;

        for (int len = l; len <= r; len++) {
            int curr_sum = 0;

            for (int i = 0; i < n; i++) {
                curr_sum += nums[i];
                if (i >= len) curr_sum -= nums[i - len];
                if (i >= len - 1 && curr_sum > 0)
                    min_sum = min(min_sum, curr_sum);
            }
        }

        return min_sum == INT_MAX ? -1 : min_sum;
    }
};
