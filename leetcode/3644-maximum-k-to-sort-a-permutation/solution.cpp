// https://leetcode.com/problems/maximum-k-to-sort-a-permutation/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int k = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i) k &= nums[i];
        }

        return max(k, 0);
    }
};
