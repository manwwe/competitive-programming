// https://leetcode.com/problems/evaluate-division/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> calcEquation(
        vector<vector<string>>& equations,
        vector<double>& values,
        vector<vector<string>>& queries
    ) {
        unordered_map<string, vector<pair<string, double>>> graph;

        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0], b = equations[i][1];
            double value = values[i];

            graph[a].push_back({b, value});
            graph[b].push_back({a, 1.0 / value});
        }

        auto dfs = [&](auto&& self, string curr, string target,
                       unordered_set<string>& visited) -> double {
            if (curr == target) return 1.0;

            visited.insert(curr);

            for (auto& [next, weight] : graph[curr]) {
                if (visited.count(next)) continue;

                double res = self(self, next, target, visited);
                if (res != -1.0) return weight * res;
            }

            return -1.0;
        };

        vector<double> res;

        for (auto& query : queries) {
            string a = query[0], b = query[1];

            if (!graph.count(a) || !graph.count(b)) {
                res.push_back(-1.0);
                continue;
            }

            unordered_set<string> visited;
            res.push_back(dfs(dfs, a, b, visited));
        }

        return res;
    }
};
