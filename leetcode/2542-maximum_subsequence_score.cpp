// https://leetcode.com/problems/maximum-subsequence-score/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> pairs;

        for (int i = 0; i < n; i++)
            pairs.push_back({nums2[i], nums1[i]});

        sort(pairs.rbegin(), pairs.rend());

        priority_queue<int, vector<int>, greater<int>> min_heap;
        long long curr_sum = 0, max_score = 0;

        for (auto [min_val, num] : pairs) {
            min_heap.push(num);
            curr_sum += num;

            if (min_heap.size() > k) {
                curr_sum -= min_heap.top();
                min_heap.pop();
            }

            if (min_heap.size() == k)
                max_score = max(max_score, curr_sum * min_val);
        }

        return max_score;
    }
};
