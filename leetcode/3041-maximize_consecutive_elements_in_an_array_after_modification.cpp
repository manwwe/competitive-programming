// https://leetcode.com/problems/maximize-consecutive-elements-in-an-array-after-modification/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> dp;
        int res = 0;

        for (int x : nums) {
            dp[x + 1] = dp[x] + 1;
            dp[x] = dp[x - 1] + 1;
            res = max({res, dp[x], dp[x + 1]});
        }

        return res;
    }
};
