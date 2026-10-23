#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define all(x) (x).begin(), (x).end()

vi parent_of;

int find_root(int x)
{
    while (parent_of[x] != x)
    {
        parent_of[x] = parent_of[parent_of[x]];
        x = parent_of[x];
    }
    return x;
}

void solve()
{
    int n;
    cin >> n;
    vi color(n), left_end(n), right_end(n);
    for (int i = 0; i < n; i++) cin >> color[i] >> left_end[i] >> right_end[i];
    vi order(n);
    iota(all(order), 0);
    sort(all(order), [&](int a, int b) {
        return left_end[a] < left_end[b];
    });
    parent_of.assign(n, 0);
    iota(all(parent_of), 0);
    set<pii> active[2];
    for (int idx = 0; idx < n; idx++)
    {
        int i = order[idx];
        int c = color[i];
        int other = 1 - c;
        while (!active[other].empty() && active[other].begin()->first < left_end[i]) active[other].erase(active[other].begin());
        if (!active[other].empty())
        {
            pii best = *active[other].rbegin();
            for (auto [r, id] : active[other])
            {
                int ra = find_root(i);
                int rb = find_root(id);
                if (ra != rb) parent_of[ra] = rb;
            }
            active[other].clear();
            active[other].insert(best);
        }
        active[c].insert({right_end[i], i});
    }
    int groups = 0;
    for (int i = 0; i < n; i++) if (find_root(i) == i) groups++;
    cout << groups << '\n';
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
