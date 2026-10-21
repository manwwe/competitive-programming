// https://leetcode.com/problems/smallest-number-in-infinite-set/

#include <bits/stdc++.h>
using namespace std;

class SmallestInfiniteSet {
    int curr_num = 1;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    unordered_set<int> added;

public:
    SmallestInfiniteSet() {}

    int popSmallest() {
        if (!min_heap.empty()) {
            int num = min_heap.top();
            min_heap.pop();
            added.erase(num);
            return num;
        }
        return curr_num++;
    }

    void addBack(int num) {
        if (num >= curr_num || added.count(num)) return;
        min_heap.push(num);
        added.insert(num);
    }
};


/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
