// https://leetcode.com/contest/biweekly-contest-193/problems/minimize-inversions-in-a-prefix-tree/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct Node {
        int child[10];
        int id;

        Node() : id(-1) { fill(child, child + 10, -1); }
    };

    vector<Node> trie;
    vector<int> pos;
    long long ans;

    vector<int> dfs(int u) {
        vector<vector<int>> groups;

        for (int c = 0; c < 10; c++) {
            int v = trie[u].child[c];

            if (v != -1) {
                groups.push_back(dfs(v));
            }
        }

        int m = groups.size();

        vector<vector<long long>> cost(m, vector<long long>(m, 0));

        // Count inversions between child subtrees.
        vector<pair<int, int>> elements;

        for (int i = 0; i < m; i++) {
            for (int x : groups[i]) {
                elements.push_back({x, i});
            }
        }

        sort(elements.begin(), elements.end());

        vector<long long> seen(m, 0);

        for (auto [x, g] : elements) {
            for (int j = 0; j < m; j++) {
                if (j != g) {
                    // x is greater than every previously
                    // seen position from group j.
                    cost[g][j] += seen[j];
                }
            }

            seen[g]++;
        }

        // Bitmask DP: optimal ordering of children.
        int total = 1 << m;
        const long long INF = LLONG_MAX / 4;

        vector<long long> dp(total, INF);
        dp[0] = 0;

        for (int mask = 0; mask < total; mask++) {
            if (dp[mask] == INF)
                continue;

            for (int j = 0; j < m; j++) {
                if (mask & (1 << j))
                    continue;

                long long add = 0;

                for (int i = 0; i < m; i++) {
                    if (mask & (1 << i)) {
                        add += cost[i][j];
                    }
                }

                int nextMask = mask | (1 << j);

                dp[nextMask] = min(dp[nextMask], dp[mask] + add);
            }
        }

        ans += dp[total - 1];

        // A marked node is visited before its children.
        if (trie[u].id != -1) {
            int p = pos[trie[u].id];

            for (auto [x, g] : elements) {
                if (p > x) {
                    ans++;
                }
            }
        }

        // Merge sorted positions for the parent.
        vector<int> result;
        result.reserve(elements.size() + (trie[u].id != -1));

        if (trie[u].id != -1) {
            result.push_back(pos[trie[u].id]);
        }

        for (auto [x, g] : elements) {
            result.push_back(x);
        }

        sort(result.begin(), result.end());

        return result;
    }

  public:
    long long minInversions(vector<string> &words, vector<int> &target) {
        int n = words.size();

        pos.resize(n);

        for (int i = 0; i < n; i++) {
            pos[target[i]] = i;
        }

        trie.clear();
        trie.emplace_back();

        for (int i = 0; i < n; i++) {
            int u = 0;

            for (char c : words[i]) {
                int x = c - 'a';

                if (trie[u].child[x] == -1) {
                    int v = trie.size();
                    trie[u].child[x] = v;
                    trie.emplace_back();
                }

                u = trie[u].child[x];
            }

            trie[u].id = i;
        }

        ans = 0;
        dfs(0);

        return ans;
    }
};
