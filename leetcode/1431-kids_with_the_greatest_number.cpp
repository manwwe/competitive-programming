// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {
        int max_candies = *max_element(candies.begin(), candies.end());
        vector<bool> ans;

        for (int candy : candies) {
            if (candy + extraCandies >= max_candies) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};
