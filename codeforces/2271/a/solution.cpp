// https://codeforces.com/contest/2271/problem/A

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
vector<int> vi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int x, y;
        cin >> x >> y;

        if (y > x + 1 || y < -x - 1) {
            cout << -1 << '\n';
        } else if ((x + y) % 2 == 0) {
            cout << x << '\n';
        } else {
            cout << x + 1 << '\n';
        }
    }

    return 0;
}
