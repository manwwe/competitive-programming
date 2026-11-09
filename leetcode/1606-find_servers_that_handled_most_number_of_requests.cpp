// https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available;
        for (int i = 0; i < k; i++) available.insert(i);

        priority_queue<pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>> busy;

        vector<int> count(k);
        int max_requests = 0;

        for (int i = 0; i < arrival.size(); i++) {
            while (!busy.empty() && busy.top().first <= arrival[i]) {
                available.insert(busy.top().second);
                busy.pop();
            }

            if (available.empty()) continue;

            auto it = available.lower_bound(i % k);
            if (it == available.end()) it = available.begin();

            int server_id = *it;
            available.erase(it);

            max_requests = max(max_requests, ++count[server_id]);
            busy.push({(long long)arrival[i] + load[i], server_id});
        }

        vector<int> res;
        for (int i = 0; i < k; i++) {
            if (count[i] == max_requests) res.push_back(i);
        }
        return res;
    }
};
