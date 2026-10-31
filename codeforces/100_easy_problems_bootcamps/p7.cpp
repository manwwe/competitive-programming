#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ar array


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    string res;
    string vowels = "aoyeui";

    for (char c : s) {
        char low = tolower(c);
        if (vowels.find(low) != string::npos) continue;
        res += '.';
        res += low;
    }

    cout << res << "\n";

    return 0;
}
