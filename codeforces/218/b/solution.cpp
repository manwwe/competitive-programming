#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define all(x) (x).begin(), (x).end()

void solve() {
    int n, m;
    cin >> n >> m;
    priority_queue<int> max_heap;
    priority_queue<int, vi, greater<int>> min_heap;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        max_heap.push(a);
        min_heap.push(a);
    }
    ll max_profit = 0;
    ll min_profit = 0;
    for (int i = 0; i < n; i++) {
        int top = max_heap.top();
        max_heap.pop();
        max_profit += top;
        if (top - 1 > 0) max_heap.push(top - 1);
    }
    for (int i = 0; i < n; i++) {
        int low = min_heap.top();
        min_heap.pop();
        min_profit += low;
        if (low - 1 > 0) min_heap.push(low - 1);
    }
    cout << max_profit << ' ' << min_profit << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
