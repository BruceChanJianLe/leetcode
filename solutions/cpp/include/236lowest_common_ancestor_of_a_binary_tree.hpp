#pragma once

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // Base cases
    if (!root || root == p || root == q) return root;

    // Search left subtree
    auto left_tree = lowestCommonAncestor(root->left, p, q);
    // Search right subtree
    auto right_tree = lowestCommonAncestor(root->right, p, q);

    // Found on left and right (root is lowest common ancestor)
    if (left_tree && right_tree) return root; 

    return left_tree ? left_tree : right_tree;
  }
};
