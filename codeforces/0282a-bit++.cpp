#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int x = 0;

    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;
        if (operation[1] == '+') {
            x++;
        } else {
            x--;
        }
    }
    cout << x;
    return 0;
}
