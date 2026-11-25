// https://leetcode.com/problems/smallest-unique-subarray/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sa(n), rnk(nums), tmp(n);
        iota(sa.begin(), sa.end(), 0);

        for (int k = 1;; k <<= 1) {
            auto key = [&](int i) { return make_pair(rnk[i], i + k < n ? rnk[i + k] : -1); };
            sort(sa.begin(), sa.end(), [&](int a, int b) { return key(a) < key(b); });

            tmp[sa[0]] = 0;
            for (int i = 1; i < n; i++)
                tmp[sa[i]] = tmp[sa[i - 1]] + (key(sa[i - 1]) < key(sa[i]));
            rnk = tmp;

            if (rnk[sa[n - 1]] == n - 1 || k >= n) break;
        }

        vector<int> lcp(n + 1, 0);
        for (int i = 0, h = 0; i < n; i++) {
            if (rnk[i] == 0) {
                h = 0;
                continue;
            }
            int j = sa[rnk[i] - 1];
            while (i + h < n && j + h < n && nums[i + h] == nums[j + h]) h++;
            lcp[rnk[i]] = h;
            if (h > 0) h--;
        }

        int res = n;
        for (int r = 0; r < n; r++) {
            int len = max(lcp[r], lcp[r + 1]) + 1;
            if (len <= n - sa[r]) res = min(res, len);
        }

        return res;
    }
};
