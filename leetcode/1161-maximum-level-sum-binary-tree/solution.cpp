// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

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
    int maxLevelSum(TreeNode *root) {
        queue<TreeNode *> q;
        q.push(root);

        int level = 0, best_level = 0;
        int max_sum = INT_MIN;

        while (!q.empty()) {
            int n = q.size();
            int curr_sum = 0;
            level++;

            for (int i = 0; i < n; i++) {
                TreeNode *curr_node = q.front();
                q.pop();

                curr_sum += curr_node->val;

                if (curr_node->left)
                    q.push(curr_node->left);
                if (curr_node->right)
                    q.push(curr_node->right);
            }

            if (curr_sum > max_sum) {
                max_sum = curr_sum;
                best_level = level;
            }
        }

        return best_level;
    }
};
