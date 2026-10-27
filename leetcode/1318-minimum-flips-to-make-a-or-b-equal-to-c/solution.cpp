// https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int min_flips = 0;

        while (a || b || c) {
            int bit_a = a & 1;
            int bit_b = b & 1;
            int bit_c = c & 1;

            if (bit_c == 0) min_flips += bit_a + bit_b;
            else if (bit_a == 0 && bit_b == 0) min_flips++;

            a >>= 1;
            b >>= 1;
            c >>= 1;
        }

        return min_flips;
    }
};
