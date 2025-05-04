#pragma once

#include <limits>
#include <ranges>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Recursive in order traversal (optimize)
class OptInOrderTraversalSolution {
public:
  bool isValidBST(TreeNode* root) {
    TreeNode* prev{nullptr};
    return inOrderTraversalWalk(root, prev);
  }

private:
  bool inOrderTraversalWalk(TreeNode* root, TreeNode*& prev) {
    if (!root) return true;

    // Check left subtree
    if (!inOrderTraversalWalk(root->left, prev)) return false;

    if (prev && prev->val >= root->val) return false;

    prev = root;

    // Check right subtree
    return inOrderTraversalWalk(root->right, prev);

  }
};

// Recursive in order traversal (extra space)
class InOrderTraversalSolution {
public:
  bool isValidBST(TreeNode* root) {
    std::vector<int> range;
    inOrderTraversalWalk(root, range);

    for (const auto& window : std::ranges::slide_view(range, 2)) {
      if (window.front() >= window.back()) return false;
    }

    return true;
  }

private:
  void inOrderTraversalWalk(TreeNode* root, std::vector<int>& range) {
    if (!root) return;

    inOrderTraversalWalk(root->left, range);
    range.emplace_back(root->val);
    inOrderTraversalWalk(root->right, range);
  }
};

// Recursive DFS range checking
class DFSSolution {
public:
  bool isValidBST(TreeNode* root) {
    return dfsWalk(root,
        std::numeric_limits<long>::min(), std::numeric_limits<long>::max());
  }

private:
  bool dfsWalk(TreeNode* root, long left_bound, long right_bound) {
    if (!root) return true;

    return (left_bound < root->val && root->val < right_bound)
      && dfsWalk(root->left, left_bound, root->val)
      && dfsWalk(root->right, root->val, right_bound);
  }
};
