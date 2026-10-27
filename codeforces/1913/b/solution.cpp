// https://codeforces.com/problemset/problem/1913/B

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define ar array

void solve() {
    string s;
    cin >> s;

    int zeros = 0, ones = 0;

    for (char c : s) {
        if (c == '0')
            zeros++;
        else
            ones++;
    }

    int n = s.size();
    int i = 0;

    for (; i < n; i++) {
        if (s[i] == '0') {
            if (ones == 0)
                break;
            ones--;
        } else {
            if (zeros == 0)
                break;
            zeros--;
        }
    }

    cout << n - i << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}
