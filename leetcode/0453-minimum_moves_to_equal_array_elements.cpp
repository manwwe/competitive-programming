// https://leetcode.com/problems/minimum-moves-to-equal-array-elements/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min_num = *min_element(nums.begin(), nums.end());
        long long moves = 0;

        for (int num : nums) moves += (long long)num - min_num;

        return moves;
    }
};
