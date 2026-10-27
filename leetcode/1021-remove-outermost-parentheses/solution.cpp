// https://leetcode.com/problems/remove-outermost-parentheses/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string removeOuterParentheses(string s) {
        int counter = 0;
        string result = "";

        for (char c : s) {
            if (c == '(') {
                if (counter > 0) {
                    result += c;
                }
                counter++;
            } else {
                counter--;
                if (counter > 0) {
                    result += c;
                }
            }
        }

        return result;
    }
};
