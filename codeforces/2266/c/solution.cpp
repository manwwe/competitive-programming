// https://codeforces.com/problemset/problem/2266/C

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        int left_ones = 0;
        int right_zeros = 0;

        for (char c : s) {
            if (c == '0') {
                right_zeros++;
            }
        }

        int min_changes = n;

        for (int i = 0; i <= n; i++) {
            bool valid_split = (s[0] == '0' || i == 0);

            if (valid_split) {
                min_changes = min(min_changes, left_ones + right_zeros);
            }

            if (i < n) {
                if (s[i] == '1') {
                    left_ones++;
                } else {
                    right_zeros--;
                }
            }
        }

        cout << min_changes << '\n';
    }

    return 0;
}
