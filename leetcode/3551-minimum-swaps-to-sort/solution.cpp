#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<pair<int, int>, int>> order;

        for (int i = 0; i < n; i++) {
            int x = nums[i], sum = 0;
            while (x) {
                sum += x % 10;
                x /= 10;
            }
            order.push_back({{sum, nums[i]}, i});
        }

        sort(order.begin(), order.end());

        vector<bool> visited(n, false);
        int min_swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;

            int j = i, cycle_size = 0;
            while (!visited[j]) {
                visited[j] = true;
                j = order[j].second;
                cycle_size++;
            }

            min_swaps += cycle_size - 1;
        }

        return min_swaps;
    }
};
