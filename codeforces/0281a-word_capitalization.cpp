// https://codeforces.com/problemset/problem/281/A

#include <bits/stdc++.h>
#include <cctype>

using namespace std;

typedef long long ll;
vector<int> vi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string word;
    cin >> word;

    word[0] = (char)toupper(word[0]);
    cout << word << "\n";
    return 0;
}
