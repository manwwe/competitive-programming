#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ar array

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> prime_count(n + 1, 0);

    for (int i = 2; i <= n; i++) {
        if (prime_count[i] != 0)
            continue;

        for (int j = i; j <= n; j += i) {
            prime_count[j]++;
        }
    }

    int res = 0;

    for (int i = 2; i <= n; i++) {
        if (prime_count[i] == 2)
            res++;
    }

    cout << res << "\n";

    return 0;
}
