#pragma

#include <algorithm>
#include <cstddef>
#include <queue>
#include <stack>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Recursive Depth First Search
class RecursiveDFSSolution {
public:
  // First solution
  int maxDepth(TreeNode* root) {
    if (!root) return 0;

    return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
  }
};

// Iterative depth first search (using stack)
class IterativeDFSSolution {
public:
  int maxDepth(TreeNode* root) {
    // Sanity check
    if (!root) return 0;

    // Note that to the constructor takes a
    // std::vector<std::pair<TreeNode*, std::size_t>>
    std::stack<std::pair<TreeNode*, std::size_t>> stack({{root, 1uz}});
    int depth{0};

    while (!stack.empty()) {
      auto [node, level] = stack.top();
      stack.pop();

      if (node->left) stack.emplace(node->left, level + 1);
      if (node->right) stack.emplace(node->right, level + 1);
      depth = level > depth ? level : depth;
    }

    return depth;
  }
};

// Breath first search, the max level is the result
class BFSSolution {
public:
  int maxDepth(TreeNode* root) {
    // Sanity check
    if (!root) return 0;

    std::queue<TreeNode*> queue({root});
    int depth{0};

    while (!queue.empty()) {
      auto level_size = queue.size();

      while (level_size) {
        auto node = queue.front();
        queue.pop();

        if (node->left) queue.push(node->left);
        if (node->right) queue.push(node->right);

        --level_size;
      }

      ++depth;
    }

    return depth;
  }
};
