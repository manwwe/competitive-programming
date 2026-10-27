// https://leetcode.com/problems/minimum-sum-of-squared-difference/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long minSumSquareDiff(vector<int> &nums1, vector<int> &nums2, int k1,
                               int k2) {
        int n = nums1.size();
        vector<int> diff(n);

        long long total = 0;
        int maxDiff = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
            maxDiff = max(maxDiff, diff[i]);
        }

        long long k = (long long)k1 + k2;

        if (total <= k) {
            return 0;
        }

        int left = 0, right = maxDiff;

        while (left < right) {
            int mid = left + (right - left) / 2;

            long long operations = 0;

            for (int d : diff) {
                if (d > mid) {
                    operations += d - mid;
                }
            }

            if (operations <= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        int threshold = left;

        for (int &d : diff) {
            if (d > threshold) {
                k -= d - threshold;
                d = threshold;
            }
        }

        // Use remaining operations on differences
        // equal to the threshold.
        for (int &d : diff) {
            if (k > 0 && d == threshold) {
                d--;
                k--;
            }
        }

        long long ans = 0;

        for (int d : diff) {
            ans += 1LL * d * d;
        }

        return ans;
    }
};
