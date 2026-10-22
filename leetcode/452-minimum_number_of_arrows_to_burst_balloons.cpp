// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });

        int arrows = 0;
        long long prev_end = LLONG_MIN;

        for (auto& point : points) {
            if (point[0] > prev_end) {
                arrows++;
                prev_end = point[1];
            }
        }

        return arrows;
    }
};
