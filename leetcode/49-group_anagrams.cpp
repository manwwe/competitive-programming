#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        vector<vector<string>> result;

        for (const string& s : strs) {
            int f[26] = {0};

            for (char c : s) f[c - 'a']++;

            string key;
            for (int x : f) key += to_string(x) + "#";
            groups[key].push_back(s);
        }

        for (const auto& i : groups) {
            result.push_back(i.second);
        }

        return result;
    }
};
