// https://leetcode.com/problems/find-the-highest-altitude/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int largestAltitude(vector<int> &gain) {
        int altitude = 0;
        int highest = 0;

        for (int i = 0; i < gain.size(); i++) {
            altitude = altitude + gain[i];
            highest = max(altitude, highest);
        }

        return highest;
    }
};
