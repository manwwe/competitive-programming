#include <bits/stdc++.h>
using namespace std;

class Solution {
    static constexpr long long mod = 1e9 + 7;

    struct Node {
        long long sum = 0, sq = 0, lazy = 0;
    };

    vector<Node> tree;

    void apply(int p, int l, int r, long long val) {
        auto &node = tree[p];
        long long len = r - l + 1;
        node.sq =
            (node.sq + 2 * val * node.sum % mod + val * val % mod * len) % mod;
        node.sum = (node.sum + val * len) % mod;
        node.lazy = (node.lazy + val) % mod;
    }

    void push(int p, int l, int r) {
        if (!tree[p].lazy || l == r)
            return;
        int mid = (l + r) / 2;
        apply(p * 2, l, mid, tree[p].lazy);
        apply(p * 2 + 1, mid + 1, r, tree[p].lazy);
        tree[p].lazy = 0;
    }

    void update(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            apply(p, l, r, 1);
            return;
        }

        push(p, l, r);
        int mid = (l + r) / 2;

        if (ql <= mid)
            update(p * 2, l, mid, ql, qr);
        if (qr > mid)
            update(p * 2 + 1, mid + 1, r, ql, qr);

        tree[p].sum = (tree[p * 2].sum + tree[p * 2 + 1].sum) % mod;
        tree[p].sq = (tree[p * 2].sq + tree[p * 2 + 1].sq) % mod;
    }

  public:
    int sumCounts(vector<int> &nums) {
        int n = nums.size();
        tree.resize(4 * n);

        vector<int> last(100001, -1);
        long long res = 0;

        for (int i = 0; i < n; i++) {
            update(1, 0, n - 1, last[nums[i]] + 1, i);
            res = (res + tree[1].sq) % mod;
            last[nums[i]] = i;
        }

        return res;
    }
};
