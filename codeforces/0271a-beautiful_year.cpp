#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ar array


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int y;
    cin >> y;

    while (true) {
        y++;

        int freq[10] = {0};
        int year = y;
        bool valid = true;

        while (year > 0) {
            int digit = year % 10;
            freq[digit]++;

            if (freq[digit] > 1) {
                valid = false;
                break;
            }

            year /= 10;
        }

        if (valid) {
            cout << y << "\n";
            break;
        }
    }

    return 0;
}
