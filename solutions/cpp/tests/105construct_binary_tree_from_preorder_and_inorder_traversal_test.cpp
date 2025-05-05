#include "105construct_binary_tree_from_preorder_and_inorder_traversal.hpp"

#include <gtest/gtest.h>

#include <vector>
#include <optional>
#include <queue>

// --- Helper to convert a tree to level-order vector for testing ---
std::vector<std::optional<int>> treeToVector(TreeNode* root) {
  std::vector<std::optional<int>> result;
  std::queue<TreeNode*> q;
  if (root) q.push(root);
  while (!q.empty()) {
    TreeNode* node = q.front(); q.pop();
    if (node) {
      result.push_back(node->val);
      q.push(node->left);
      q.push(node->right);
    } else {
      result.push_back(std::nullopt);
    }
  }
  // Trim trailing nulls
  while (!result.empty() && !result.back()) result.pop_back();
  return result;
}

// Cleanup utility
void freeTree(TreeNode* root) {
  if (!root) return;
  freeTree(root->left);
  freeTree(root->right);
  delete root;
}

struct States {
  std::vector<int> preorder;
  std::vector<int> inorder;
  std::vector<std::optional<int>> result;
};

struct ConstructBinaryTreeFromPreAndInTraversalTest
  : public ::testing::TestWithParam<States>
{
  Solution s;
};

TEST_P(ConstructBinaryTreeFromPreAndInTraversalTest, ConstructsCorrectTree)
{
  auto as = GetParam();
  TreeNode* root = s.buildTree(as.preorder, as.inorder);
  std::vector<std::optional<int>> actual = treeToVector(root);
  EXPECT_EQ(actual, as.result);
  freeTree(root);
}

INSTANTIATE_TEST_SUITE_P(
  Default, ConstructBinaryTreeFromPreAndInTraversalTest,
  ::testing::Values(
    States{
      {3, 9, 20, 15, 7},
      {9, 3, 15, 20, 7},
      {3, 9, 20, std::nullopt, std::nullopt, 15, 7}
    },
    States{
      {-1},
      {-1},
      {-1}
    },
    States{
      {1, 2, 3},
      {3, 2, 1},
      {1, 2, std::nullopt, 3}
    },
    States{
      {1, 2},
      {2, 1},
      {1, 2}
    }
  )
);
