// https://leetcode.com/problems/is-subsequence/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isSubsequence(string s, string t) {

        int s_index = 0;
        int t_size = t.size();
        int s_size = s.size();

        for (int i = 0; i < t_size && s_index < s_size; i++) {
            if (s[s_index] == t[i]) {
                s_index++;
            }
        }
        return s_index == s_size;
    }
};
