// https://codeforces.com/problemset/problem/231/A

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int solved = 0;
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;

    if (a + b + c >= 2) {
      solved++;
    }
  }
  cout << solved;
  return 0;
}
