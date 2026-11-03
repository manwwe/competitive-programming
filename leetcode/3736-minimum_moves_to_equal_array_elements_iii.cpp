// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-iii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max_val = *max_element(nums.begin(), nums.end());
        int min_moves = 0;

        for (int num : nums) min_moves += max_val - num;

        return min_moves;
    }
};
