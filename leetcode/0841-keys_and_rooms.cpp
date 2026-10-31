// https://leetcode.com/problems/keys-and-rooms/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);

        auto dfs = [&](auto&& self, int room) -> void {
            visited[room] = true;

            for (int key : rooms[room]) {
                if (!visited[key]) self(self, key);
            }
        };

        dfs(dfs, 0);

        for (bool seen : visited) {
            if (!seen) return false;
        }

        return true;
    }
};
