// https://leetcode.com/problems/domino-and-tromino-tiling/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTilings(int n) {
        const int mod = 1e9 + 7;

        if (n <= 2) return n;

        long long a = 1, b = 1, c = 2;

        for (int i = 3; i <= n; i++) {
            long long curr = (2 * c + a) % mod;
            a = b;
            b = c;
            c = curr;
        }

        return c;
    }
};
