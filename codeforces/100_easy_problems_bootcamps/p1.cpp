#include <bits/stdc++.h>
#include <vector>

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
    for (int i = n -1; i >= 0; i--) cout << arr[i] << ' ';
    cout << "\n";


    return 0;
}
