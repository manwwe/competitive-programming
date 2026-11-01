// https://leetcode.com/problems/longest-consecutive-sequence/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int res = 0;

        for (int num : st) {
            if (!st.count(num - 1)) {
                int curr = num;
                int len = 1;

                while (st.count(curr + 1)) {
                    curr++;
                    len++;
                }

                res = max(res, len);
            }
        }

        return res;
    }
};
