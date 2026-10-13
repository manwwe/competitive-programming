// https://leetcode.com/problems/maximum-alternating-sum-of-squares/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long maxAlternatingSum(vector<int> &nums) {
        long long score = 0;
        vector<long long> ve;

        for (int num : nums)
            ve.push_back(1LL * num * num);
        sort(ve.begin(), ve.end(), greater<long long>());

        int n = ve.size();
        int positive = (n + 1) / 2;

        for (int i = 0; i < n; i++) {
            if (i < positive)
                score += ve[i];
            else
                score -= ve[i];
        }

        return score;
    }
};
