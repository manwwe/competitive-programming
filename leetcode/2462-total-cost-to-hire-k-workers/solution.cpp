// https://leetcode.com/problems/total-cost-to-hire-k-workers/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        int left = 0, right = n - 1;
        long long total_cost = 0;

        priority_queue<int, vector<int>, greater<int>> left_heap, right_heap;

        for (int i = 0; i < candidates && left <= right; i++)
            left_heap.push(costs[left++]);

        for (int i = 0; i < candidates && left <= right; i++)
            right_heap.push(costs[right--]);

        while (k--) {
            if (right_heap.empty() ||
                (!left_heap.empty() && left_heap.top() <= right_heap.top())) {
                total_cost += left_heap.top();
                left_heap.pop();

                if (left <= right) left_heap.push(costs[left++]);
            } else {
                total_cost += right_heap.top();
                right_heap.pop();

                if (left <= right) right_heap.push(costs[right--]);
            }
        }

        return total_cost;
    }
};
