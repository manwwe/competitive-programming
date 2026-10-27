// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxVowels(string s, int k) {
        string vowels = "aeiou";
        int current_vowels = 0;

        // Count vowels in the first window
        for (int i = 0; i < k; i++) {
            if (vowels.find(s[i]) != string::npos) {
                current_vowels++;
            }
        }

        int max_vowels = current_vowels;

        for (int right = k; right < s.size(); right++) {
            if (vowels.find(s[right - k]) != string::npos) {
                current_vowels--;
            }

            if (vowels.find(s[right]) != string::npos) {
                current_vowels++;
            }

            max_vowels = max(max_vowels, current_vowels);
        }
        return max_vowels;
    }
};
