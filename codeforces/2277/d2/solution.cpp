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
const int SMALL_P = 13;
const ll SMALL_LIM = 1LL << SMALL_P;
const int W = 4200;
const int MAX_P = 61;

ll small_pre[(1 << SMALL_P) + 5];
ll cum_blocks[MAX_P + 2];
vll tail_pre[MAX_P + 2];

ll calc_f(ll n) {
    if (n == 0) return 0;
    if (n == 2) return 3;
    int p = 63 - __builtin_clzll(n + 1);
    if (n == (1LL << p) - 1) return p;
    ll m = n - (1LL << p) + 2;
    ll over = (1LL << p) + 1 - m;
    return p + 1 + min(calc_f(m), over);
}

ll prefix_sum(ll n) {
    if (n < SMALL_LIM) return small_pre[n];
    int p = 63 - __builtin_clzll(n + 1);
    ll res = cum_blocks[p] % MOD;
    res = (res + p) % MOD;
    ll m_top = n - (1LL << p) + 2;
    if (m_top < 2) return res;
    ll cnt = (m_top - 1) % MOD;
    res = (res + cnt * (p + 1)) % MOD;
    ll head_end = (1LL << p) - W;
    ll mid_part = 0;
    if (m_top <= head_end) {
        mid_part = (prefix_sum(m_top) - 1 + MOD) % MOD;
    } else {
        mid_part = (prefix_sum(head_end) - 1 + MOD) % MOD;
        ll u_lo = (1LL << p) + 1 - m_top;
        ll tail_part = (tail_pre[p][W] - tail_pre[p][u_lo - 1] + MOD) % MOD;
        mid_part = (mid_part + tail_part) % MOD;
    }
    res = (res + mid_part) % MOD;
    return res;
}

void precompute() {
    ll run = 0;
    for (ll i = 0; i < SMALL_LIM; i++) {
        run = (run + calc_f(i)) % MOD;
        small_pre[i] = run;
    }
    cum_blocks[SMALL_P] = small_pre[SMALL_LIM - 2];
    for (int p = SMALL_P; p < MAX_P; p++) {
        tail_pre[p].assign(W + 1, 0);
        for (int u = 1; u <= W; u++) {
            ll m = (1LL << p) + 1 - u;
            ll g = min(calc_f(m), (ll)u);
            tail_pre[p][u] = (tail_pre[p][u - 1] + g) % MOD;
        }
        ll block_sum = p;
        ll cnt = ((1LL << p) - 1) % MOD;
        block_sum = (block_sum + cnt * (p + 1)) % MOD;
        ll head_end = (1LL << p) - W;
        ll mid_part = (prefix_sum(head_end) - 1 + MOD) % MOD;
        mid_part = (mid_part + tail_pre[p][W]) % MOD;
        block_sum = (block_sum + mid_part) % MOD;
        cum_blocks[p + 1] = (cum_blocks[p] + block_sum) % MOD;
    }
}

void solve() {
    ll l, r;
    cin >> l >> r;
    ll res = prefix_sum(r);
    if (l > 0) res = (res - prefix_sum(l - 1) + MOD) % MOD;
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    precompute();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
