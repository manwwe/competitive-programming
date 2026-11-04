// https://leetcode.com/problems/minimum-operations-to-make-elements-within-k-subarrays-equal/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        multiset<long long> low, high;
        long long sum_low = 0, sum_high = 0;

        auto balance = [&]() {
            while (low.size() > high.size() + 1) {
                long long v = *prev(low.end());
                low.erase(prev(low.end()));
                sum_low -= v;
                high.insert(v);
                sum_high += v;
            }
            while (low.size() < high.size()) {
                long long v = *high.begin();
                high.erase(high.begin());
                sum_high -= v;
                low.insert(v);
                sum_low += v;
            }
        };

        auto add = [&](long long v) {
            if (low.empty() || v <= *prev(low.end())) {
                low.insert(v);
                sum_low += v;
            } else {
                high.insert(v);
                sum_high += v;
            }
            balance();
        };

        auto remove = [&](long long v) {
            auto it = low.find(v);
            if (it != low.end()) {
                low.erase(it);
                sum_low -= v;
            } else {
                high.erase(high.find(v));
                sum_high -= v;
            }
            balance();
        };

        vector<long long> cost(n - x + 1);
        for (int i = 0; i < n; i++) {
            add(nums[i]);
            if (i >= x) remove(nums[i - x]);
            if (i >= x - 1) {
                long long median = *prev(low.end());
                cost[i - x + 1] =
                    median * low.size() - sum_low +
                    sum_high - median * high.size();
            }
        }

        const long long inf = LLONG_MAX / 4;
        vector<long long> prev_dp(n + 1, 0), curr_dp(n + 1);

        for (int j = 1; j <= k; j++) {
            fill(curr_dp.begin(), curr_dp.end(), inf);
            for (int i = x; i <= n; i++) {
                curr_dp[i] = min(curr_dp[i - 1],
                    prev_dp[i - x] + cost[i - x]);
            }
            swap(prev_dp, curr_dp);
        }

        return prev_dp[n];
    }
};
