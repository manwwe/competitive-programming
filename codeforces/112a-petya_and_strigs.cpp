// https://codeforces.com/problemset/problem/112/A

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
vector<int> vi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string first, second;
    cin >> first >> second;

    for (size_t i = 0; i < first.size(); i++) {
        char a = tolower(first[i]);
        char b = tolower(second[i]);

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
