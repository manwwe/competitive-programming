#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ar array


void solve()
{
    int n;
    cin >> n;
    ll prefix_sum = 0;
    ll best_h = LLONG_MAX;
    for (int i = 1; i <= n; i++)
    {
        ll val;
        cin >> val;
        prefix_sum += val;
        best_h = min(best_h, prefix_sum / i);
        cout << best_h << " \n"[i == n];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
