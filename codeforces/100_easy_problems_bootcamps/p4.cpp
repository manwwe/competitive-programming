#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ar array


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string n, m;
    cin >> n >> m;

    for (size_t i = 0; i < n.size(); i++) {
        char a = tolower(n[i]);
        char b = tolower(m[i]);

        if (a < b) {
            cout << -1;
            return 0;
        }

        if (a > b) {
            cout << 1;
            return 0;
        }
    }

    cout << 0;

    return 0;
}
