// https://leetcode.com/problems/stone-removal-game/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canAliceWin(int n) {
        bool aliceTurn = true;

        for (int take = 10; take > 0 && n >= take; take--) {
            n -= take;
            aliceTurn = !aliceTurn;
        }

        return !aliceTurn;
    }
};
