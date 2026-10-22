// https://leetcode.com/problems/non-overlapping-intervals/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });

        int removals = 0;
        int prev_end = INT_MIN;

        for (auto& interval : intervals) {
            if (interval[0] < prev_end) removals++;
            else prev_end = interval[1];
        }

        return removals;
    }
};
