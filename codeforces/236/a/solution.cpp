// https://codeforces.com/problemset/problem/236/A

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
vector<int> vi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string username;
    cin >> username;

    bool seen[26] = {};
    int distinct_count = 0;

    for (char c : username) {
        int index = c - 'a';

        if (!seen[index]) {
            seen[index] = true;
            distinct_count++;
        }
    }

    if (distinct_count % 2 == 0) {
        cout << "CHAT WITH HER!\n";
    } else {
        cout << "IGNORE HIM!\n";
    }

    return 0;
}
