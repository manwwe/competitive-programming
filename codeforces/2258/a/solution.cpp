#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define ar array
#define vll vector<long long>

void solve() {
    int n;
    cin >> n;
    vll arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll max_gcd = __gcd(arr[0], arr[n - 1]);
    cout << max_gcd << '\n';
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
