#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ar array


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int arr[4] = {0};

    for (char c : s) {
        if (c != '+') {
            int num = c - '0';
            arr[num]++;
        }
    }

    bool first = true;

    for (int i = 1; i <=3; i++) {
        for (int j=0; j < arr[i]; j++) {
            if (!first) cout << "+";

            cout << i;
            first = false;
        }
    }

    cout << '\n';
    return 0;
}
