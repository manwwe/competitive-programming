// https://leetcode.com/problems/decode-string

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> st;

        int k = 0;
        string result = "";

        for (char c : s) {
            if (isdigit(c)) {
                k = k * 10 + (c - '0');
            } else if (c == '[') {
                counts.push(k);
                st.push(result);

                k = 0;
                result = "";
            } else if (c == ']') {
                int repeat = counts.top();
                counts.pop();

                string previous = st.top();
                st.pop();

                for (int i = 0; i < repeat; i++) {
                    previous += result;
                }
                result = previous;
            } else {
                result += c;
            }
        }
        return result;
    }
};
