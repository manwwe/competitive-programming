// https://leetcode.com/problems/sum-of-sortable-integers/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());

        auto check = [&](int k) {
            for (int i = 0; i < n; i += k) {
                int start = 0, drops = 0;

                for (int j = 0; j < k; j++) {
                    if (nums[i + j] > nums[i + (j + 1) % k]) {
                        drops++;
                        start = (j + 1) % k;
                    }
                }

                if (drops > 1) return false;

                for (int j = 0; j < k; j++) {
                    if (nums[i + (start + j) % k] != sorted_nums[i + j])
                        return false;
                }
            }
            return true;
        };

        int res = 0;

        for (int k = 1; k * k <= n; k++) {
            if (n % k != 0) continue;

            if (check(k)) res += k;

            if (k != n / k && check(n / k))
                res += n / k;
        }

        return res;
    }
};
