// https://leetcode.com/problems/valid-parentheses/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isValid(string s) {
        stack<char> brackets;

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                brackets.push(c);
            } else {
                if (brackets.empty()) {
                    return false;
                }

                char top = brackets.top();

                if ((c == ')' && top != '(') || (c == ']' && top != '[') ||
                    (c == '}' && top != '{')) {
                    return false;
                }

                brackets.pop();
            }
        }

        return brackets.empty();
    }
};
