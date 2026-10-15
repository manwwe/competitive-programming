// https://codeforces.com/problemset/problem/2258/B1

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define all(x) (x).begin(), (x).end()

void solve() {
    int n, m;
    cin >> n >> m;
    vi cnt(m + 1, 0);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    int best_cnt = 0;
    int prefix = 0;
    for (int len = 1; len <= m; len++) {
        prefix += cnt[len];
        int curr = cnt[len] + (n - prefix);
        if (2 * len <= m)
            curr += cnt[2 * len];
        best_cnt = max(best_cnt, curr);
    }
    cout << best_cnt << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
