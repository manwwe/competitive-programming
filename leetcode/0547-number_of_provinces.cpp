// https://leetcode.com/problems/number-of-provinces/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);

        auto dfs = [&](auto&& self, int city) -> void {
            visited[city] = true;

            for (int i = 0; i < n; i++) {
                if (isConnected[city][i] && !visited[i]) self(self, i);
            }
        };

        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            dfs(dfs, i);
            provinces++;
        }

        return provinces;
    }
};
