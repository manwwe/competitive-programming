#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ar array

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int count = 1;

    for (size_t i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1])
            count++;
        else
            count = 1;

        if (count >= 7) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";

    return 0;
}
