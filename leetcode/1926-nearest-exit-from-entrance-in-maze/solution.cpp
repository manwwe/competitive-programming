// https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        int dirs[5] = {0, 1, 0, -1, 0};

        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';

        int steps = 0;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                auto [r, c] = q.front();
                q.pop();

                if (steps > 0 && (r == 0 || r == m - 1 || c == 0 || c == n - 1))
                    return steps;

                for (int i = 0; i < 4; i++) {
                    int nr = r + dirs[i], nc = c + dirs[i + 1];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    if (maze[nr][nc] == '+') continue;

                    maze[nr][nc] = '+';
                    q.push({nr, nc});
                }
            }

            steps++;
        }

        return -1;
    }
};
