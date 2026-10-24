#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> groups;

        for (string& word : strs) {
            int freq[26] = {0};

            for (char c : word) freq[c - 'a']++;

            string key = "";

            for (int i = 0; i < 26; i++) {
                key += to_string(freq[i]) + "#";
            }

            groups[key].push_back(word);
        }

        vector<vector<string>> result;

        for (auto& [key, words] : groups) {
            result.push_back(words);
        }

        return result;
    }
};
