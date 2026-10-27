// https://leetcode.com/problems/successful-pairs-of-spells-and-potions/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());

        int n = potions.size();
        vector<int> res;

        for (int spell : spells) {
            int left = 0, right = n;

            while (left < right) {
                int mid = left + (right - left) / 2;

                if (1LL * spell * potions[mid] >= success) right = mid;
                else left = mid + 1;
            }

            res.push_back(n - left);
        }

        return res;
    }
};
