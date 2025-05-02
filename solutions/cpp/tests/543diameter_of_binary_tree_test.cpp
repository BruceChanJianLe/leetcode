#include "543diameter_of_binary_tree.hpp"

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

struct States
{
  std::vector<std::optional<int>> input;
  int result;
};

struct DiameterOfBinaryTreeTest : public ::testing::TestWithParam<States>
{
  Solution s;
};

TEST_P(DiameterOfBinaryTreeTest, ComputesCorrectDiameter) {
  auto as = GetParam();
  TreeNode* root = buildTree(as.input);
  auto result = s.diameterOfBinaryTree(root);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(Default, DiameterOfBinaryTreeTest,
  ::testing::Values(
    States{{1, 2, 3, 4, 5}, 3},          // [4,2,1,3] or [5,2,1,3]
    States{{1, 2}, 1},                   // [2,1]
    States{{1}, 0},                      // Single node
    States{{1, 2, std::nullopt, 3}, 2},       // Left skewed
    States{{1, std::nullopt, 2, std::nullopt, 3}, 2} // Right skewed
  )
);

