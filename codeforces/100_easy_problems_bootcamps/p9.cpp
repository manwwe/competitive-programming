#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ar array

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string s;

    cin >> n >> s;

    int cnt = 0;

    for (char c : s) {
        if (c == '8') cnt++;
    }

    int res = min(n / 11, cnt);

    cout << res << "\n";

    return 0;
}
