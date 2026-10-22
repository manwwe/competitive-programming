#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

void solve() {
    string s;
    cin >> s;
    int cnt = 0;
    int sorted_len = 0;
    int bad_len = 0;
    bool is_valid = true;
    for (char c : s) {
        if (c == '+') cnt++;
        else if (c == '-') {
            cnt--;
            if (sorted_len > cnt) sorted_len = cnt;
            if (bad_len > cnt) bad_len = 0;
        } else if (c == '1') {
            if (bad_len != 0) is_valid = false; else sorted_len = cnt;
        } else {
            if (cnt < 2 || sorted_len == cnt) is_valid = false;
            else if (bad_len == 0) bad_len = cnt;
        }
        if (!is_valid) break;
    }
    if (is_valid) cout << "YES\n"; else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
