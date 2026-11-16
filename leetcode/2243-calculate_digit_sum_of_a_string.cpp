// https://leetcode.com/problems/calculate-digit-sum-of-a-string/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string digitSum(string s, int k) {
        while ((int)s.size() > k) {
            string next;

            for (int i = 0; i < (int)s.size(); i += k) {
                int sum = 0;
                for (int j = i; j < min(i + k, (int)s.size()); j++)
                    sum += s[j] - '0';
                next += to_string(sum);
            }

            s = next;
        }

        return s;
    }
};
