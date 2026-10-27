#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define all(x) (x).begin(), (x).end()

const ll MOD = 998244353;
ll coin_val[63];
ll coin_cost[63];

ll calc_f(ll n) {
    if (n == 0) return 0;
    ll need = n / 2;
    if (need == 0) return 1;
    ll best_total = LLONG_MAX;
    ll acc = 0;
    ll rem = need;
    while (rem > 0) {
        int fin_p = 1;
        while (coin_val[fin_p] < rem) fin_p++;
        best_total = min(best_total, acc + coin_cost[fin_p]);
        int big_p = 1;
        while (coin_val[big_p + 1] <= rem) big_p++;
        acc += coin_cost[big_p];
        rem -= coin_val[big_p];
    }
    best_total = min(best_total, acc);
    return best_total - n;
}

void solve() {
    ll l, r;
    cin >> l >> r;
    ll res = 0;
    for (ll n = l; n <= r; n++) {
        res = (res + calc_f(n) % MOD) % MOD;
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int p = 1; p <= 61; p++) {
        coin_val[p] = (1LL << p) - 1;
        coin_cost[p] = (1LL << (p + 1)) + p;
    }
    coin_val[62] = LLONG_MAX;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
