#include <bits/stdc++.h>
#include <queue>

using namespace std;

typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;

    priority_queue<ll> pq;
    ll sum = 0;
    ll ans = LLONG_MIN;

    for (int i = 0; i < n; i++) {
        if ((int)pq.size() == m - 1) {
            ans = max(ans, (ll)m * a[i] - sum);
        }

        pq.push(a[i]);
        sum += a[i];

        if ((int)pq.size() > m - 1) {
            sum -= pq.top();
            pq.pop();
        }
    }

    cout << ans << "\n";
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
