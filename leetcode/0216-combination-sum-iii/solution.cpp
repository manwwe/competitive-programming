// https://leetcode.com/problems/combination-sum-iii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> curr;

        auto dfs = [&](auto&& dfs, int start, int sum) -> void {
            if (curr.size() == k) {
                if (sum == n) res.push_back(curr);
                return;
            }

            for (int i = start; i <= 9; i++) {
                if (sum + i > n) break;

                curr.push_back(i);
                dfs(dfs, i + 1, sum + i);
                curr.pop_back();
            }
        };

        dfs(dfs, 1, 0);
        return res;
    }
};
