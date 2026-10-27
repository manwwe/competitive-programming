#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        auto dfs = [&](auto&& self, int i, int j) -> void {
            if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != 0) return;

            grid[i][j] = 1;

            self(self, i + 1, j);
            self(self, i - 1, j);
            self(self, i, j + 1);
            self(self, i, j - 1);
        };

        for (int i = 0; i < n; i++) {
            dfs(dfs, i, 0);
            dfs(dfs, i, m - 1);
        }

        for (int j = 0; j < m; j++) {
            dfs(dfs, 0, j);
            dfs(dfs, n - 1, j);
        }

        int closed_islands = 0;

        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (grid[i][j] != 0) continue;
                closed_islands++;
                dfs(dfs, i, j);
            }
        }

        return closed_islands;
    }
};
