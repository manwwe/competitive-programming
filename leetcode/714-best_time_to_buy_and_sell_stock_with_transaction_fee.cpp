// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int cash = 0, hold = -prices[0];

        for (int price : prices) {
            int prev_cash = cash;
            cash = max(cash, hold + price - fee);
            hold = max(hold, prev_cash - price);
        }

        return cash;
    }
};
