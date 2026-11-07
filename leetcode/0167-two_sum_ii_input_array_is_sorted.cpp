// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        vector<int> res;

        while (l < r) {
           int crr = numbers[r] + numbers[l];

           if (crr == target) return {l+1, r+1};

           if (crr < target) l++;
           else r--;
        }
        return res;
    }
};
