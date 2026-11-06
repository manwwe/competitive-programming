// https://leetcode.com/problems/count-zero-request-servers/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });

        int m = queries.size();
        vector<pair<int, int>> sorted_queries;
        for (int i = 0; i < m; i++)
            sorted_queries.push_back({queries[i], i});

        sort(sorted_queries.begin(), sorted_queries.end());

        vector<int> count(n + 1, 0), res(m);
        int left = 0, right = 0, active_servers = 0;

        for (auto [time, idx] : sorted_queries) {
            while (right < logs.size() && logs[right][1] <= time) {
                int server_id = logs[right][0];
                if (++count[server_id] == 1) active_servers++;
                right++;
            }

            while (left < right && logs[left][1] < time - x) {
                int server_id = logs[left][0];
                if (--count[server_id] == 0) active_servers--;
                left++;
            }

            res[idx] = n - active_servers;
        }

        return res;
    }
};
