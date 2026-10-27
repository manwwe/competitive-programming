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
    int n;
    cin >> n;
    int min_val = INT_MAX;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        min_val = min(min_val, x);
    }
    int res = 0;
    if (min_val < n) res = n;
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
