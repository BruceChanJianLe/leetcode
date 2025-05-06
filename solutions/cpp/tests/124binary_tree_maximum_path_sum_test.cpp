#include "124binary_tree_maximum_path_sum.hpp"

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
  int result;
};

struct BinaryTreeMaxPathSumTest : public ::testing::TestWithParam<States>
{
  Solution s;
};

TEST_P(BinaryTreeMaxPathSumTest, ReturnsCorrectSum)
{
  const auto& as = GetParam();
  TreeNode* root = buildTree(as.tree);
  EXPECT_EQ(s.maxPathSum(root), as.result);
  freeTree(root);
}

INSTANTIATE_TEST_SUITE_P(Default,
    BinaryTreeMaxPathSumTest,
    ::testing::Values(
      States{
        {1, 2, 3}, 6
      },
      States{
        {-10, 9, 20, std::nullopt, std::nullopt, 15, 7}, 42
      },
      States{
        {2, -1}, 2
      },
      States{
        {-3}, -3
      },
      States{
        {-10, 9, 20, -5, std::nullopt, 15, 7}, 42
      },
      States{
        {1, -2, 3}, 4
      },
      States{
        {1, -2, -3, 1, 3, -2, std::nullopt, -1}, 3
      }
      )
    );
