// https://leetcode.com/problems/search-suggestions-system/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());

        vector<vector<string>> res;
        string prefix;
        int n = products.size();
        int start = 0;

        for (char c : searchWord) {
            prefix += c;
            start = lower_bound(products.begin() + start, products.end(), prefix) - products.begin();

            vector<string> suggestions;

            for (int i = start; i < min(start + 3, n); i++) {
                if (products[i].compare(0, prefix.size(), prefix) != 0) break;
                suggestions.push_back(products[i]);
            }

            res.push_back(suggestions);
        }

        return res;
    }
};
