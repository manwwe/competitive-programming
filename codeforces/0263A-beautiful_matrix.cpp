// https://codeforces.com/problemset/problem/263/A

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

typedef long long ll;
vector<int> vi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int value;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> value;
            if (value == 1) {
                cout << abs(i - 2) + abs(j - 2) << "\n";
                return 0;
            }
        }
    }
    return 0;
}
