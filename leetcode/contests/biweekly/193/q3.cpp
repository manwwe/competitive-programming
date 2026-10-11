// https://leetcode.com/contest/biweekly-contest-193/problems/longest-resilient-subarray-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int resilientSubarray(vector<int> &nums, int k) {
        int n = nums.size();
        int ans = 1;

        for (int i = 0; i < n;) {
            int r = ((nums[i] % k) + k) % k;
            int j = i;

            while (j < n && ((nums[j] % k) + k) % k == r) {
                j++;
            }

            int len = j - i;

            int step = k / gcd(k, r);

            int best = len - 1 - (len - 1) % step;

            ans = max(ans, best + 1);

            i = j;
        }

        return ans;
    }
};
