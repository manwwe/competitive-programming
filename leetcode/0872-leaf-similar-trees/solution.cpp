// https://leetcode.com/problems/leaf-similar-trees/

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
    void dfs(TreeNode *root, vector<int> &sequence) {
        if (root == nullptr)
            return;

        if (root->left == nullptr && root->right == nullptr) {
            sequence.push_back(root->val);
            return;
        }

        dfs(root->left, sequence);
        dfs(root->right, sequence);
    }

    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        vector<int> seq1;
        vector<int> seq2;

        dfs(root1, seq1);
        dfs(root2, seq2);

        return seq1 == seq2;
    }
};
