#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ar array
#define vll vector<long long>

void solve()
{
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vll row_min(m + 1, LLONG_MAX);
    for (int i = 0; i < n; i++)
    {
        int r;
        ll c;
        cin >> r >> c;
        row_min[r] = min(row_min[r], c);
    }
    ll total = 0;
    for (int i = 1; i <= m; i++)
        total += row_min[i];
    ll max_eaten = min(total, k);
    cout << max_eaten << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
