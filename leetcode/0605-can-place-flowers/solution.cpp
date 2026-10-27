// https://leetcode.com/problems/can-place-flowers/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        int fb_size = flowerbed.size();

        for (int i = 0; i < fb_size; i++) {
            bool left_empty = (i == 0 || flowerbed[i - 1] == 0);
            bool right_empty = (i == fb_size - 1 || flowerbed[i + 1] == 0);

            if (flowerbed[i] == 0 && left_empty && right_empty) {
                flowerbed[i] = 1;
                n--;
            }
        }
        return n <= 0;
    }
};
