#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector<vector<int>> buckets(nums.size()+1);
        vector<int> result;

        for (int num : nums) count[num]++;

        for (const auto& it : count) {
            buckets[it.second].push_back(it.first);
        }

        for (int i = nums.size(); i >=1; i--) {
            for (int num : buckets[i]) {
                result.push_back(num);

                if (result.size() == k) return result;
            }
        }

        return result;
    }
};
