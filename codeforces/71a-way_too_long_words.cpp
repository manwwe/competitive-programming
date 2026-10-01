// https://codeforces.com/problemset/problem/71/A
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;

        if (word.size() <= 10) {
            cout << word << "\n";
        } else {
            cout << word.front() << word.size() - 2 << word.back() << "\n";
        }
    }
    return 0;
}
