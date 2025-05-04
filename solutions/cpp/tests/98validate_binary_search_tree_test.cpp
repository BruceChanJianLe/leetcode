#include "98validate_binary_search_tree.hpp"

#include <gtest/gtest.h>

#include <optional>
#include <queue>

// Helper: Build tree from level-order vector (using `std::optional`)
TreeNode* buildTree(const std::vector<std::optional<int>>& data) {
  if (data.empty() || !data.front()) return nullptr;

  TreeNode* root = new TreeNode(*data.front());
  std::queue<TreeNode*> q;
  q.push(root);
  std::size_t i = 1;

  while (i < data.size()) {
    TreeNode* curr = q.front(); q.pop();
    if (i < data.size() && data[i]) {
      curr->left = new TreeNode(*data[i]);
      q.push(curr->left);
    }
    ++i;
    if (i < data.size() && data[i]) {
      curr->right = new TreeNode(*data[i]);
      q.push(curr->right);
    }
    ++i;
  }

  return root;
}

// Cleanup utility
void freeTree(TreeNode* root) {
  if (!root) return;
  freeTree(root->left);
  freeTree(root->right);
  delete root;
}

struct States
{
  std::vector<std::optional<int>> tree;
  bool result;
};

struct ValidateBSTreeTest : public ::testing::TestWithParam<States>
{
  DFSSolution ds;
  InOrderTraversalSolution is;
  OptInOrderTraversalSolution ois;
};

TEST_P(ValidateBSTreeTest, OptInOrderTraversalValidateBSTreeCase) {
  const auto& as = GetParam();
  TreeNode* root = buildTree(as.tree);
  EXPECT_EQ(ois.isValidBST(root), as.result);
  free(root);
}

TEST_P(ValidateBSTreeTest, InOrderTraversalValidateBSTreeCase) {
  const auto& as = GetParam();
  TreeNode* root = buildTree(as.tree);
  EXPECT_EQ(is.isValidBST(root), as.result);
  free(root);
}

TEST_P(ValidateBSTreeTest, ValidateBSTreeCase) {
  const auto& as = GetParam();
  TreeNode* root = buildTree(as.tree);
  EXPECT_EQ(ds.isValidBST(root), as.result);
  free(root);
}

INSTANTIATE_TEST_SUITE_P(Default, ValidateBSTreeTest,
  ::testing::Values(
    States{{2, 1, 3}, true},
    States{{5, 1, 4, std::nullopt, std::nullopt, 3, 6}, false},
    States{{1, 1}, false}, // Duplicate value
    States{{5,4,6,std::nullopt,std::nullopt,3,7}, false},
    States{{10, 5, 15, std::nullopt, std::nullopt, 6, 20}, false}, // Invalid right child
    States{{2147483647}, true}, // Single node with max int
    States{{0, std::nullopt, -1}, false}, // Invalid right child smaller than root
    States{{1, std::nullopt, 2, std::nullopt, 3, std::nullopt, 4}, true} // Right-skewed valid BST
  )
);
