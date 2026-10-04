#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minRotations(string s) {
        int current = 0;
        int total = 0;

        for (char digit : s) {
            int target = digit - '0';

            int distance = abs(current - target);
            int other_distance = 10 - distance;

            total += min(distance, other_distance);
            current = target;
        }
        return total;
    }
};
