// https://leetcode.com/contest/biweekly-contest-193/problems/maximum-product-pair-with-target-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> maxProductPair(vector<int> &nums, int target) {
        unordered_map<int, int> mp;

        vector<int> ans = {-1, -1};
        long long maxProduct = LLONG_MIN;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if (mp.count(complement)) {
                int j = mp[complement];

                int a = nums[i];
                int b = nums[j];

                if (a != b) {
                    long long product = 1LL * a * b;

                    if (product > maxProduct) {
                        maxProduct = product;

                        if (a > b) {
                            ans = {i, j};
                        } else {
                            ans = {j, i};
                        }
                    }
                }
            }

            mp[nums[i]] = i;
        }

        return ans;
    }
};
