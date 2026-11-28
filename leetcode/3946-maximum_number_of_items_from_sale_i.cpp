// https://leetcode.com/problems/maximum-number-of-items-from-sale-i/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        const int MAXF = 1500;
        vector<int> cnt(MAXF + 1, 0);
        int minPrice = INT_MAX;
        for (auto& it : items) {
            cnt[it[0]]++;
            minPrice = min(minPrice, it[1]);
        }

        vector<int> dp(budget + 1, INT_MIN);
        dp[0] = 0;

        for (auto& it : items) {
            int f = it[0], p = it[1], value = 0;
            for (int m = f; m <= MAXF; m += f) value += cnt[m];

            for (int c = budget; c >= p; c--)
                if (dp[c - p] != INT_MIN)
                    dp[c] = max(dp[c], dp[c - p] + value);
        }

        int res = 0;
        for (int c = 0; c <= budget; c++)
            if (dp[c] != INT_MIN)
                res = max(res, dp[c] + (budget - c) / minPrice);

        return res;
    }
};
