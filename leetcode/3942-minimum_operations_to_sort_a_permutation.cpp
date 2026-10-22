// https://leetcode.com/problems/minimum-operations-to-sort-a-permutation/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int pos = 0;
        bool inc = true, dec = true;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) pos = i;
            if ((nums[i] + 1) % n != nums[(i + 1) % n]) inc = false;
            if ((nums[(i + 1) % n] + 1) % n != nums[i]) dec = false;
        }

        int res = INT_MAX;

        if (inc) res = min(pos, n - pos + 2);

        if (dec) {
            res = min(res, 1 + (n - 1 - pos + n) % n);
            res = min(res, pos + 2);
        }

        return res == INT_MAX ? -1 : res;
    }
};
