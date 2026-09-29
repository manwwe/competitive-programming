// https://leetcode.com/problems/greatest-common-divisor-of-strings/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string gcdOfStrings(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();

    int len = gcd(n, m);
    string candidate = str1.substr(0, len);

    for (int i = 0; i < n; i++) {
      if (str1[i] != candidate[i % len]) {
        return "";
      }
    }

    for (int i = 0; i < m; i++) {
      if (str2[i] != candidate[i % len]) {
        return "";
      }
    }
    return candidate;
  }
};

// The best solution I found:
class AnotherSolution {
public:
  string gcdOfStrings(string str1, string str2) {
    return (str1 + str2 == str2 + str1)
               ? str1.substr(0, gcd(size(str1), size(str2)))
               : "";
  }
};
