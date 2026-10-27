// https://leetcode.com/problems/daily-temperatures/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int j = st.top();
                st.pop();
                res[j] = i - j;
            }

            st.push(i);
        }

        return res;
    }
};
