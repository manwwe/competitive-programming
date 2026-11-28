// https://leetcode.com/problems/maximum-number-of-items-from-sale-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<long long> cnt(n + 1, 0), reach(n + 1, 0);
        long long minPrice = LLONG_MAX;
        for (auto& it : items) {
            cnt[it[0]]++;
            minPrice = min(minPrice, (long long)it[1]);
        }

        for (int f = 1; f <= n; f++)
            if (cnt[f])
                for (int m = f; m <= n; m += f) reach[f] += cnt[m];

        vector<pair<long long, long long>> offers;
        for (auto& it : items)
            if (reach[it[0]] > 1) offers.push_back({it[1], reach[it[0]] - 1});
        sort(offers.begin(), offers.end());

        long long left = budget, doubled = 0, res = left / minPrice;
        for (auto [price, units] : offers) {
            long long take = min(units, left / price);
            doubled += take;
            left -= take * price;
            res = max(res, 2 * doubled + left / minPrice);
            if (take < units) break;
        }

        return res;
    }
};
