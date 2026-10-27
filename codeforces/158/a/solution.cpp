// https://codeforces.com/problemset/problem/158/A

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int result = 0;
    int threshold = 0;
    int score;

    for (int i = 0; i < n; i++) {
        cin >> score;
        if (i < k) {
            if (score > 0) {
                result++;
            }

            if (i == k - 1) {
                threshold = score;
            }
        } else if (score > 0 && score >= threshold) {
            result++;
        }
    }
    cout << result << "\n";
    return 0;
}
