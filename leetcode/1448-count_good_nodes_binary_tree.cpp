// https://leetcode.com/problems/count-good-nodes-in-binary-tree/

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
    int dfs(TreeNode *root, int max_val) {
        if (root == nullptr)
            return 0;

        int count = 0;

        if (root->val >= max_val) {
            count = 1;
        }

        max_val = max(max_val, root->val);

        count += dfs(root->left, max_val);
        count += dfs(root->right, max_val);

        return count;
    }
    int goodNodes(TreeNode *root) { return dfs(root, root->val); }
};
