// https://leetcode.com/problems/find-pivot-index/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int pivotIndex(vector<int> &nums) {
        int left = 0;
        int total_sum = reduce(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            int right = total_sum - left - nums[i];

            if (left == right) {
                return i;
            }

            left = left + nums[i];
        }

        return -1;
    }
};
