// https://codeforces.com/problemset/problem/339/A

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
vector<int> vi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int left = 0;
    int current = 0;
    int right = s.size() - 1;

    while (current <= right) {
        if (s[current] == '1') {
            swap(s[left], s[current]);
            left += 2;
            current += 2;
        } else if (s[current] == '2') {
            current += 2;
        } else {
            swap(s[current], s[right]);
            right -= 2;
        }
    }
    cout << s << "\n";
    return 0;
}
