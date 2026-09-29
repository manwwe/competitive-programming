// https://leetcode.com/problems/merge-strings-alternately
#include <cstddef>
#include <string>

using namespace std;

class Solution {
public:
  string mergeAlternately(string word1, string word2) {
    size_t w1size = word1.size();
    size_t w2size = word2.size();
    size_t maxSize = max(w1size, w2size);
    string result;

    for (size_t i = 0; i < maxSize; i++) {
      if (i < w1size) {
        result += word1[i];
      }

      if (i < w2size) {
        result += word2[i];
      }
    }
    return result;
  }
};
