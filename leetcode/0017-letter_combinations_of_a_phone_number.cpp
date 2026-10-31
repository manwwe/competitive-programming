// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> res;
        string curr;
        vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"
        };

        auto dfs = [&](auto&& dfs, int i) -> void {
            if (i == digits.size()) {
                res.push_back(curr);
                return;
            }

            for (char c : mapping[digits[i] - '0']) {
                curr.push_back(c);
                dfs(dfs, i + 1);
                curr.pop_back();
            }
        };

        dfs(dfs, 0);
        return res;
    }
};
