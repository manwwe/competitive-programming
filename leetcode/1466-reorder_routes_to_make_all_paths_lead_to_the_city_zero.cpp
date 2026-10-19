// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> graph(n);

        for (auto& edge : connections) {
            int u = edge[0], v = edge[1];
            graph[u].push_back({v, 1});
            graph[v].push_back({u, 0});
        }

        auto dfs = [&](auto&& self, int city, int parent) -> int {
            int changes = 0;

            for (auto [next_city, cost] : graph[city]) {
                if (next_city == parent) continue;
                changes += cost + self(self, next_city, city);
            }

            return changes;
        };

        return dfs(dfs, 0, -1);
    }
};
