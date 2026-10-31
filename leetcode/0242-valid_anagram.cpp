// https://leetcode.com/problems/valid-anagram/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        int freq[26] = {0};
        int n = s.size();

        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        return all_of(begin(freq), end(freq), [](int x){return x == 0;});
    }
};
