#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define ar array


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >>t;

    int x, y, z;
    int sx = 0;
    int sy = 0;
    int sz = 0;

    while (t--) {
        cin >> x >> y >> z;

        sx += x;
        sy += y;
        sz += z;

    };

    string result = (sx == 0 && sy == 0 && sz == 0) ? "YES":"NO";

    cout << result << "\n";


    return 0;
}
