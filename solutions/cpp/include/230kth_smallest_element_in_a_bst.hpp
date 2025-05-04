#pragma once

#include <stack>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Recursive DFS (optimal)
// Time complexity: O(H + k) where H is the height of the tree.
// Space complexity: O(H) for the recursion stack.
class OptimalRDSFSolution {
public:
  int kthSmallest(TreeNode* root, int k) {
    // k, result
    std::pair<int, int> store{k, 0};
    inOrderWalk(root, store);
    return store.second;
  }

private:
  void inOrderWalk(TreeNode* root, std::pair<int, int>& store) {
    if (!root) return;

    inOrderWalk(root->left, store);
    --store.first;
    if (store.first == 0) {
      store.second = root->val;
    }
    inOrderWalk(root->right, store);
  }
};

// Recursive DFS
// Time complexity: O(n) n - number of nodes
// Space complexity: O(n) n - number of nodes
class RDSFSolution {
public:
  int kthSmallest(TreeNode* root, int k) {
    std::vector<int> ranges;
    inOrderWalk(root, ranges);
    return ranges[k - 1];
  }

private:
  void inOrderWalk(TreeNode* root, std::vector<int>& ranges) {
    if (!root) return;

    inOrderWalk(root->left, ranges);
    ranges.emplace_back(root->val);
    inOrderWalk(root->right, ranges);
  }
};

// Iterative DFS
// Time complexity: O(H + k) where H is the height of the tree.
// Space complexity: O(H) for the recursion stack.
class IDSFSolution {
public:
  int kthSmallest(TreeNode* root, int k) {
    std::stack<TreeNode*> stacky;
    int count{0};

    while (root || !stacky.empty()) {
      while (root) {
        stacky.emplace(root);
        root = root->left;
      }

      root = stacky.top();
      stacky.pop();
      ++count;

      if (count == k) return root->val;

      root = root->right;
    }
    return -1;
  }
};
