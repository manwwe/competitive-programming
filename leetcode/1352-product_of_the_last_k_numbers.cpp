// https://leetcode.com/problems/product-of-the-last-k-numbers/

#include <bits/stdc++.h>
using namespace std;

class ProductOfNumbers {
    vector<long long> prefix = {1};

public:
    ProductOfNumbers() {}

    void add(int num) {
        if (num == 0)
            prefix = {1};
        else
            prefix.push_back(prefix.back() * num);
    }

    int getProduct(int k) {
        int n = prefix.size();
        if (k >= n) return 0;
        return prefix.back() / prefix[n - 1 - k];
    }
};
