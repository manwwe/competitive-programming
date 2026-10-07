#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Lab {
    ll a, b, c;
    ll sum;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        ll k;
        cin >> n >> k;

        vector<Lab> labs(n);

        ll mn = LLONG_MAX;

        for (int i = 0; i < n; ++i) {
            cin >> labs[i].a >> labs[i].b >> labs[i].c;

            labs[i].sum = labs[i].a + labs[i].b + labs[i].c;

            mn = min(mn, labs[i].sum);
        }

        auto possible = [&](ll target) -> bool {
            ll operations = 0;

            for (const auto &lab : labs) {
                ll a = lab.a;
                ll b = lab.b;
                ll c = lab.c;
                ll sum = lab.sum;

                if (sum >= target)
                    continue;

                ll need = target - sum;

                // If any +1 operation already exists,
                // it can be repeated indefinitely.
                //
                // c += sgn(a - b)
                // b += sgn(a - c)
                // a += sgn(b - c)
                if (a > b || a > c || b > c) {
                    if (need > k - operations)
                        return false;

                    operations += need;
                    continue;
                }

                // At this point:
                // a <= b <= c

                // If all are equal, every operation changes
                // its instrument by 0, so we are stuck forever.
                if (a == b && b == c)
                    return false;

                /*
                    We need to create an inversion.

                    Option 1:
                    Decrease b until b < a.
                    Cost = b - a + 1.

                    Option 2:
                    Decrease c until c < b.
                    Cost = c - b + 1.

                    Take the cheaper one.

                    Each setup operation decreases the total sum
                    by 1. After setup, we can perform +1 operations
                    indefinitely.

                    If setup = d and we originally need "need"
                    extra sum:

                        d operations decrease sum by d
                        need + d operations increase sum

                    Total = need + 2*d.
                */

                ll setup = min(b - a + 1, c - b + 1);

                // Add 'need' safely.
                if (need > k - operations)
                    return false;

                operations += need;

                // Add 2 * setup safely.
                if (setup > (k - operations) / 2)
                    return false;

                operations += 2 * setup;
            }

            return true;
        };

        /*
            Initial minimum is always achievable.

            Every operation changes a laboratory's sum by
            at most +1, so the final minimum cannot exceed
            mn + k.
        */
        ll lo = mn;
        ll hi = mn + k + 1;

        while (lo + 1 < hi) {
            ll mid = lo + (hi - lo) / 2;

            if (possible(mid))
                lo = mid;
            else
                hi = mid;
        }

        cout << lo << '\n';
    }

    return 0;
}
