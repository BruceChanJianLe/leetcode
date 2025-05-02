#pragma once

#include <utility>

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
  TreeNode* invertTree(TreeNode* root) {
    // Base case
    if (!root) return root;

    std::swap(root->left, root->right);

    // Swap child nodes recursively
    invertTree(root->left);
    invertTree(root->right);

    return root;
  }
};
