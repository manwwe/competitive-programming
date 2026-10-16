// https://leetcode.com/problems/path-sum-iii/

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
    int count_paths(TreeNode *root, long long targetSum) {
        if (root == nullptr)
            return 0;

        int count = 0;

        if (root->val == targetSum) {
            count++;
        }

        count += count_paths(root->left, targetSum - root->val);
        count += count_paths(root->right, targetSum - root->val);

        return count;
    }
    int pathSum(TreeNode *root, int targetSum) {
        if (root == nullptr)
            return 0;

        int count = count_paths(root, targetSum);

        count += pathSum(root->left, targetSum);
        count += pathSum(root->right, targetSum);

        return count;
    }
};
