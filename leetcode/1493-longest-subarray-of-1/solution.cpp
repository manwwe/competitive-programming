// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestSubarray(vector<int> &nums) {
        int left = 0;
        int sum_zeros = 0;
        int max_ones = 0;
        int n = nums.size();

        for (int right = 0; right < n; right++) {
            if (nums[right] == 0) {
                sum_zeros++;
            }

            while (sum_zeros > 1) {
                if (nums[left] == 0) {
                    sum_zeros--;
                }
                left++;
            }

            max_ones = max(max_ones, right - left);
        }

        return max_ones;
    }
};
