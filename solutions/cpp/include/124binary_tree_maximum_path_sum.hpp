#pragma once

#include <algorithm>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  int maxPathSum(TreeNode* root) {
    // init with root-val
    auto max_seen{root->val};

    dfsWalk(root, max_seen);

    return max_seen;
  }

private:
  int dfsWalk(TreeNode* root, int& max_seen) {
    // Base case
    if (!root) return 0;

    auto left_max = std::max(dfsWalk(root->left, max_seen), 0);
    auto right_max = std::max(dfsWalk(root->right, max_seen), 0);

    // Update max_seen value
    max_seen = std::max(max_seen, left_max + right_max + root->val);

    // return the max path taken
    return std::max(left_max, right_max) + root->val;
  }
};
