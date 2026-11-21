// https://leetcode.com/problems/find-subtree-sizes-after-changes/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; i++)
            children[parent[i]].push_back(i);

        vector<int> newParent(parent), prev(n), order, last(26, -1);
        vector<pair<int, bool>> st = {{0, false}};

        while (!st.empty()) {
            auto [u, leaving] = st.back();
            st.pop_back();
            int c = s[u] - 'a';

            if (leaving) {
                last[c] = prev[u];
                continue;
            }

            order.push_back(u);
            if (u != 0 && last[c] != -1) newParent[u] = last[c];
            prev[u] = last[c];
            last[c] = u;

            st.push_back({u, true});
            for (int v : children[u])
                st.push_back({v, false});
        }

        vector<int> size(n, 1);
        for (int i = n - 1; i > 0; i--)
            size[newParent[order[i]]] += size[order[i]];

        return size;
    }
};
