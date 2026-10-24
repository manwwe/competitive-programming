#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define all(x) (x).begin(), (x).end()

vi bfs(int src, int n, vector<vi>& adj) {
    vi dist(n + 1, -1);
    queue<int> q;
    dist[src] = 0;
    q.push(src);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int w : adj[u]) {
            if (dist[w] == -1) {
                dist[w] = dist[u] + 1;
                q.push(w);
            }
        }
    }
    return dist;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vi> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    vi dist_one = bfs(1, n, adj);
    vi dist_n = bfs(n, n, adj);
    int max_dist = dist_one[n];
    for (int i = 0; i < m; i++) {
        int v;
        cin >> v;
        if (dist_n[v] == dist_one[v] + dist_one[n]) continue;
        max_dist = max(max_dist, dist_n[v] + 1);
    }
    cout << max_dist << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
