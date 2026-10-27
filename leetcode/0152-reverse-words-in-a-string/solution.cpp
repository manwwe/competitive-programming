// https://leetcode.com/problems/reverse-words-in-a-string

#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        int n = s.size();
        int read = 0;
        int write = 0;

        while (read < n) {
            while (read < n && s[read] == ' ') {
                read++;
            }

            if (read == n) {
                break;
            }

            if (write > 0) {
                s[write++] = ' ';
            }

            int word_start = write;

            while (read < n && s[read] != ' ') {
                s[write++] = s[read++];
            }

            reverse(s.begin() + word_start, s.begin() + write);
        }

        s.resize(write);
        return s;
    }
};
