#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<ll> a(n);
        for (ll &x : a)
            cin >> x;

        int m = n - 4;
        vector<ll> val(m);

        for (int i = 0; i < m; ++i) {
            val[i] = a[i] + a[i + 2] - a[i + 4];
        }

        unordered_map<ll, ll> freq;
        ll ans = 0;

        // Count all pairs with equal audience-love values.
        for (ll x : val) {
            ans += freq[x];
            ++freq[x];
        }

        // Remove pairs whose triads share a key.
        // {i, i+2, i+4} overlaps another triad exactly
        // when the starting positions differ by 2 or 4.
        for (int i = 0; i < m; ++i) {
            if (i + 2 < m && val[i] == val[i + 2])
                --ans;

            if (i + 4 < m && val[i] == val[i + 4])
                --ans;
        }

        cout << ans << '\n';
    }

    return 0;
}
