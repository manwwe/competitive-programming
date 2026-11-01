#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ar array


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll A;
    cin >> A;

    ll a = sqrt(A);

    while (A % a != 0) a--;

    ll b = A / a;

    cout << 2 * (a + b) << "\n";

    return 0;
}
