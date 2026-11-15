// https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long even = 1, odd = 0, res = 0;
        int parity = 0;

        for (int x : arr) {
            parity ^= x & 1;
            if (parity) {
                res += even;
                odd++;
            } else {
                res += odd;
                even++;
            }
        }

        return res % MOD;
    }
};
