// https://leetcode.com/problems/count-non-decreasing-subarrays-after-k-operations/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), right = n - 1;
        long long cost = 0, res = 0;
        deque<int> dq;

        for (int left = n - 1; left >= 0; left--) {
            while (!dq.empty() && nums[dq.front()] < nums[left]) {
                int j = dq.front();
                dq.pop_front();
                int end = dq.empty() ? right + 1 : dq.front();
                cost += 1LL * (end - j) * (nums[left] - nums[j]);
            }

            dq.push_front(left);

            while (cost > k) {
                cost -= nums[dq.back()] - nums[right];
                if (dq.back() == right) dq.pop_back();
                right--;
            }

            res += right - left + 1;
        }

        return res;
    }
};
