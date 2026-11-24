// https://leetcode.com/problems/maximum-subarray-with-equal-products/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size(), res = 0;
        const long long LIMIT = 2520LL * 10;

        for (int i = 0; i < n; i++) {
            long long prod = 1, g = 0, l = 1;

            for (int j = i; j < n; j++) {
                prod *= nums[j];
                if (prod > LIMIT) break;
                g = gcd(g, (long long)nums[j]);
                l = lcm(l, (long long)nums[j]);
                if (prod == g * l) res = max(res, j - i + 1);
            }
        }

        return res;
    }
};
