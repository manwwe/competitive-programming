// https://codeforces.com/problemset/problem/2269/B

#include <bits/stdc++.h>
using namespace std;

int nextNumber(int x) {
    int sum = 0;

    while (x != 0) {
        int digit = x % 10;
        sum += digit * digit;
        x /= 10;
    }

    return sum;
}

void solve() {
    int n;
    cin >> n;

    map<int, long long> freq;
    long long answer = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        for (int j = 0; j < 30; j++) {
            x = nextNumber(x);
        }

        answer += freq[x];
        freq[x]++;
    }

    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
