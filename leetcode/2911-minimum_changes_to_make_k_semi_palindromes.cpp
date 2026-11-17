// https://leetcode.com/problems/minimum-changes-to-make-k-semi-palindromes/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        vector<vector<int>> divs(n + 1);
        for (int d = 1; d <= n; d++)
            for (int len = 2 * d; len <= n; len += d)
                divs[len].push_back(d);

        vector<vector<int>> cost(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int len = j - i + 1;
                for (int d : divs[len]) {
                    int groups = len / d, changes = 0;
                    for (int r = 0; r < d; r++)
                        for (int a = 0, b = groups - 1; a < b; a++, b--)
                            changes += s[i + r + a * d] != s[i + r + b * d];
                    cost[i][j] = min(cost[i][j], changes);
                }
            }
        }

        vector<vector<int>> dp(k + 1, vector<int>(n + 1, INF));
        dp[0][0] = 0;
        for (int p = 1; p <= k; p++)
            for (int j = 2 * p; j <= n; j++)
                for (int i = 2 * (p - 1); i + 2 <= j; i++)
                    if (dp[p - 1][i] < INF)
                        dp[p][j] = min(dp[p][j], dp[p - 1][i] + cost[i][j - 1]);

        return dp[k][n];
    }
};
