#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int LIM = 201000;
int spf[LIM];
vi prime_powers;
int sz;
vi tree_max;

void build_sieve() {
    for (int i = 2; i < LIM; i++) {
        if (spf[i] == 0) {
            for (int j = i; j < LIM; j += i) {
                if (spf[j] == 0)
                    spf[j] = i;
            }
        }
    }
    for (int i = 2; i < LIM; i++) {
        if (spf[i] == i) {
            ll pw = i;
            while (pw < LIM) {
                prime_powers.pb((int)pw);
                pw *= i;
            }
        }
    }
    sort(all(prime_powers));
}

void range_chmax(int l, int r, int v) {
    if (l > r)
        return;
    int lo = l - 1 + sz;
    int hi = r + sz;
    while (lo < hi) {
        if (lo & 1) {
            tree_max[lo] = max(tree_max[lo], v);
            lo++;
        }
        if (hi & 1) {
            hi--;
            tree_max[hi] = max(tree_max[hi], v);
        }
        lo >>= 1;
        hi >>= 1;
    }
}

int point_query(int p) {
    int idx = p - 1 + sz;
    int res = 0;
    while (idx >= 1) {
        res = max(res, tree_max[idx]);
        idx >>= 1;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    sz = n;
    vi a(n + 1);
    vector<vi> occ(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        int x = a[i];
        while (x > 1) {
            int p = spf[x];
            int e = 0;
            while (x % p == 0) {
                x /= p;
                e++;
            }
            int pw = 1;
            for (int k = 1; k <= e; k++) {
                pw *= p;
                occ[pw].pb(i);
            }
        }
    }
    tree_max.assign(2 * n + 2, 0);
    vi good_vals;
    vi empty_list;
    for (int q : prime_powers) {
        const vi &pos = (q <= n) ? occ[q] : empty_list;
        int m = pos.size();
        bool found = false;
        int prev = 0;
        for (int idx = 0; idx <= m; idx++) {
            int p = (idx < m) ? pos[idx] : n + 1;
            int left = prev + 1;
            int right = p - 1;
            if (left <= right && point_query(left) <= right)
                found = true;
            prev = p;
        }
        if (found)
            good_vals.pb(q);
        if (q > n)
            break;
        prev = 0;
        for (int idx = 0; idx <= m; idx++) {
            int p = (idx < m) ? pos[idx] : n + 1;
            range_chmax(prev + 1, min(p, n), p);
            prev = p;
        }
    }
    cout << good_vals.size() << '\n';
    for (int v : good_vals)
        cout << v << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    build_sieve();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
