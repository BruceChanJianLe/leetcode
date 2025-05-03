#include "102binary_tree_level_order_traversal.hpp"

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
  std::vector<std::vector<int>> result;
};

struct BinaryTreeLevelOrderTraversalTest : public ::testing::TestWithParam<States>
{
  Solution s;
};

TEST_P(BinaryTreeLevelOrderTraversalTest, ProducesExpectedTraversal)
{
  const auto& [tree, expected] = GetParam();
  TreeNode* root = buildTree(tree);
  auto result = s.levelOrder(root);
  EXPECT_EQ(result, expected);
  freeTree(root);
}

INSTANTIATE_TEST_SUITE_P(Default, BinaryTreeLevelOrderTraversalTest,
  ::testing::Values(
    States{{3,9,20,std::nullopt,std::nullopt,15,7}, {{3},{9,20},{15,7}}},
    States{{1}, {{1}}},
    States{{}, {}},
    States{{1,2,3,4,5,6,7}, {{1},{2,3},{4,5,6,7}}},
    States{{10,std::nullopt,20,15,25}, {{10},{20},{15,25}}}
  )
);
