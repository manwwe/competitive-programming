#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ar array


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        int n = s.size();

        if (n <= 10) cout << s << "\n";
        else cout << s.front() << n - 2 << s.back() << "\n";
    }

    return 0;
}
