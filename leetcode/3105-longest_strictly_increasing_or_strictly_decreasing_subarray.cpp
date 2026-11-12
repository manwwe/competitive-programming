// https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = 1, dec = 1, max_len = 1;

        for (int i = 1; i < nums.size(); i++) {
            inc = nums[i] > nums[i - 1] ? inc + 1 : 1;
            dec = nums[i] < nums[i - 1] ? dec + 1 : 1;
            max_len = max({max_len, inc, dec});
        }

        return max_len;
    }
};
