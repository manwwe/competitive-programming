#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ar array


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    int l, r;
    cin >> l >> r;
    int sum = 0;

    for (; l <=r; l++) sum += arr[l];

    cout << sum;

    return 0;
}
