// https://codeforces.com/problemset/problem/2256/B

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

        int ans = 0;

        for (int a = 0; a <= 1; a++) {
            for (int b = 0; b <= 1; b++) {
                string cur = s;

                cur[0] = char('0' + a);
                cur[1] = char('0' + b);

                for (int i = 2; i < n; i++) {
                    cur[i] = (cur[i - 2] == '0') ? '1' : '0';
                }

                bool valid = true;

                for (int i = 0; i < n; i++) {
                    if (s[i] != '?' && s[i] != cur[i]) {
                        valid = false;
                        break;
                    }
                }

                if (valid)
                    ans++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
