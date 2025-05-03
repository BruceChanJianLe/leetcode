#pragma once

#include <limits>
#include <queue>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Recursive DFS 2
class DFSSolution2 {
public:
  int goodNodes(TreeNode* root) {
    return dfsWalk(root, std::numeric_limits<int>::min());
  }

private:
  int dfsWalk(TreeNode* root, int max_seen) {
    if (!root) return 0;

    auto count = root->val >= max_seen ? 1 : 0;
    max_seen = std::max(max_seen, root->val);

    count += dfsWalk(root->left, max_seen);
    count += dfsWalk(root->right, max_seen);

    return count;
  }
};

// Recursive DFS 1
class DFSSolution1 {
public:
  int goodNodes(TreeNode* root) {
    return dfsWalk(root, std::numeric_limits<int>::min());
  }

private:
  int dfsWalk(TreeNode* root, const int max_seen) {
    if (!root) return 0;

    return ((root->val >= max_seen) ? 1 : 0 )
      + dfsWalk(root->left, std::max(root->val, max_seen))
      + dfsWalk(root->right, std::max(root->val, max_seen));
  }
};

// Iterative BFS
class BFSSolution {
public:
  int goodNodes(TreeNode* root) {
    int result{0};
    std::queue<std::pair<TreeNode*, int>>
      queuey({{root, std::numeric_limits<int>::min()}});

    while (!queuey.empty()) {
      auto [node, root_val] = queuey.front();
      queuey.pop();

      if (node->val >= root_val) ++result;

      auto max_seen{std::max(node->val, root_val)};
      if (node->left) queuey.emplace(node->left, max_seen);
      if (node->right) queuey.emplace(node->right, max_seen);
    }

    return result;
  }
};
