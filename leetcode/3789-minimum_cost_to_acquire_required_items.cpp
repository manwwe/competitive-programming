// https://leetcode.com/problems/minimum-cost-to-acquire-required-items/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long common = min(need1, need2);

        long long min_cost = common * min(costBoth, cost1 + cost2);

        min_cost += (long long)(need1 - common) * min(cost1, costBoth);
        min_cost += (long long)(need2 - common) * min(cost2, costBoth);

        return min_cost;
    }
};
