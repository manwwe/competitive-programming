// https://leetcode.com/problems/find-target-indices-after-sorting-array/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> result;
        int smaller = 0;
        int equal = 0;

        for (int num : nums) {
            if (num < target) smaller++;
            else if (num == target) equal++;
        }

        for (int i = smaller; i < smaller + equal; i++) result.push_back(i);

        return result;
    }
};
