// https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/

#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
  public:
    int result = 0;

    void dfs(TreeNode *root, int left, int right) {
        if (root == nullptr)
            return;

        result = max(result, max(left, right));

        dfs(root->left, right + 1, 0);
        dfs(root->right, 0, left + 1);
    }

    int longestZigZag(TreeNode *root) {
        dfs(root, 0, 0);
        return result;
    }
};
