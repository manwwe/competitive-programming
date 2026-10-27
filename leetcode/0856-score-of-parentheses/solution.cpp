// https://leetcode.com/problems/score-of-parentheses/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int score = 0;

        for (char c : s) {
            if (c == '(') {
                st.push(score);
                score = 0;
            } else {
                int previous = st.top();
                st.pop();

                if (score == 0) {
                    score = previous + 1;
                } else {
                    score = previous + 2 * score;
                }
            }
        }
        return score;
    }
};
