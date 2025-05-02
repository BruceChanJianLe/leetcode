#pragma once

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class FirstSolution {
public:
  bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!subRoot) return true;
    if (!root) return false;

    if (root->val == subRoot->val && isSameTree(root, subRoot)) return true;

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
  }

private:
  bool isSameTree(TreeNode* root1, TreeNode* root2) {
    if (!root1 && !root2) return true;

    if (!root1 || !root2) return false;
    if (root1->val != root2->val) return false;

    return isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right);
  }
};
