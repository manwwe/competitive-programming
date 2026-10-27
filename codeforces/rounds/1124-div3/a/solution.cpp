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
        long long x0, y0, r;
        cin >> x0 >> y0 >> r;

        cout << x0 + r << " " << y0 << '\n';
    }

    return 0;
}
