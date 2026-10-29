// https://leetcode.com/problems/palindromic-path-queries-in-a-tree/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> parent(n, -1), depth(n), sz(n, 1);
        vector<int> heavy(n, -1), head(n), pos(n);
        vector<int> order = {0};

        for (int i = 0; i < (int)order.size(); i++) {
            int u = order[i];
            for (int v : adj[u]) {
                if (v == parent[u]) continue;
                parent[v] = u;
                depth[v] = depth[u] + 1;
                order.push_back(v);
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            int u = order[i];
            if (parent[u] == -1) continue;
            int p = parent[u];
            sz[p] += sz[u];
            if (heavy[p] == -1 || sz[u] > sz[heavy[p]]) heavy[p] = u;
        }

        int timer = 0;
        for (int u : order) {
            if (parent[u] != -1 && heavy[parent[u]] == u) continue;
            for (int v = u; v != -1; v = heavy[v]) {
                head[v] = u;
                pos[v] = timer++;
            }
        }

        vector<int> bit(n + 1);

        auto update = [&](int i, int mask) {
            for (++i; i <= n; i += i & -i) bit[i] ^= mask;
        };

        auto prefix = [&](int i) {
            int mask = 0;
            for (++i; i > 0; i -= i & -i) mask ^= bit[i];
            return mask;
        };

        auto range_xor = [&](int l, int r) {
            return prefix(r) ^ prefix(l - 1);
        };

        for (int i = 0; i < n; i++) {
            update(pos[i], 1 << (s[i] - 'a'));
        }

        auto path_xor = [&](int u, int v) {
            int mask = 0;
            while (head[u] != head[v]) {
                if (depth[head[u]] < depth[head[v]]) swap(u, v);
                mask ^= range_xor(pos[head[u]], pos[u]);
                u = parent[head[u]];
            }
            if (depth[u] > depth[v]) swap(u, v);
            mask ^= range_xor(pos[u], pos[v]);
            return mask;
        };

        vector<bool> res;

        for (auto& q : queries) {
            stringstream ss(q);
            string op;
            int u;
            ss >> op >> u;

            if (op == "update") {
                char c;
                ss >> c;
                int mask = (1 << (s[u] - 'a')) ^ (1 << (c - 'a'));
                update(pos[u], mask);
                s[u] = c;
            } else {
                int v;
                ss >> v;
                int mask = path_xor(u, v);
                res.push_back((mask & (mask - 1)) == 0);
            }
        }

        return res;
    }
};
