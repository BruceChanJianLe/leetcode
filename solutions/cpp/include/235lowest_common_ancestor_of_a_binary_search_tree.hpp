#pragma once

#include <algorithm>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class FirstSolution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (std::max(p->val, q->val) < root->val) {
      return lowestCommonAncestor(root->left, p, q);
    } else if (std::min(p->val, q->val) > root->val) {
      return lowestCommonAncestor(root->right, p, q);
    } else {
      return root;
    }
  }
};

class SecondSolution {
  public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      while (root) {
        if (std::max(p->val, q->val) < root->val) {
          root = root->left;
        } else if (std::min(p->val, q->val) > root->val) {
          root = root->right;
        } else {
          return root;
        }
      }
      return root;
    }
};
