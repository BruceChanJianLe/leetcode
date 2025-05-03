#pragma once

#include <queue>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Iterative solution
class Solution {
public:
  std::vector<std::vector<int>> levelOrder(TreeNode* root) {
    if (!root) return {};

    std::queue<TreeNode*> queuey({root});
    std::vector<std::vector<int>> result;

    while(!queuey.empty()) {
      auto node_nums = queuey.size();

      std::vector<int> curr;
      while (node_nums) {
        auto node = queuey.front();
        queuey.pop();

        curr.emplace_back(node->val);

        if (node->left) queuey.emplace(node->left);
        if (node->right) queuey.emplace(node->right);

        --node_nums;
      }

      result.emplace_back(curr);
    }

    return result;
  }
};
