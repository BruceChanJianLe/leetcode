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

class DFSSolution {
public:
  std::vector<int> rightSideView(TreeNode* root) {
    std::vector<int> result;
    walk(root, 0, result);
    return result;
  }

private:
  void walk(TreeNode* root, const int level, std::vector<int>& result) {
    if (!root) return;

    // The first node of the level (right most)
    if (level == result.size()) result.emplace_back(root->val);
    walk(root->right, 1 + level, result);
    walk(root->left, 1 + level, result);
  }
};

class SecondSolution {
public:
  std::vector<int> rightSideView(TreeNode* root) {
    // Sanity check, refer to question
    if (!root) return {};

    std::queue<TreeNode*> queuey({root});
    std::vector<int> result;

    while (!queuey.empty()) {
      auto num_of_nodes = queuey.size();

      while (num_of_nodes) {
        auto node = queuey.front();
        queuey.pop();

        if (num_of_nodes == 1) result.emplace_back(node->val);

        // This order ensure the last one is always the most right node
        if (node->left) queuey.emplace(node->left);
        if (node->right) queuey.emplace(node->right);

        --num_of_nodes;
      }
    }

    return result;
  }
};

class FirstSolution {
public:
  std::vector<int> rightSideView(TreeNode* root) {
    // Sanity check, refer to question
    if (!root) return {};

    std::queue<std::pair<TreeNode*, bool>> queuey({{root, true}});
    std::vector<int> result;

    while (!queuey.empty()) {
      auto num_of_nodes = queuey.size();

      bool first{true};
      while (num_of_nodes) {
        auto [node, add] = queuey.front();
        queuey.pop();

        if (add) result.emplace_back(node->val);

        if (node->right) {
          queuey.emplace(node->right, first);
          first = false;
        }

        if (node->left) {
          queuey.emplace(node->left, first);
          first = false;
        }

        --num_of_nodes;
      }
    }

    return result;
  }
};
