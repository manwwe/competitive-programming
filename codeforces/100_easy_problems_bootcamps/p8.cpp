#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ar array


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, L, a;
    cin >> n >> L >> a;

    int breaks = 0;
    int current_time = 0;

    while (n--) {
        int t, l;
        cin >> t >> l;

        breaks += (t - current_time) / a;
        current_time = t + l;
    }

    breaks += (L - current_time) / a;
    cout << breaks << "\n";

    return 0;
}
