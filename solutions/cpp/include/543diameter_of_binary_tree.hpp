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
  int diameterOfBinaryTree(TreeNode* root) {
    int diameter{0};
    height(root, diameter);
    return diameter;
  }

private:
  int height(TreeNode* root, int& diameter) {
    // Base case
    if (!root) return 0;

    auto left_height = height(root->left, diameter);
    auto right_height = height(root->right, diameter);

    diameter = std::max(diameter, left_height + right_height);

    return 1 + std::max(left_height, right_height);
  }
};
