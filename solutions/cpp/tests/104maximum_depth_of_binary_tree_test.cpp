#include "104maximum_depth_of_binary_tree.hpp"

#include <gtest/gtest.h>
#include <optional>

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

struct States
{
  std::vector<std::optional<int>> input;
  int result;
};

struct MaximumDepthOfBinaryTreeTest : public ::testing::TestWithParam<States>
{
  RecursiveDFSSolution rs;
  IterativeDFSSolution is;
  BFSSolution bs;
};

TEST_P(MaximumDepthOfBinaryTreeTest, RecursiveDFSSolution) {
  auto as = GetParam();
  TreeNode* root = buildTree(as.input);
  auto result = rs.maxDepth(root);
  EXPECT_EQ(result, as.result);
}

TEST_P(MaximumDepthOfBinaryTreeTest, IterativeDFSSolution) {
  auto as = GetParam();
  TreeNode* root = buildTree(as.input);
  auto result = is.maxDepth(root);
  EXPECT_EQ(result, as.result);
}

TEST_P(MaximumDepthOfBinaryTreeTest, BFSSolution) {
  auto as = GetParam();
  TreeNode* root = buildTree(as.input);
  auto result = bs.maxDepth(root);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(Default, MaximumDepthOfBinaryTreeTest,
  ::testing::Values(
    States{{3, 9, 20, std::nullopt, std::nullopt, 15, 7}, 3},
    States{{1, std::nullopt, 2}, 2},
    States{{}, 0},
    States{{0}, 1},
    States{{1, 2, std::nullopt, 3, std::nullopt, 4}, 4}  // Left-skewed tree
  )
);
