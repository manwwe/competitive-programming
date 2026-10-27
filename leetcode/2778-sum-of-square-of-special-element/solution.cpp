// https://leetcode.com/problems/sum-of-squares-of-special-elements/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int sumOfSquares(vector<int> &nums) {

        int n = nums.size();
        int result = 0;

        for (int i = 1; i < n + 1; i++) {
            if (n % i == 0) {
                result += nums[i - 1] * nums[i - 1];
            }
        }

        return result;
    }
};
