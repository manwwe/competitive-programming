// https://leetcode.com/problems/shortest-path-with-at-most-k-consecutive-identical-characters/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : edges) adj[e[0]].push_back({e[1], e[2]});

        const long long inf = LLONG_MAX;
        vector<vector<long long>> dist(n, vector<long long>(k + 1, inf));

        using State = tuple<long long, int, int>;
        priority_queue<State, vector<State>, greater<State>> pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [cost, u, cnt] = pq.top();
            pq.pop();

            if (cost != dist[u][cnt]) continue;
            if (u == n - 1) return cost;

            for (auto [v, w] : adj[u]) {
                int next_cnt = labels[u] == labels[v] ? cnt + 1 : 1;
                if (next_cnt > k) continue;

                long long next_cost = cost + w;
                if (next_cost >= dist[v][next_cnt]) continue;

                dist[v][next_cnt] = next_cost;
                pq.push({next_cost, v, next_cnt});
            }
        }

        return -1;
    }
};
