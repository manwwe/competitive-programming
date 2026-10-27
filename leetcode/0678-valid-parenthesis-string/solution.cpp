// https://leetcode.com/problems/valid-parenthesis-string/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool checkValidString(string s) {
        int min_open = 0;
        int max_open = 0;

        for (char c : s) {
            if (c == '(') {
                min_open++;
                max_open++;
            } else if (c == ')') {
                min_open--;
                max_open--;
            } else {
                min_open--;
                max_open++;
            }

            // Even treating every '*' as '(' cannot save us.
            if (max_open < 0) {
                return false;
            }

            // We can't have fewer than 0 unmatched '('.
            min_open = max(min_open, 0);
        }

        return min_open == 0;
    }
};
