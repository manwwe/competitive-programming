#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minRotations(int n, string s) {
        auto dist = [](int a, int b) {
            int d = abs(a - b);
            return min(d, 10 - d);
        };

        int total = dist(0, s[0] - '0');

        for (int i = 1; i < n; i++) {
            total += dist(s[i - 1] - '0', s[i] - '0');
        }

        int answer = total;

        for (int k = 0; k < n; k++) {
            int previous = (k == 0) ? 0 : s[k - 1] - '0';

            int old_connection = dist(previous, s[k] - '0');
            int new_connection = dist(previous, s[n - 1] - '0');

            int new_total = total - old_connection + new_connection;

            answer = min(answer, new_total);
        }

        return answer;
    }
};
