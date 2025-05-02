#pragma once

#include <algorithm>
#include <cstdlib>
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class SecondSolution {
public:
  bool isBalanced(TreeNode* root) {
    return height(root).first;
  }

private:
  std::pair<bool, int> height(TreeNode* root) {
    // Base case
    if (!root) return {true, 0};

    auto [left_balance, left_height] = height(root->left);
    auto [right_balance, right_height] = height(root->right);

    auto balanced = left_balance && right_balance
      && std::abs(left_height - right_height) <= 1;

    return {balanced, 1 + std::max(left_height, right_height)};
  }
};

class FirstSolution {
public:
  bool isBalanced(TreeNode* root) {
    bool balanced{true};

    height(root, balanced);

    return balanced;
  }

private:
  int height(TreeNode* root, bool& balanced) {
    // Base case
    if (!root) return 0;

    auto left_height = height(root->left, balanced);
    auto right_height = height(root->right, balanced);

    balanced = balanced && std::abs(left_height - right_height) <= 1
      ? true : false;

    return 1 + std::max(left_height, right_height);
  }
};
