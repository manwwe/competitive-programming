#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define all(x) (x).begin(), (x).end()

vll insert_sorted(const vll& base, ll val) {
    size_t pos = lower_bound(base.begin(), base.end(), val, greater<ll>()) - base.begin();
    vll res;
    res.reserve(base.size() + 1);
    res.insert(res.end(), base.begin(), base.begin() + pos);
    res.pb(val);
    res.insert(res.end(), base.begin() + pos, base.end());
    return res;
}

void process_block(const vector<pair<int, ll>>& blk, vll& res) {
    bool has_fixed = false;
    for (auto& p : blk) if (p.first != 3) has_fixed = true;
    if (!has_fixed) {
        res.pb(blk[0].second);
        return;
    }
    vll f;
    vll gap;
    vi col;
    ll pending = 0;
    for (auto& p : blk) {
        int type = p.first;
        ll len = p.second;
        if (type == 3) {
            pending = len;
        } else {
            if (f.empty()) {
                f.pb(len + pending);
                col.pb(type);
            } else if (pending > 0 && col.back() == type) {
                f.back() += pending + len;
            } else {
                gap.pb(pending);
                f.pb(len);
                col.pb(type);
            }
            pending = 0;
        }
    }
    if (pending > 0) f.back() += pending;
    int k = f.size();
    vll prev_dp[2];
    vll cur_dp[2];
    for (int i = 0; i < k; i++) {
        ll left_gap = 0;
        ll right_gap = 0;
        if (i > 0) left_gap = gap[i - 1];
        if (i + 1 < k) right_gap = gap[i];
        for (int d = 0; d < 2; d++) {
            vll best;
            bool has_best = false;
            for (int e = 0; e < 2; e++) {
                ll s = f[i];
                if (e == 1) s += left_gap;
                if (d == 0) s += right_gap;
                vll cand = insert_sorted(prev_dp[e], s);
                if (!has_best || cand > best) {
                    best = move(cand);
                    has_best = true;
                }
            }
            cur_dp[d] = move(best);
        }
        swap(prev_dp[0], cur_dp[0]);
        swap(prev_dp[1], cur_dp[1]);
    }
    vll& final_set = prev_dp[0] > prev_dp[1] ? prev_dp[0] : prev_dp[1];
    for (ll x : final_set) res.pb(x);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<ll, 3>> ev;
    for (int i = 0; i < n; i++) {
        ll l, r;
        cin >> l >> r;
        ev.pb({l, 1, 0});
        ev.pb({r + 1, -1, 0});
    }
    for (int i = 0; i < m; i++) {
        ll l, r;
        cin >> l >> r;
        ev.pb({l, 0, 1});
        ev.pb({r + 1, 0, -1});
    }
    sort(all(ev));
    vll res;
    vector<pair<int, ll>> blk;
    ll cur1 = 0;
    ll cur2 = 0;
    size_t i = 0;
    while (i < ev.size()) {
        ll pos = ev[i][0];
        size_t j = i;
        while (j < ev.size() && ev[j][0] == pos) {
            cur1 += ev[j][1];
            cur2 += ev[j][2];
            j++;
        }
        int type = (cur1 > 0 ? 1 : 0) + (cur2 > 0 ? 2 : 0);
        if (type == 0) {
            if (!blk.empty()) {
                process_block(blk, res);
                blk.clear();
            }
        } else {
            blk.pb({type, ev[j][0] - pos});
        }
        i = j;
    }
    if (!blk.empty()) process_block(blk, res);
    sort(all(res), greater<ll>());
    cout << res.size() << '\n';
    for (size_t idx = 0; idx < res.size(); idx++) {
        if (idx) cout << ' ';
        cout << res[idx];
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
