// https://leetcode.com/problems/string-compression

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int compress(vector<char> &chars) {
        int n = chars.size();
        int read = 0;
        int write = 0;

        while (read < n) {
            char current_char = chars[read];
            int group_start = read;

            // Find the end of the current group
            while (read < n && chars[read] == current_char) {
                read++;
            }

            int count = read - group_start;

            // Write the character
            chars[write] = current_char;
            write++;

            // Write the count if there is more than one character
            if (count > 1) {
                string count_str = to_string(count);

                for (char digit : count_str) {
                    chars[write] = digit;
                    write++;
                }
            }
        }

        return write;
    }
};
