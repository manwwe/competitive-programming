// https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minInsertions(string s) {
        int close = 0;
        int insertions = 0;

        for (char c : s) {
            if (c == '(') {
                if (close % 2 == 1) {
                    insertions++;
                    close--;
                }

                close += 2;
            } else {
                close--;

                if (close < 0) {
                    insertions++;
                    close = 1;
                }
            }
        }

        return insertions + close;
    }
};
