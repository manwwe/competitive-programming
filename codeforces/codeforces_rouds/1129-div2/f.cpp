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

void solve() {
    int n;
    cin >> n;
    vector<vi> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vll a(n + 1);
    ll total = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        total = (total + a[i]) % MOD;
    }
    vi pos(n + 1);
    vi ord(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        pos[x] = i;
        ord[i] = x;
    }
    vi par1(n + 1, 0);
    vi bfs_order;
    bfs_order.reserve(n);
    bfs_order.pb(1);
    for (int i = 0; i < (int)bfs_order.size(); i++) {
        int u = bfs_order[i];
        for (int w : adj[u]) {
            if (w == par1[u]) continue;
            par1[w] = u;
            bfs_order.pb(w);
        }
    }
    vll sub1(a);
    for (int i = n - 1; i >= 1; i--) {
        int u = bfs_order[i];
        sub1[par1[u]] = (sub1[par1[u]] + sub1[u]) % MOD;
    }
    vll val(n + 1, 0);
    vi dsu_par(n + 1);
    vi sz(n + 1, 1);
    for (int i = 0; i <= n; i++) dsu_par[i] = i;
    auto find_root = [&](int x) {
        while (dsu_par[x] != x) x = dsu_par[x];
        return x;
    };
    for (int i = n; i >= 1; i--) {
        int u = ord[i];
        for (int c : adj[u]) {
            if (pos[c] < pos[u]) continue;
            ll side = sub1[c];
            if (c == par1[u]) side = (total - sub1[u] + MOD) % MOD;
            ll add_val = (total - side + MOD) % MOD;
            int root_c = find_root(c);
            val[root_c] = (val[root_c] + add_val) % MOD;
        }
        for (int c : adj[u]) {
            if (pos[c] < pos[u]) continue;
            int ra = find_root(u);
            int rb = find_root(c);
            if (ra == rb) continue;
            if (sz[ra] > sz[rb]) swap(ra, rb);
            val[ra] = (val[ra] - val[rb] + MOD) % MOD;
            dsu_par[ra] = rb;
            sz[rb] += sz[ra];
        }
    }
    for (int r = 1; r <= n; r++) {
        ll res = total;
        int x = r;
        while (true) {
            res = (res + val[x]) % MOD;
            if (dsu_par[x] == x) break;
            x = dsu_par[x];
        }
        cout << res << ' ';
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
